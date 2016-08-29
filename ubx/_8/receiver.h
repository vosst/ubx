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
#ifndef UBX_8_RECEIVER_H_
#define UBX_8_RECEIVER_H_

#include <ubx/_8/nmea/scanner.h>
#include <ubx/_8/nmea/sentence.h>

#include <boost/asio.hpp>
#include <boost/filesystem.hpp>

#include <array>

namespace ubx
{
namespace _8
{

/// @brief Receiver connects to a ublox 8 GNSS receiver.
class Receiver : public std::enable_shared_from_this<Receiver>
{
  public:
    using Buffer = std::array<char, 50>;

    /// @brief Monitor provides calling code with means for monitoring
    /// receiver operation.
    class Monitor
    {
    public:
        /// @cond
        Monitor() = default;
        Monitor(const Monitor&) = delete;
        Monitor(Monitor&&) = delete;
        virtual ~Monitor() = default;
        Monitor& operator=(const Monitor&) = delete;
        Monitor& operator=(Monitor&&) = delete;
        /// @endcond

        /// @brief on_new_chunk is invoked for every incoming chunk of raw data.
        virtual void on_new_chunk(Buffer::iterator it, Buffer::iterator itE) = 0;

        /// @brief on_new_nmea_sentence is invoked for every complete and parsed nmea sentence.
        virtual void on_new_nmea_sentence(const nmea::Sentence& sentence) = 0;
    };

    /// @brief create returns a new Receiver instance connected to the
    /// serial port reachable under dev.
    static std::shared_ptr<Receiver> create(const boost::filesystem::path& dev, const std::shared_ptr<Monitor>& monitor);

    /// @brief run hands a thread of execution to the underlying io dispatcher.
    void run();

  private:
    /// @brief Receiver initializes a new instance opening the serial port
    /// located at path.
    ///
    /// Throws in case of issues.
    Receiver(const boost::filesystem::path& dev, const std::shared_ptr<Monitor>& monitor);

    /// @brief finalize returns a finalized reader instance reading from
    /// the serial port.
    std::shared_ptr<Receiver> finalize();

    /// @brief start_read starts an async read operation from the configured serial port.
    void start_read();

    std::shared_ptr<Monitor> monitor;
    Buffer buffer;
    nmea::Scanner nmea_scanner;
    boost::asio::io_service io_service;
    boost::asio::io_service::work work;
    boost::asio::serial_port sp;
};
}
}

#endif // UBX_8_RECEIVER_H_
