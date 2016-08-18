#ifndef UBX_8_SCANNER_H_
#define UBX_8_SCANNER_H_

#include <cstdint>

#include <vector>

namespace ubx
{
namespace _8
{
static constexpr const std::uint8_t sync_char_1{0xb5};
static constexpr const std::uint8_t sync_char_2{62};

enum class Class
{
    cfg = 0x06
};

enum class Id
{
};

struct Message
{    
    Class cls;
    Id id;
    std::uint16_t length;
    std::vector<std::uint8_t> payload;
    std::uint8_t ck_a;
    std::uint8_t ck_b;
};
}
}

#endif // UBX_8_SCANNER_H_
