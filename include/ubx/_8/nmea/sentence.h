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
#ifndef UBX_8_NMEA_SENTENCE_H_
#define UBX_8_NMEA_SENTENCE_H_

#include <ubx/_8/nmea/gga.h>
#include <ubx/_8/nmea/gll.h>
#include <ubx/_8/nmea/gsa.h>
#include <ubx/_8/nmea/gsv.h>
#include <ubx/_8/nmea/rmc.h>
#include <ubx/_8/nmea/txt.h>
#include <ubx/_8/nmea/vtg.h>

#include <boost/variant.hpp>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief All known nmea sentences should go here.
///
/// NOTE: Expand at the end.
typedef boost::variant<
    Gga,
    Gsa,
    Gll,
    Gsv,
    Rmc,
    Txt,
    Vtg
> Sentence;
}
}
}

#endif // UBX_8_NMEA_SENTENCE_H_

