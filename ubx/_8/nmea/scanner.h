#ifndef UBX_8_NMEA_SCANNER_H_
#define UBX_8_NMEA_SCANNER_H_

#include <sstream>
#include <string>

namespace ubx
{
namespace _8
{
namespace nmea
{
/// @brief Scanner inspects incoming characters and tries to identify beginning and end of
/// NMEA messages.
class Scanner
{
public:
    /// @brief Expect models the state of the scanner, describing what it expects next
    /// to advance its state.
    enum class Expect
    {
        dollar,
        more_data,
        line_feed,
        nothing_more
    };

    /// @brief update updates the state of the Scanner with c.
    Expect update(char c);

    /// @brief finalize tries to extract a complete NMEA sentence.
    ///
    /// Throws a std::runtime_error if the Scanner is not in state
    /// Expect::nothing_more.
    std::string finalize();

private:
    Expect state{Expect::dollar}; ///< The state of the Scanner.
    std::stringstream ss;         ///< Buffer holding incomplete sentence data.
};
}
}
}

#endif // UBX_8_NMEA_SCANNER_H_
