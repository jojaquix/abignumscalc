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

void Client::sort_and_sum(std::vector<uint1024_t>& nums)
{
	//Envia un valor 
	uint16_t size = nums.size();
	write(sock, buffer(&size, sizeof(size)));	
	for (int i = 0; i < size; ++i)
	{
		write(sock, buffer(&nums.at(i), sizeof(uint1024_t)));
	}

	std::vector<uint1024_t> resp;
	uint1024_t myNum;
	for (int i = 0; i < size +1 ; ++i)
	{		
		sock.read_some(buffer(&myNum, sizeof(myNum)));
		std::cout << "Val : " << myNum << std::endl;
		resp.push_back(myNum);
	}
	
}







