#include <boost/asio.hpp>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;
using boost::asio::ip::tcp;

string make_daytime_string() {
  time_t now = time(0);
  return ctime(&now);
}

int main() {
  boost::asio::io_context io_context;

  tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));

  while (true) {
    tcp::socket socket(io_context);
    acceptor.accept(socket);

    string message = make_daytime_string();
    boost::system::error_code ec;

    boost::asio::write(socket, boost::asio::buffer(message), ec);
  }

  return 0;
}

