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
    std::copy(it, itE, std::ostream_iterator<char>(out, "")); out << std::flush;
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

  boost::filesystem::path device{argv[1]};
  boost::filesystem::path trace{argc > 2 ? argv[2] : "/tmp/trace.nmea"};

  ubx::_8::SerialPortReceiver::create(boost::filesystem::path(device),
                                      std::make_shared<PrintingMonitor>(trace))
      ->run();

  return EXIT_SUCCESS;
}
