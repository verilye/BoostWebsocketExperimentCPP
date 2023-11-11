#include <boost/asio.hpp>
#include <iostream>
#include <string>


class Server {

public:

	std::string getData(boost::asio::ip::tcp::socket& socket);
	void sendData(boost::asio::ip::tcp::socket& socket, const std::string& message);
	int listenLoop();
};