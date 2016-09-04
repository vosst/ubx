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
#ifndef UBX_8_REPLAYING_RECEIVER_H_
#define UBX_8_REPLAYING_RECEIVER_H_

#include <ubx/_8/receiver.h>

#include <boost/filesystem.hpp>

#include <array>
#include <fstream>

namespace ubx {
namespace _8 {

/// @brief Replaying replays a pre-recorded nmea trace.
class ReplayingReceiver : public Receiver, public std::enable_shared_from_this<ReplayingReceiver> {
 public:
  /// @brief create returns a new Receiver instance replaying the nmea trace in
  /// trace.
  static std::shared_ptr<ReplayingReceiver> create(const boost::filesystem::path& trace,
                                                   const std::shared_ptr<Receiver::Monitor>& monitor);

  // From Receiver
  void run();

 private:
  /// @brief create returns a new Receiver instance replaying the nmea trace in
  /// trace.
  ///
  /// Throws in case of issues.
  ReplayingReceiver(const boost::filesystem::path& trace, const std::shared_ptr<Receiver::Monitor>& monitor);

  Receiver::Buffer buffer;
  std::ifstream in;
};
}
}

#endif  // UBX_8_REPLAYING_RECEIVER_H_
