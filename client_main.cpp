#include "client.h"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::multiprecision;
using namespace alert::bignums;



int main()
{
	
	io_service io;
	Client client(io,"127.0.0.1", 80);
	client.sort_and_sum();
		
	return 0;
}



