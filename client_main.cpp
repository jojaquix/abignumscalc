#include "client.h"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::multiprecision;
using namespace alert::bignums;



int main()
{
	
	std::vector<uint1024_t>  nums
	{
		uint1024_t("1000000000000000000000000000000000000000001"),
		uint1024_t("4653163244165465115465465416274321340"),
		uint1024_t("5761653163244165465115465465416274321340"),
		uint1024_t("15465465416274321340"),
		uint1024_t("2465465415465465416274321340"),
		uint1024_t("3163244165465115465465416274321340")
	};

	io_service io;
	Client client(io,"127.0.0.1", 8080);
	client.sort_and_sum(nums);
		
	return 0;
}



