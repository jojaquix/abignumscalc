#include <iostream>
#include <cstdio>
#include <boost/asio.hpp>
#include <atomic>
#include <thread>
#include <functional>
#include <memory>
#include "server.h"


using namespace std;
using namespace std::placeholders;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace alert::bignums;


Server::Server(io_service& ioService, int port) :
	ioService(ioService),
	acceptor(ioService, tcp::endpoint(tcp::v4(), port))
{}


//sync server
void Server::run()
{
	while (!mExit)
	{
		socket_ptr sock(new tcp::socket(ioService));
		acceptor.accept(*sock);
		thread(bind(&Server::onClientSession, this, sock));
	}
}


void Server::exit(bool e)
{
	mExit = e;
}


void Server::start_accept()
{
	socket_ptr sock(new ip::tcp::socket(ioService));
	acceptor.async_accept(*sock, bind(&Server::on_accept, this, sock, _1));
}

void Server::on_accept(socket_ptr sock, const boost::system::error_code & err)
{
	if (err)
	{
		//todo: log error
		return;
	}

	onClientSession(sock);

	start_accept();
}


void Server::onClientSession(socket_ptr sock)
{
	std::vector<uint1024_t> nums;
	boost::system::error_code err;
	size_t len;
	uint16_t size;
	uint1024_t myNum;

	len = sock->read_some(buffer(&size, sizeof(size)), err);
	std::cout << "Size of vector: " << size << std::endl;
	
	for (int i = 0; i < size; ++i)
	{
		len = sock->read_some(buffer(&myNum, sizeof(myNum)), err);
		std::cout << "Val : " << myNum << std::endl;
		nums.push_back(myNum);
	}	
	
}



