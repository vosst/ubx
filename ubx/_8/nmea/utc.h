#ifndef UBX_8_NMEA_UTC_H_
#define UBX_8_NMEA_UTC_H_

#include <cstdint>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Time in UTC.
struct Utc
{
    std::uint8_t hours;
    std::uint8_t minutes;
    float seconds;
};
}
}
}

#endif // UBX_8_NMEA_UTC_H_
