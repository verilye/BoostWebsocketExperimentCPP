#include "client.hpp"

std::string Client::getData(boost::asio::ip::tcp::socket& socket) {
	
	// Read the buffer
	boost::asio::streambuf buf;

	// Read buffer inside socket, include terminating char
	read_until(socket, buf, "\n");

	// Cast to string and copy from buffer memory location to string
	std::string data = boost::asio::buffer_cast<const char*>(buf.data());

	return data;
};

void Client::sendData(boost::asio::ip::tcp::socket& socket, const std::string& message) {

	boost::asio::write(socket, boost::asio::buffer(message + "\n"));

};

int Client::chat() {

	boost::asio::io_service io_service;

	// create socket
	boost::asio::ip::tcp::socket client_socket(io_service);

	client_socket.connect(
		boost::asio::ip::tcp::endpoint(
			boost::asio::ip::address::from_string("127.0.0.1"),
			9999));


	// Getting username from user
	std::cout << "Please enter your username: ";

	std::string u_name, reply, response;

	std::getline(std::cin, u_name);

	//Sending username to server

	sendData(client_socket, u_name);

	//Infinite loop for chatting
	while (true) {

		// Fetching response
		response = getData(client_socket);

		// Pop last terminating char
		response.pop_back();

		// Validating if the connection has to be close
		if (response == "exit") {
			std::cout << "Connection terminated" << std::endl;
			break;
		}

		std::cout << "Server: " << response << std::endl;

		// Reading new message from input stream
		std::cout << u_name << ": ";
		std::getline(std::cin, reply);
		sendData(client_socket, reply);

		if (reply == "exit") {
			break;
		}

	}

	return 0;
};