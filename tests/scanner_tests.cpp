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

#include <ubx/_8/nmea/scanner.h>

#include <gtest/gtest.h>

TEST(NmeaScanner, ctor_and_dtor_work) {
  ubx::_8::nmea::Scanner scanner;
}

TEST(NmeaScanner, initial_state_is_wait_for_dollar) {
  ubx::_8::nmea::Scanner scanner;
  EXPECT_EQ(ubx::_8::nmea::Scanner::Expect::dollar, scanner.update('*'));
}

TEST(NmeaScanner, throws_if_finalized_for_incomplete_data) {
  EXPECT_ANY_THROW(ubx::_8::nmea::Scanner scanner; scanner.finalize(););
  EXPECT_ANY_THROW(ubx::_8::nmea::Scanner scanner; scanner.update('$');
                   scanner.finalize(););
  EXPECT_ANY_THROW(ubx::_8::nmea::Scanner scanner; scanner.update('$');
                   scanner.update('1'); scanner.finalize(););
  EXPECT_ANY_THROW(ubx::_8::nmea::Scanner scanner; scanner.update('$');
                   scanner.update('\r'); scanner.finalize(););
}

TEST(NmeaScanner, returns_accumulated_data_when_finalized) {
  ubx::_8::nmea::Scanner scanner;
  scanner.update('$');
  scanner.update('1');
  scanner.update('2');
  scanner.update('3');
  scanner.update('4');
  scanner.update('5');
  scanner.update('6');
  scanner.update('\r');
  scanner.update('\n');

  EXPECT_EQ("$123456\r\n", scanner.finalize());
}
