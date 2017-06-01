#include <iostream>
#include <cstdio>
#include <boost/asio.hpp>
#include "calculator.h"

using namespace alert::bignums;


int main()
{	
	
	uint1024_t myNum("1000000000000000000000000000000000000000001");
	uint1024_t myNum2("15465465416274321340");

	std::cout << myNum + myNum2;
	//getchar();

	return 0;
}