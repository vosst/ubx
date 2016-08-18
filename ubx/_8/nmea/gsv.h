#ifndef UBX_8_NMEA_GSV_H_
#define UBX_8_NMEA_GSV_H_

#include <ubx/_8/nmea/talker.h>

#include <boost/optional.hpp>

#include <cstdint>

#include <vector>

namespace ubx
{
namespace _8
{
namespace nmea
{
struct Gsv
{
    struct Info
    {
        boost::optional<std::uint8_t> satellite_id;
        boost::optional<std::uint8_t> elevation;
        boost::optional<std::uint16_t> azimuth;
        boost::optional<std::uint8_t> snr;
    };
    Talker talker;
    boost::optional<std::uint8_t> sentence_count;
    boost::optional<std::uint8_t> sentence_number;
    boost::optional<std::uint8_t> satellites_count;
    boost::optional<std::vector<Info>> satellites_info;
};
}
}
}

#endif // UBX_8_NMEA_GSV_H_
