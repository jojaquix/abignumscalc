#include <iostream>
#include <fstream>
#include <string>

#include "client.h"


using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::multiprecision;
using namespace alert::bignums;

using namespace std;

int main(int nargs, char *args[])
{
	
	if (nargs<3)
	{
		cout << "Se requiere el puerto y la ruta completa del archivo de datos" << endl << endl;
	}
	else
	{

		std::vector<uint1024_t>  nums;
		nums.clear();
		int port = atoi(args[1]);
		io_service io;

		std::string line;
		std::ifstream dataFile(args[2]);
		if (dataFile.is_open())
		{
			while (getline(dataFile, line))
			{
				cout << line << '\n';
				uint1024_t num(line);
				nums.push_back(num);
			}
			dataFile.close();
		}

		if (nums.size() > 0)
		{

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
		else
		{
			std::cout << "empty vector" << std::endl;
		}
	}
	
		
	return 0;
}



