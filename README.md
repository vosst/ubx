# ubx [![Build Status](https://travis-ci.org/vosst/ubx.svg?branch=master)](https://travis-ci.org/vosst/ubx)
C++ library and simple tooling to access ublox chipsets.

```cpp
#include <ubx/_8/serial_port_receiver.h>

#include <fstream>
#include <iostream>

namespace {
class PrintingMonitor : public ubx::_8::Receiver::Monitor {
 public:
  PrintingMonitor(const boost::filesystem::path& trace)
      : out{trace.string().c_str()} {}

  void on_new_chunk(ubx::_8::Receiver::Buffer::iterator it,
                    ubx::_8::Receiver::Buffer::iterator itE) override {
    std::copy(it, itE, std::ostream_iterator<char>(out, ""));
    out << std::flush;
  }

  void on_new_nmea_sentence(const ubx::_8::nmea::Sentence& sentence) override {
    std::cout << "on_new_nmea_sentence: " << sentence;
  }

 private:
  std::ofstream out;
};
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << " /path/to/serial/device [/path/to/trace/file]" << std::endl;
    return EXIT_FAILURE;
  }

  boost::asio::io_service ios;
  boost::asio::io_service::work ka{ios};

  boost::asio::signal_set ss(ios, SIGINT, SIGQUIT);
  ss.async_wait([&](const boost::system::error_code& ec, int) {
    if (not ec)
      ios.stop();
  });

  boost::filesystem::path device{argv[1]};
  boost::filesystem::path trace{argc > 2 ? argv[2] : "/tmp/trace.nmea"};

  ubx::_8::SerialPortReceiver::create(ios, boost::filesystem::path(device),
                                      std::make_shared<PrintingMonitor>(trace))
      ->start();

  ios.run();

  return EXIT_SUCCESS;
}
```

# Examples

Right now, accessing ublox receivers connected via a serial port is supported.
```bash
ubx_serial_port_receiver 
Usage: ./ubx_serial_port_receiver /path/to/serial/device [/path/to/trace/file]
sudo ./ubx_serial_port_receiver /dev/ttyACM1
...
```

# Status
The repo exists and the code in here is mostly meant for bootstrapping purposes.
Factoring everything under test is ongoing, the code has seen quite some real world
exposure, though.
