#ifndef UBX_8_NMEA_LONGITUDE_H_
#define UBX_8_NMEA_LONGITUDE_H_

#include <cstdint>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Longitude as defined in wgs84.
struct Longitude
{
    std::uint32_t degrees;
    float minutes;
};
}
}
}

#endif // UBX_8_NMEA_LONGITUDE_H_
