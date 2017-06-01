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
		
		class Writer
		{	
			ostream& oStream;
			Writer(ostream& o);
			void Write(vector<cpp_int>& nums);			
		};

		class Reader
		{
			istream& iStream;
			Reader(istream& i);
			void Read(vector<cpp_int>& nums);
		};
	}
}