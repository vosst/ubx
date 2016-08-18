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
