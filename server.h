#include <iostream>
#include <cstdio>
#include <boost/asio.hpp>
#include <atomic>
#include <thread>
#include <functional>
#include <memory>
#include "calculator.h"



namespace alert
{
	namespace bignums
	{


		using namespace std;
		using namespace std::placeholders;
		using namespace boost::asio;
		using namespace boost::asio::ip;
		using namespace alert::bignums;

		class Server
		{

			typedef std::shared_ptr<ip::tcp::socket> socket_ptr;

		private:

			/**
			* exit from sync run
			*/
			atomic_bool mExit{ false };

			/**
			* io service object reference
			*/
			io_service& ioService;

			/**
			* acceptor of connections
			*/
			tcp::acceptor acceptor;

		public:

			/**
			* Constructor
			*/
			Server(io_service& ioService, int port);

			/**
			* Run server in sync mode.
			*/
			void run();


			/**
			* Terminate server in sync mode.
			*/
			void exit(bool e);
			
			/**
			* start accept connections
			*/
			void start_accept();

			/**
			* accpet event handler
			*/
			void on_accept(socket_ptr sock, const boost::system::error_code & err);


			/**
			* On data input event handler.
			*/
			void onClientSession(socket_ptr sock);

		};

	}
}

