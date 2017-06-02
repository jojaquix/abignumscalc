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
		/**
        * Operaciones habilitadas sobre números grandes.
        */
        
		class Operations
		{
		public:
			/**
			* return based in auto move semantics
			*/
			static vector<uint1024_t> sort(vector<uint1024_t>& nums);
			static uint1024_t sum(vector<uint1024_t>& nums);
		private:

			/**
			* quick sort implementation using indexes.
			*/
			static void qsort(vector<uint1024_t>& nums, vector<int>&idx, int p, int q);
			static int partition(vector<uint1024_t>& nums, vector<int>& idx, int p, int q);

		};

	}
}