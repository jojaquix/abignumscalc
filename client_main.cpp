#include "client.h"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::multiprecision;
using namespace alert::bignums;

using namespace std;

int main(int nargs, char *args[])
{
	
	if (nargs<2)
	{
		cout << "\t se requiere el puerto " << endl << endl;
	}
	else
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
				

		int port = atoi(args[1]);
		io_service io;
		Client client(io, "127.0.0.1", port);
		std::cout << "Client conected to port: " << port << std::endl;
		auto resp = client.sort_and_sum(nums);
		/**
		* response is array of nums.size + 1
		* firs element is sum
		* other elements vector sorted
		*/

		std::cout << "Response vector size: " << resp.size() << std::endl;
		for (auto& r : resp)
		{
			std::cout << r << std::endl;
		}
	}
		
	return 0;
}



