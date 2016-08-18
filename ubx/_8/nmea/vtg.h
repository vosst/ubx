#ifndef UBX_8_NMEA_VTG_H_
#define UBX_8_NMEA_VTG_H_

#include <ubx/_8/nmea/mode.h>
#include <ubx/_8/nmea/talker.h>

#include <boost/optional.hpp>

#include <cstdint>

namespace ubx
{
namespace _8
{
namespace nmea
{
struct Vtg
{
    Talker talker;
    boost::optional<float> cog_true;
    boost::optional<float> cog_magnetic;
    boost::optional<float> sog_knots;
    boost::optional<float> sog_kmh;
    boost::optional<Mode> mode;
};
}
}
}

#endif // UBX_8_NMEA_VTG_H_
