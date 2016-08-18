#ifndef UBX_8_NMEA_TXT_H_
#define UBX_8_NMEA_TXT_H_

#include <ubx/_8/nmea/talker.h>

#include <boost/optional.hpp>

#include <cstdint>

#include <string>

namespace ubx
{
namespace _8
{
namespace nmea
{
struct Txt
{
    Talker talker;
    boost::optional<std::uint8_t> total_number_of_sentences;
    boost::optional<std::uint8_t> sentence_number;
    boost::optional<std::uint8_t> identifier;
    boost::optional<std::string> message;
};
}
}
}

#endif // UBX_8_NMEA_TXT_H_
