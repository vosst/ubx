// Copyright (C) 2016 Thomas Voss <thomas.voss.bochum@gmail.com>
// 
// This library is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef UBX_8_NMEA_GRAMMAR_H_
#define UBX_8_NMEA_GRAMMAR_H_

#define BOOST_SPIRIT_DEBUG
#define FUSION_MAX_VECTOR_SIZE 15

#include <ubx/_8/nmea/sentence.h>

#include <boost/fusion/adapted/struct.hpp>

#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/qi_real.hpp>
#include <boost/spirit/include/qi_uint.hpp>

#include <cstdint>

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Latitude,
    (uint32_t, degrees)
    (float, minutes)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Longitude,
    (uint32_t, degrees)
    (float, minutes)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Date,
    (std::uint8_t, day)
    (std::uint8_t, month)    
    (std::uint8_t, year)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Utc,
    (std::uint8_t, hours)
    (std::uint8_t, minutes)    
    (float, seconds)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Gsa,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<ubx::_8::nmea::Gsa::OperationMode>, operation_mode)
    (boost::optional<ubx::_8::nmea::Gsa::FixMode>, fix_mode)
    (boost::optional<std::vector<boost::optional<std::uint8_t>>>, satellite_ids)
    (boost::optional<ubx::Dop<ubx::tag::Positional>>, pdop)
    (boost::optional<ubx::Dop<ubx::tag::Horizontal>>, hdop)
    (boost::optional<ubx::Dop<ubx::tag::Vertical>>, vdop)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Gga,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<ubx::_8::nmea::Utc>, utc)
    (boost::optional<ubx::_8::nmea::Latitude>, latitude)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, latitude_direction)
    (boost::optional<ubx::_8::nmea::Longitude>, longitude)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, longitude_direction)
    (boost::optional<ubx::_8::nmea::gps::FixMode>, fix_mode)
    (boost::optional<std::uint8_t>, satellites_in_use)
    (boost::optional<ubx::Dop<ubx::tag::Horizontal>>, hdop)
    (boost::optional<float>, altitude)
    (boost::optional<float>, geoidal_separation)
    (boost::optional<float>, age)
    (boost::optional<std::uint16_t>, differential_reference_station)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Gll,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<ubx::_8::nmea::Latitude>, latitude)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, latitude_direction)
    (boost::optional<ubx::_8::nmea::Longitude>, longitude)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, longitude_direction)
    (boost::optional<ubx::_8::nmea::Utc>, utc)
    (boost::optional<ubx::_8::nmea::Status>, status)
    (boost::optional<ubx::_8::nmea::Mode>, mode)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Gsv::Info,
    (boost::optional<std::uint8_t>, satellite_id)
    (boost::optional<std::uint8_t>, elevation)
    (boost::optional<std::uint16_t>, azimuth)
    (boost::optional<std::uint8_t>, snr)
)
        
BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Gsv,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<std::uint8_t>, sentence_count)
    (boost::optional<std::uint8_t>, sentence_number)
    (boost::optional<std::uint8_t>, satellites_count)
    (boost::optional<std::vector<ubx::_8::nmea::Gsv::Info>>, satellites_info)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Rmc,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<ubx::_8::nmea::Utc>, utc)
    (boost::optional<ubx::_8::nmea::Status>, status)
    (boost::optional<ubx::_8::nmea::Latitude>, latitude)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, latitude_direction)
    (boost::optional<ubx::_8::nmea::Longitude>, longitude)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, longitude_direction)
    (boost::optional<float>, speed_over_ground)
    (boost::optional<float>, course_over_ground)
    (boost::optional<ubx::_8::nmea::Date>, date)
    (boost::optional<float>, magnetic_variation)
    (boost::optional<ubx::_8::nmea::CardinalDirection>, cardinal_direction)
    (boost::optional<ubx::_8::nmea::Mode>, mode)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Txt,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<std::uint8_t>, total_number_of_sentences)
    (boost::optional<std::uint8_t>, sequence_number)
    (boost::optional<std::uint8_t>, identifier)
    (boost::optional<std::string>, message)
)

BOOST_FUSION_ADAPT_STRUCT
(
    ubx::_8::nmea::Vtg,
    (ubx::_8::nmea::Talker, talker)
    (boost::optional<float>, cog_true)
    (boost::optional<float>, cog_magnetic)
    (boost::optional<float>, sog_knots)
    (boost::optional<float>, sog_kmh)
    (boost::optional<ubx::_8::nmea::Mode>, mode)
)

namespace ubx
{
namespace _8
{
namespace nmea
{
template<typename Iterator>
class Grammar : public boost::spirit::qi::grammar<Iterator, Sentence()>
{
  public:
    Grammar() : Grammar::base_type{start}
    {
        start %= '$' >> (gga | gsa | gll | gsv | rmc | vtg) >> '*' >> checksum >> "\r\n";
        field_separator %= ',';
        checksum %= boost::spirit::qi::hex;
        talker.add
                ("GL", Talker::gl)
                ("GN", Talker::gn)
                ("GP", Talker::gp);
        status.add
                ("A", Status::valid)
                ("V", Status::not_valid);
        mode.add("A", Mode::autonomous)
                ("D", Mode::differential)
                ("E", Mode::estimated)
                ("M", Mode::manual_input)
                ("S", Mode::simulator_mode)
                ("N", Mode::data_not_valid);
        cardinal_direction.all.add
                ("N", CardinalDirection::north)
                ("S", CardinalDirection::south)
                ("E", CardinalDirection::east)
                ("W", CardinalDirection::west);
        cardinal_direction.ns.add
                ("N", CardinalDirection::north)
                ("S", CardinalDirection::south);
        cardinal_direction.ew.add
                ("E", CardinalDirection::east)
                ("W", CardinalDirection::west);
        gps.fix_mode.add
                ("0", gps::FixMode::invalid)
                ("1", gps::FixMode::gps_sps)
                ("2", gps::FixMode::differential_gps_sps)
                ("3", gps::FixMode::gps_pps)
                ("4", gps::FixMode::real_time_kinematic)
                ("5", gps::FixMode::floating_point_real_time_kinematic)
                ("6", gps::FixMode::estimated)
                ("7", gps::FixMode::manual_input)
                ("8", gps::FixMode::simulator);
        for_gsa.operation_mode.add
                ("A", Gsa::OperationMode::automatic)
                ("M", Gsa::OperationMode::manual);
        for_gsa.operation_mode.name("Gsa::OperationMode");
        for_gsa.fix_mode.add
                ("1", Gsa::FixMode::fix_not_available)
                ("2", Gsa::FixMode::fix_in_2d)
                ("3", Gsa::FixMode::fix_in_3d);
        for_gsa.fix_mode.name("Gsa::FixMode");
        pdop %= boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>();
        hdop %= boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>();
        vdop %= boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>();
        
        latitude  %= boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>() >> boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>();
        longitude %= boost::spirit::qi::uint_parser<std::uint32_t, 10, 3, 3>() >> boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>();
        date      %= boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>() >> boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>() >> boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>();
        utc       %= boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>() >> boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>() >> boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<double>>();

        gsa %= talker
                >> "GSA"                                                       >> field_separator
                >> -for_gsa.operation_mode                                     >> field_separator
                >> -for_gsa.fix_mode                                           >> field_separator
                >> boost::spirit::qi::repeat(12)[-boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>()  >> field_separator]
                >> -pdop                                                       >> field_separator
                >> -hdop                                                       >> field_separator
                >> -vdop;
        
        gga %= talker
                >> "GGA"                                                          >> field_separator
                >> -utc                                                           >> field_separator
                >> -(latitude)                                                    >> field_separator
                >> -(cardinal_direction.ns)                                       >> field_separator
                >> -(longitude)                                                   >> field_separator
                >> -(cardinal_direction.ew)                                       >> field_separator
                >> -gps.fix_mode                                                  >> field_separator
                >> -boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>()     >> field_separator
                >> -hdop                                                          >> field_separator
                >> -(boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>())  >> field_separator
                >> -boost::spirit::qi::lit('M')                                                  >> field_separator
                >> -(boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>())  >> field_separator
                >> -boost::spirit::qi::lit('M')                                                  >> field_separator
                >> -boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>()    >> field_separator
                >> -boost::spirit::qi::uint_parser<std::uint32_t, 10, 2, 2>();
        
        gll %= talker >> "GLL"                   >> field_separator
                      >> -latitude               >> field_separator
                      >> -cardinal_direction.ns  >> field_separator
                      >> -longitude              >> field_separator
                      >> -cardinal_direction.ew  >> field_separator
                      >> -utc                    >> field_separator
                      >> -status                 >> field_separator
                      >> -mode;

        gsv_info  %=
                field_separator >> -boost::spirit::qi::uint_parser<std::uint8_t, 10, 2, 2>()    >>
                field_separator >> -boost::spirit::qi::uint_parser<std::uint8_t, 10, 2, 2>()    >>
                field_separator >> -boost::spirit::qi::uint_parser<std::uint16_t, 10, 3, 3>()   >>
                field_separator >> -boost::spirit::qi::uint_parser<std::uint8_t, 10, 2, 2>();
        
        gsv %= talker >> "GSV"                                                      >> field_separator
                      >> -boost::spirit::qi::uint_parser<std::uint8_t, 10, 1, 1>()  >> field_separator
                      >> -boost::spirit::qi::uint_parser<std::uint8_t, 10, 1, 1>()  >> field_separator
                      >> -boost::spirit::qi::uint_parser<std::uint16_t, 10, 2, 2>()
                      >> +(gsv_info);

        rmc %= talker
                >> "RMC"                                                            >> field_separator
                >> -utc                                                             >> field_separator
                >> -status                                                          >> field_separator
                >> -(latitude)                                                      >> field_separator
                >> -(cardinal_direction.ns)                                         >> field_separator
                >> -(longitude)                                                     >> field_separator
                >> -(cardinal_direction.ew)                                         >> field_separator
                >> -(boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>())    >> field_separator
                >> -(boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>())    >> field_separator
                >> -date                                                            >> field_separator
                >> -(boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>())    >> field_separator
                >> -(cardinal_direction.ew)                                         >> field_separator
                >> -mode;

        vtg %= talker
                >> "VTG"                                                        >> field_separator
                >> -boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>()  >> field_separator
                >> 'T'                                                          >> field_separator
                >> -boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>()  >> field_separator
                >> 'M'                                                          >> field_separator
                >> -boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>()  >> field_separator
                >> 'N'                                                          >> field_separator
                >> -boost::spirit::qi::real_parser<float, boost::spirit::qi::strict_ureal_policies<float>>()  >> field_separator
                >> 'K'                                                          >> field_separator
                >> mode;
    }

    boost::spirit::qi::rule<Iterator, Sentence()> start;
    boost::spirit::qi::rule<Iterator> field_separator;
    boost::spirit::qi::rule<Iterator, std::uint32_t()> checksum;
    boost::spirit::qi::rule<Iterator, Latitude()> latitude;
    boost::spirit::qi::rule<Iterator, Longitude()> longitude;
    boost::spirit::qi::rule<Iterator, Date()> date;
    boost::spirit::qi::rule<Iterator, Utc()> utc;
    boost::spirit::qi::rule<Iterator, Dop<tag::Positional>()> pdop;
    boost::spirit::qi::rule<Iterator, Dop<tag::Horizontal>()> hdop;
    boost::spirit::qi::rule<Iterator, Dop<tag::Vertical>()> vdop;

    boost::spirit::qi::rule<Iterator, Gsa()> gsa;
    boost::spirit::qi::rule<Iterator, Gga()> gga;
    boost::spirit::qi::rule<Iterator, Gll()> gll;
    boost::spirit::qi::rule<Iterator, Gsv::Info()> gsv_info;
    boost::spirit::qi::rule<Iterator, Gsv()> gsv;
    boost::spirit::qi::rule<Iterator, Rmc()> rmc;
    boost::spirit::qi::rule<Iterator, Txt()> txt;
    boost::spirit::qi::rule<Iterator, Vtg()> vtg;

    // Enumerations go here
    boost::spirit::qi::symbols<char, Talker> talker;
    boost::spirit::qi::symbols<char, Status> status;
    boost::spirit::qi::symbols<char, Mode> mode;
    struct
    {
        boost::spirit::qi::symbols<char, CardinalDirection> all;
        boost::spirit::qi::symbols<char, CardinalDirection> ns;
        boost::spirit::qi::symbols<char, CardinalDirection> ew;
    } cardinal_direction;

    // Positioning-system specific rules go here
    struct
    {
        boost::spirit::qi::symbols<char, gps::FixMode> fix_mode;
    } gps;

    // Sentence-specific rules go here
    struct
    {
        boost::spirit::qi::symbols<char, Gsa::OperationMode> operation_mode;
        boost::spirit::qi::symbols<char, Gsa::FixMode> fix_mode;
    } for_gsa;
};
}
}
}

#endif // UBX_8_NMEA_GRAMMAR_H_
