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
#ifndef UBX_8_NMEA_GSA_H_
#define UBX_8_NMEA_GSA_H_

#include <ubx/dop.h>

#include <ubx/_8/nmea/latitude.h>
#include <ubx/_8/nmea/longitude.h>
#include <ubx/_8/nmea/talker.h>

#include <ubx/_8/nmea/gps/fix_mode.h>

#include <boost/optional.hpp>

#include <cstdint>
#include <vector>

namespace ubx
{
namespace _8
{
namespace nmea
{
struct Gsa
{
    enum class OperationMode
    {
        manual = 'M',   ///< Manual, forced to operate in 2D or 3D mode.
        automatic = 'A' ///< Automatic, allowed to switch between 2D and 3D.
    };

    enum FixMode
    {
        fix_not_available = 1, ///< Fix not available
        fix_in_2d = 2,         ///< 2d fix
        fix_in_3d = 3,         ///< 3d fix
    };

    Talker talker;
    boost::optional<OperationMode> operation_mode;
    boost::optional<FixMode> fix_mode;
    boost::optional<std::vector<boost::optional<std::uint8_t>>> satellite_ids;
    boost::optional<Dop<tag::Positional>> pdop;
    boost::optional<Dop<tag::Horizontal>> hdop;
    boost::optional<Dop<tag::Vertical>> vdop;
};
}
}
}

#endif // UBX_8_NMEA_GSA_H_
