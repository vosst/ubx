#ifndef UBX_8_NMEA_GPS_FIX_MODE_H_
#define UBX_8_NMEA_GPS_FIX_MODE_H_

namespace ubx
{
namespace _8
{
namespace nmea
{
namespace gps
{
/// @brief FixMode enumerates all known, gps-specific fix modes.
enum class FixMode
{
    invalid = 0,
    gps_sps = 1,
    differential_gps_sps = 2,
    gps_pps = 3,
    real_time_kinematic = 4,
    floating_point_real_time_kinematic = 5,
    estimated = 6,
    manual_input = 7,
    simulator = 8            
};
}
}
}
}

#endif // UBX_8_NMEA_GPS_FIX_MODE_H_
