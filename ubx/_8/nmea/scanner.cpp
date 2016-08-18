#include <ubx/_8/nmea/scanner.h>

namespace nmea = ubx::_8::nmea;

nmea::Scanner::Expect nmea::Scanner::update(char c)
{
    switch (state)
    {
        case Expect::dollar:
            if (c == '$')
            {
                ss << c;
                state = Expect::more_data;
            }
            break;
        case Expect::more_data:
            switch (c)
            {
                case '\r': state = Expect::line_feed; break;
                default: break;
            }
            ss << c;
            break;
        case Expect::line_feed:
            switch (c)
            {
                case '\n': state = Expect::nothing_more; break;
                default: break;
            }
            ss << c;
            break;
    }
}

std::string nmea::Scanner::finalize()
{
    if (state != Expect::nothing_more)
        throw std::runtime_error{"Incomplete"};
    
    auto result = ss.str();
    ss = std::stringstream{};
    state = Expect::dollar;
    
    return result;
}
