// Copyright (C) 2016 Thomas Voss <thomas.voss.bochum@gmail.com>
//
// This library is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <ubx/_8/replaying_receiver.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "config.h"

namespace {
struct MockMonitor : public ubx::_8::Receiver::Monitor {
  MOCK_METHOD2(on_new_chunk, void(ubx::_8::Receiver::Buffer::iterator, ubx::_8::Receiver::Buffer::iterator));
  MOCK_METHOD1(on_new_nmea_sentence, void(const ubx::_8::nmea::Sentence&));
};
}

TEST(Receiver, handles_precorded_traces_correctly) {
  using namespace ::testing;

  auto monitor = std::make_shared<NiceMock<MockMonitor>>();
  EXPECT_CALL(*monitor, on_new_nmea_sentence(_)).Times(AtLeast(1));
  auto receiver = ubx::_8::ReplayingReceiver::create(testing::trace_dir() / "trace.nmea", monitor);

  EXPECT_NO_THROW(receiver->run());
}
