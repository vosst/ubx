#ifndef UBX_8_RECEIVER_H_
#define UBX_8_RECEIVER_H_

#include <ubx/_8/nmea/scanner.h>

#include <boost/asio.hpp>

#include <array>

namespace ubx
{
namespace _8
{
/// @brief Receiver connects to a ublox 8 GNSS receiver.
class Receiver : public std::enable_shared_from_this<Receiver>
{
  public:
    /// @brief create returns a new Receiver instance connected to the
    /// serial port s.
    static std::shared_ptr<Receiver> create(const std::string& s);

    /// @brief run hands a thread of execution to the underlying io dispatcher.
    void run();

  private:
    /// @brief Receiver initializes a new instance opening the serial port
    /// located at path.
    ///
    /// Throws in case of issues.
    Receiver(const std::string& path);

    /// @brief finalize returns a finalized reader instance reading from
    /// the serial port.
    std::shared_ptr<Receiver> finalize();

    /// @brief start_read starts an async read operation from the configured serial port.
    void start_read();

    std::array<char, 50> buffer;
    nmea::Scanner nmea_scanner;
    boost::asio::io_service io_service;
    boost::asio::io_service::work work;
    boost::asio::serial_port sp;
};
}
}

#endif // UBX_8_RECEIVER_H_
