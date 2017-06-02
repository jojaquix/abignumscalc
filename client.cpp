#include "client.h"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::multiprecision;
using namespace alert::bignums;


Client::Client(io_service& ioService, std::string ip, int port) : ioService(ioService),
ep(ip::address::from_string(ip), port), sock(ioService)
{
	sock.connect(ep);
}

void Client::sort_and_sum()
{
	//Envia un valor 
	uint16_t size = 12;
	write(sock, buffer(&size, sizeof(size)));
	uint1024_t myNum("1000000000000000000000000000000000000000001");
	for (int i = 0; i < size; ++i)
	{
		write(sock, buffer(&myNum, sizeof(myNum)));

	}
}







