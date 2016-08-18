#ifndef UBX_8_CFG_PRT_H_
#define UBX_8_CFG_PRT_H_

#include <ubx/_8/marshaller.h>

namespace ubx
{
constexpr std::size_t pow(std::size_t base, std::size_t exponent)
{
    return exponent == 0 ? 1 : base * pow(base, exponent - 1);
}

template<typename Numeric>
class Bitfield
{
  public:
    static_assert(std::is_integral<Numeric>::value, "Numeric has to be an integral type.");

    template<std::size_t Begin, std::size_t End, typename Value>
    Bitfield<Numeric>& set(Value value)
    {
        static_assert(std::is_integral<Value>::value, "Value has to be an integral type.");
        static_assert(Begin < End, "Begin and End must refer to a valid range.");
        static_assert(End < sizeof(Numeric) * 8, "Out of range.");

        if (value > pow(2, End - Begin + 1) - 1)
            throw std::out_of_range("Value cannot be encoded in bit range.");

        data = data | (value << Begin);
        
        return *this;
    }
  private:
    Numeric data;
};

namespace _8
{
namespace cfg
{
enum class Protocol : std::uint16_t
{
    ubx = 1 << 0,
    nmea = 1 << 1,
    rtcm_2 = 1 << 2,
    rtcm_3 = 1 << 5
};

enum class PortIdentifierNumber : std::uint8_t
{
    ddc = 0,
    uart_1 = 1,
    usb = 3,
    spi = 4
};

enum class Polarity : std::uint8_t
{
    high_active = 0,
    low_active = 1
};

struct TxReady
{
    bool enabled;
    Polarity polarity;
};

class Prt : public Marshaller
{
  public:
    static constexpr const Class cls{0x06};
    static constexpr const Id id{0x00};
    
    // From Marshaller.
    Message marshal() const override;

  private:
    PortIdentifierNumber port_id;
    std::uint8_t reserved_1;
    Bitfield<std::uint16_t> tx_ready;
    Bitfield<std::uint32_t> mode;
    std::uint32_t baud_rate;
    Bitfield<std::uint16_t> in_proto;
    Bitfield<std::uint16_t> out_proto;
    Bitfield<std::uint16_t> flags;
    std::uint8_t reserved_2;
    std::uint8_t reserved_3;
};
}
}
}

#endif // UBX_8_CFG_PRT_H_
