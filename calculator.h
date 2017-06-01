#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <iomanip>
#include <vector>


namespace alert
{
	namespace bignums
	{
		using namespace std;
		using namespace boost::multiprecision;
		
		class Operations
		{
			void Sort(vector<uint1024_t>& nums);
			uint1024_t Sum(vector<uint1024_t>& nums);
		};

	}
}