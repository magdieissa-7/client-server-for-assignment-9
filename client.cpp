#include <array>
#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using boost::asio::ip::tcp;

int main() {
  boost::asio::io_context io_context;

  tcp::resolver resolver(io_context);
  tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "daytime");

  tcp::socket socket(io_context);
  boost::asio::connect(socket, endpoints);

  while (true) {
    array<char, 128> buf;
    boost::system::error_code ec;

    size_t len = socket.read_some(boost::asio::buffer(buf), ec);

    if (ec == boost::asio::error::eof)
      break;
    else if (ec)
      throw boost::system::system_error(ec);

    cout.write(buf.data(), len);
  }

  return 0;
}
