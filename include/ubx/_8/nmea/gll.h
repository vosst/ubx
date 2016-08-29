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
#ifndef UBX_8_NMEA_GLL_H_
#define UBX_8_NMEA_GLL_H_

#include <ubx/_8/nmea/cardinal_direction.h>
#include <ubx/_8/nmea/latitude.h>
#include <ubx/_8/nmea/longitude.h>
#include <ubx/_8/nmea/mode.h>
#include <ubx/_8/nmea/status.h>
#include <ubx/_8/nmea/talker.h>
#include <ubx/_8/nmea/utc.h>

#include <boost/optional.hpp>

namespace ubx
{
namespace _8
{
namespace nmea
{
struct Gll
{
    Talker talker;
    boost::optional<Latitude> latitude;
    boost::optional<CardinalDirection> latitude_direction;
    boost::optional<Longitude> longitude;
    boost::optional<CardinalDirection> longitude_direction;
    boost::optional<Utc> utc;
    boost::optional<Status> status;
    boost::optional<Mode> mode;
};
}
}
}

#endif // UBX_8_NMEA_GLL_H_
