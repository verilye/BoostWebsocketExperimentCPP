#include "server.hpp"

int main() {

	Server* server = new Server();
	server->listenLoop();

}