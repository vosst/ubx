#include <ubx/_8/serial_port_receiver.h>

#include <iostream>

std::shared_ptr<ubx::_8::Receiver> ubx::_8::SerialPortReceiver::create(
    const boost::filesystem::path& dev,
    const std::shared_ptr<Monitor>& monitor) {
  return std::shared_ptr<SerialPortReceiver> {
    new SerialPortReceiver { dev, monitor }
  }
  ->finalize();
}

void ubx::_8::SerialPortReceiver::run() {
  io_service.run();
}

void ubx::_8::SerialPortReceiver::stop() {
  io_service.stop();
}

ubx::_8::SerialPortReceiver::SerialPortReceiver(
    const boost::filesystem::path& dev,
    const std::shared_ptr<Monitor>& monitor)
    : Receiver{monitor},
      work{io_service},
      sp{io_service, dev.string().c_str()} {
  sp.set_option(boost::asio::serial_port::baud_rate(9600));
  ::tcflush(sp.lowest_layer().native_handle(), TCIOFLUSH);
}

std::shared_ptr<ubx::_8::SerialPortReceiver>
ubx::_8::SerialPortReceiver::finalize() {
  start_read();
  return shared_from_this();
}

void ubx::_8::SerialPortReceiver::start_read() {
  auto thiz = shared_from_this();
  boost::asio::async_read(
      sp, boost::asio::buffer(&buffer.front(), buffer.size()),
      [thiz, this](const boost::system::error_code&, std::size_t transferred) {
        process_chunk(buffer.begin(), buffer.begin() + transferred);
        start_read();
      });
}
