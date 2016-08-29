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

std::shared_ptr<ubx::_8::Receiver> ubx::_8::Receiver::create(const boost::filesystem::path& dev, const std::shared_ptr<Monitor>& monitor)
{
    return std::shared_ptr<Receiver>{new Receiver{dev, monitor}}->finalize();
}

void ubx::_8::Receiver::run()
{
    io_service.run();
}

ubx::_8::Receiver::Receiver(const boost::filesystem::path& dev, const std::shared_ptr<Monitor>& monitor)
    : monitor{monitor},
      work{io_service},
      sp{io_service, dev.string().c_str()}
{
    sp.set_option(boost::asio::serial_port::baud_rate(9600));
    ::tcflush(sp.lowest_layer().native_handle(), TCIOFLUSH);
}

std::shared_ptr<ubx::_8::Receiver> ubx::_8::Receiver::finalize()
{
    start_read();
    return shared_from_this();
}

void ubx::_8::Receiver::start_read()
{
    auto thiz = shared_from_this();
    boost::asio::async_read(sp, boost::asio::buffer(&buffer.front(), buffer.size()), [thiz, this](const boost::system::error_code&, std::size_t transferred) {
        auto it = buffer.begin(); auto itE = buffer.begin() + transferred;
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
        start_read();
    });
}

