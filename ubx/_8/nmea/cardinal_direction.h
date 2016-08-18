#ifndef UBX_8_NMEA_CARDINAL_DIRECTION_H_
#define UBX_8_NMEA_CARDINAL_DIRECTION_H_

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief CardinalDirection enumerates the main cardinal direction
/// available in NMEA sentences.
enum class CardinalDirection
{
    north = 'N',
    south = 'S',
    east  = 'E',
    west  = 'W'
};
}
}
}

#endif // UBX_8_NMEA_CARDINAL_DIRECTION_H_
