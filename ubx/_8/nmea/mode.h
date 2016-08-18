#ifndef UBX_8_NMEA_MODE_H_
#define UBX_8_NMEA_MODE_H_

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Mode enumerates all known NMEA positioning modes.
enum class Mode
{
    autonomous     = 'A',
    differential   = 'D',
    estimated      = 'E',
    manual_input   = 'M',
    simulator_mode = 'S',
    data_not_valid = 'N'
};
}
}
}

#endif // UBX_8_NMEA_MODE_H_
