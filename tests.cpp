#define BOOST_TEST_MODULE servertest

#include <iostream>
#include <cstdio>
#include "calculator.h"


#include <boost/test/auto_unit_test.hpp>

using namespace alert::bignums;



BOOST_AUTO_TEST_CASE(big_nums_ops)
{

	uint1024_t myNum("1000000000000000000000000000000000000000001");
	uint1024_t myNum2("15465465416274321340");
	std::cout << myNum + myNum2;
}

BOOST_AUTO_TEST_CASE(big_nums_sort)
{


	std::vector<uint1024_t>  nums 
	{
		uint1024_t ("1000000000000000000000000000000000000000001"),
		uint1024_t ("4653163244165465115465465416274321340"),
		uint1024_t ("5761653163244165465115465465416274321340"),
		uint1024_t ("15465465416274321340"),
		uint1024_t ("2465465415465465416274321340"),
		uint1024_t ("3163244165465115465465416274321340")
	};

	std::cout << "Original values: " << std::endl;

	for(auto& n : nums)
	{
		std::cout << n << std::endl;
	}

	std::cout << "Ordered values: " << std::endl;
	auto res = Operations::sort(nums);
	auto n1 = res.front();
	for (auto& n : res)
	{
		std::cout << n << std::endl;
		BOOST_CHECK(n1 <= n);
		n1 = n;
	}



	
}