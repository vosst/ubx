#include <ubx/_8/receiver.h>

#include <ubx/_8/nmea/grammar.h>

#include <iostream>

namespace qi = boost::spirit::qi;

namespace
{
// Printer pretty-prints issues while parsing NMEA sentences.
struct Printer
{
    typedef boost::spirit::utf8_string string;

    void element(string const& tag, string const& value, int depth) const
    {
        for (int i = 0; i < (depth*4); ++i) // indent to depth
            std::cout << ' ';

        std::cout << "tag: " << tag;
        if (value != "")
            std::cout << ", value: " << value;
        std::cout << std::endl;
    }
};

void print_info(boost::spirit::info const& what)
{
    using boost::spirit::basic_info_walker;

    Printer pr;
    basic_info_walker<Printer> walker(pr, what.tag, 0);
    boost::apply_visitor(walker, what.value);
}
}

ubx::_8::Receiver::Receiver(const std::shared_ptr<Monitor>& monitor)
    : monitor{monitor}
{
}

void ubx::_8::Receiver::process_chunk(Buffer::iterator it, Buffer::iterator itE)
{
    monitor->on_new_chunk(it, itE);

    while (it != itE)
    {
        try
        {
            if (nmea::Scanner::Expect::nothing_more == nmea_scanner.update(*it))
            {
                auto token = nmea_scanner.finalize();
                nmea::Sentence sentence;
                if (qi::parse(token.begin(), token.end(), nmea::Grammar<std::string::iterator>(), sentence))
                    monitor->on_new_nmea_sentence(sentence);
                else
                    std::cout << "Failed to parse sentence: " << token << std::endl;
            }
        }
        catch (const qi::expectation_failure<std::string::iterator>& e)
        {
            std::cout << "expected: "; print_info(e.what_);
            std::cout << "got: \"" << std::string(e.first, e.last) << '"' << std::endl;
        }

        ++it;
    }
}
