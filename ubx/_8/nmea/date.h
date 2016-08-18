#ifndef UBX_8_NMEA_DATE_H_
#define UBX_8_NMEA_DATE_H_

#include <cstdint>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Date models a specific calendar day (Gregorian calendar).
struct Date
{
    std::uint8_t day;
    std::uint8_t month;
    std::uint8_t year;
};
}
}
}

#endif // UBX_8_NMEA_DATE_H_
