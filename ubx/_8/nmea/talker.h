#ifndef UBX_8_NMEA_TALKER_H_
#define UBX_8_NMEA_TALKER_H_

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Talker enumerates well-known participants on an NMEA bus.
enum class Talker
{
    gl, ///< GLONASS receiver
    gn, ///< Global Navigation Satellite System (GNSS)
    gp  ///< Global Positioning System (GPS)
};
}
}
}

#endif // UBX_8_NMEA_TALKER_H_
