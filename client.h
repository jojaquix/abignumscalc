#include <cstdio>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/multiprecision/cpp_int.hpp>


namespace alert
{
	namespace bignums
	{

		using namespace boost::asio;
		using namespace boost::asio::ip;
		using namespace boost::multiprecision;

		/**
		* Proxy class for bignums remote operations
		*/
		
		class Client
		{
			typedef std::shared_ptr<ip::tcp::socket> socket_ptr;
		private:
			io_service& ioService;
			ip::tcp::endpoint ep;
			ip::tcp::socket sock;

		public:

			Client(io_service& ioService, std::string ip, int port);

			/**
			* exposed remote operations
			*/
			void sort_and_sum(std::vector<uint1024_t>& nums);

		};
	}
}


