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
#ifndef UBX_8_NMEA_LATITUDE_H_
#define UBX_8_NMEA_LATITUDE_H_

#include <cstdint>

namespace ubx {
namespace _8 {
namespace nmea {
/// @brief Latitude as defined in wgs84.
struct Latitude {
  std::uint32_t degrees;
  float minutes;
};
}
}
}

#endif  // UBX_8_NMEA_LATITUDE_H_
