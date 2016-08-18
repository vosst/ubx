#ifndef UBX_8_NMEA_LATITUDE_H_
#define UBX_8_NMEA_LATITUDE_H_

#include <cstdint>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Latitude as defined in wgs84.
struct Latitude
{
    std::uint32_t degrees;
    float minutes;
};
}
}
}

#endif // UBX_8_NMEA_LATITUDE_H_
