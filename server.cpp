#include <iostream>
#include <cstdio>
#include <boost/asio.hpp>
#include <atomic>
#include <thread>
#include <functional>
#include <memory>
#include "calculator.h"


using namespace std;
using namespace std::placeholders;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace alert::bignums;

class Server
{

	typedef std::shared_ptr<ip::tcp::socket> socket_ptr;

private:

	atomic_bool mExit { false };

	io_service& ioService;
	tcp::acceptor acceptor;

public:
	Server(io_service& ioService, int port) :
		ioService(ioService),
		acceptor(ioService, tcp::endpoint(tcp::v4(), port))		
	{}

	
	//sync server
	void run()
	{
		while (!mExit)
		{
			socket_ptr sock(new tcp::socket(ioService));
			acceptor.accept(*sock);
			thread(bind(&Server::onClientSession, this, sock));
		}
	}


	void exit(bool e)
	{
		mExit = e;
	}


	void start_accept() 
	{
		socket_ptr sock(new ip::tcp::socket(ioService));
		acceptor.async_accept(*sock, bind(&Server::on_accept,this, sock, _1));
	}

	void on_accept(socket_ptr sock, const boost::system::error_code & err) 
	{
		if (err)
		{
			//todo: log error
			return;
		}

		onClientSession(sock);				
		
		start_accept();
	}


	void onClientSession(socket_ptr sock)
	{
		uint8_t data[1024];
		data[0] = 0;
		boost::system::error_code err;
		size_t len = sock->read_some(buffer(data, 1024), err);
		if (len > 0)
		{
			std::cout << data;
			write(*sock, buffer("ok", 2));
		}
	}


};



int main()
{	
		
	io_service io_Service;
	Server server(io_Service, 80);
	std::cout << "Server ready" << std::endl;
	server.start_accept();
	io_Service.run();
		
	return 0;
}