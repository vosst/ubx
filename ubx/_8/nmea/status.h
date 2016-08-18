#ifndef UBX_8_NMEA_STATUS_H_
#define UBX_8_NMEA_STATUS_H_

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Status enumerates all status codes known to NMEA messages.
enum class Status
{
    valid     = 'A', ///< The referenced data is valid.
    not_valid = 'V'  ///< The reference data is missing and thus not valid.
};
}
}
}

#endif // UBX_8_NMEA_STATUS_H_
