#ifndef UBX_8_NMEA_GGA_H_
#define UBX_8_NMEA_GGA_H_

#include <ubx/dop.h>

#include <ubx/_8/nmea/cardinal_direction.h>
#include <ubx/_8/nmea/latitude.h>
#include <ubx/_8/nmea/longitude.h>
#include <ubx/_8/nmea/talker.h>
#include <ubx/_8/nmea/utc.h>

#include <ubx/_8/nmea/gps/fix_mode.h>

#include <boost/optional.hpp>

#include <cstdint>

namespace ubx
{
namespace _8
{
namespace nmea
{
struct Gga
{
    Talker talker;
    boost::optional<Utc> utc;
    boost::optional<Latitude> latitude;
    boost::optional<CardinalDirection> latitude_direction;
    boost::optional<Longitude> longitude;
    boost::optional<CardinalDirection> longitude_direction;
    boost::optional<gps::FixMode> fix_mode;
    boost::optional<std::uint8_t> satellites_in_use;
    boost::optional<Dop<tag::Horizontal>> hdop;
    boost::optional<float> altitude;
    boost::optional<float> geoidal_separation;
    boost::optional<float> age; // [s]
    boost::optional<std::uint16_t> differential_reference_station;
};
}
}
}

#endif // UBX_8_NMEA_GGA_H_
