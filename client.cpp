#include <cstdio>
#include <boost/asio.hpp>


using namespace boost::asio;
using namespace boost::asio::ip;

io_service service;
ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 80);
ip::tcp::socket sock(service);

void connect_handler(const boost::system::error_code & ec);

int main()
{

	
	
	sock.async_connect(ep, connect_handler);
	service.run();
	
	return 0;
}

void connect_handler(const boost::system::error_code & ec) {
	// here we know we connected successfully
	// if ec indicates success 
	if(!ec)
	{
		char* msj = "hola";
		write(sock, buffer(msj, 5*sizeof(char)));
	}

}

