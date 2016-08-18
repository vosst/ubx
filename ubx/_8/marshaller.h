#ifndef UBX_8_MARSHALLER_H_
#define UBX_8_MARSHALLER_H_

namespace ubx
{
namespace _8
{
/// @brief Marshaller abstracts marshaling of arbitrary messages.
class Marshaller
{
  public:
    virtual ~Marshaller() = default;

    /// @brief marshal returns a message
    /// ready to be sent over the wire to a ublox
    /// receiver.
    virtual Message marshal() const = 0;
};
}
}

#endif // UBX_8_MARSHALLER_H_
