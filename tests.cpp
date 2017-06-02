#define BOOST_TEST_MODULE servertest

#include <iostream>
#include <cstdio>
#include "calculator.h"


#include <boost/test/auto_unit_test.hpp>

using namespace alert::bignums;


BOOST_AUTO_TEST_CASE(simple_test) 
{
	BOOST_CHECK_EQUAL(2 + 2, 4);
}

BOOST_AUTO_TEST_CASE(big_nums_ops)
{

	uint1024_t myNum("1000000000000000000000000000000000000000001");
	uint1024_t myNum2("15465465416274321340");

	std::cout << myNum + myNum2;
	
	
}