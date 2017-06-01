#include <cstdio>
#include <boost/optional.hpp>
#include "serializer.h"

using namespace std;
using namespace boost::multiprecision;
using namespace alert::bignums;

Writer::Writer(ostream & o) : oStream(o)
{
}

void Writer::Write(vector<cpp_int>& nums)
{
}

Reader::Reader(istream & i)  : iStream(i)
{
}

void Reader::Read(vector<cpp_int>& nums)
{
}
