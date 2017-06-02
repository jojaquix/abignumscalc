#include <iostream>
#include <boost/asio.hpp>
#include "server.h"

using namespace std;
using namespace boost::asio;
using namespace alert::bignums;

int main()
{

	io_service io_Service;
	Server server(io_Service, 80);
	Server server2(io_Service, 8080);
	std::cout << "Server ready" << std::endl;
	server.start_accept();
	server2.start_accept();
	io_Service.run();

	return 0;
}