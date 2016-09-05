#include <ubx/_8/serial_port_receiver.h>

#include <iostream>
#include <system_error>

std::shared_ptr<ubx::_8::SerialPortReceiver> ubx::_8::SerialPortReceiver::create(
    boost::asio::io_service& ios, const boost::filesystem::path& dev, const std::shared_ptr<Monitor>& monitor) {
  return std::shared_ptr<SerialPortReceiver>{new SerialPortReceiver{ios, dev, monitor}};
}

ubx::_8::SerialPortReceiver::SerialPortReceiver(boost::asio::io_service& ios, const boost::filesystem::path& dev,
                                                const std::shared_ptr<Monitor>& monitor)
    : Receiver{monitor}, ios{ios}, sp{ios, dev.string().c_str()} {
  sp.set_option(boost::asio::serial_port::baud_rate(9600));
}

void ubx::_8::SerialPortReceiver::start() {
  if (-1 == ::tcflush(sp.lowest_layer().native_handle(), TCIOFLUSH))
    throw std::system_error(errno, std::system_category());

  start_read();
}

void ubx::_8::SerialPortReceiver::stop() { sp.cancel(); }

void ubx::_8::SerialPortReceiver::start_read() {
  auto thiz = shared_from_this();
  boost::asio::async_read(sp, boost::asio::buffer(&buffer.front(), buffer.size()),
                          [thiz, this](const boost::system::error_code&, std::size_t transferred) {
                            process_chunk(buffer.begin(), buffer.begin() + transferred);
                            start_read();
                          });
}
