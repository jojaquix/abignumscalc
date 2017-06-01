#include <cstdio>
#include <boost/asio.hpp>
#include <boost/multiprecision/cpp_int.hpp>


using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::multiprecision;

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
		//Envia un valor 
		uint16_t size = 12;	
		write(sock, buffer(&size, sizeof(size)));
		uint1024_t myNum("1000000000000000000000000000000000000000001");
		for (int i = 0; i < size; ++i)
		{
			write(sock, buffer(&myNum,sizeof(myNum)));
		}


	}

}

