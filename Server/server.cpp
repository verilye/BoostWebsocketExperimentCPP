#include "server.hpp"

// Run server from main

std::string Server::getData(boost::asio::ip::tcp::socket& socket) {
	 
	boost::asio::streambuf buf;
	read_until(socket, buf, "\n");
	std::string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;

};

void Server::sendData(boost::asio::ip::tcp::socket& socket, const std::string& message){
	
	boost::asio::write(socket, boost::asio::buffer(message + "\n"));

};

int Server::listenLoop() {

	std::cout << "Listening..." << std::endl;

	boost::asio::io_service io_service;

	// Listening for new incoming connections
	// at port 9999 with iPV4 protocol

	boost::asio::ip::tcp::acceptor acceptor_server(
		io_service,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 9999));

	// Creating socket object
	boost::asio::ip::tcp::socket server_socket(io_service);

	// waiting for connection
	acceptor_server.accept(server_socket);

	// Reading username
	std::string u_name = getData(server_socket);

	// Removing "\n" from the username
	u_name.pop_back();

	// Replying with default message to initiate chat
	std::string response, reply;
	reply = "Hello " + u_name + "!";
	std::cout << "Server: " << reply << std::endl;
	sendData(server_socket, reply);

	while (true) {

		//Fetching response
		response = getData(server_socket);

		//Popping last character "\n"
		response.pop_back();

		// Validating if the connection has to be closed
		if (response == "exit") {
			std::cout << u_name << "left!" << std::endl;
			break;
		}

		std::cout << u_name << ": " << response << std::endl;

		// Reading new message from input stream
		std::cout << "Server"
			<< ": ";
		std::getline(std::cin, reply);
		sendData(server_socket, reply);

		if (reply == "exit") {
			break;
		}
	};

	return 0;

};