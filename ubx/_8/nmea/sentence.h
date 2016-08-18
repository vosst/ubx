#ifndef UBX_8_NMEA_SENTENCE_H_
#define UBX_8_NMEA_SENTENCE_H_

#include <ubx/_8/nmea/gga.h>
#include <ubx/_8/nmea/gll.h>
#include <ubx/_8/nmea/gsa.h>
#include <ubx/_8/nmea/gsv.h>
#include <ubx/_8/nmea/rmc.h>
#include <ubx/_8/nmea/txt.h>
#include <ubx/_8/nmea/vtg.h>

#include <boost/variant.hpp>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief All known nmea sentences should go here.
///
/// NOTE: Expand at the end.
typedef boost::variant<
    Gga,
    Gsa,
    Gll,
    Gsv,
    Rmc,
    Txt,
    Vtg
> Sentence;
}
}
}

#endif // UBX_8_NMEA_SENTENCE_H_

