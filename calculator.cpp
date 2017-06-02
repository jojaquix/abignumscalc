#include <cstdio>
#include <numeric>

#include "calculator.h"

using namespace std;
using namespace boost::multiprecision;
using namespace alert::bignums;

vector<uint1024_t> Operations::sort(vector<uint1024_t>& nums)
{
	//se usa qsort basad en indices
	vector<int> idx(nums.size());
	std::iota(std::begin(idx), std::end(idx), 0);

	qsort(nums, idx, idx.front(), idx.back());

	//se copian los valores en el orden adecuado;
	vector<uint1024_t> res;

	for (auto& i : idx)
	{
		res.push_back(nums[i]);
	}

	return res;

}

uint1024_t Operations::sum(vector<uint1024_t>& nums)
{
	uint1024_t acum = 0;
	std::for_each(std::begin(nums), std::end(nums),
		[&](uint1024_t n)
	{
		acum += n;
	}
	);

	return acum;
}

void  Operations::qsort(vector<uint1024_t>& nums, vector<int>& idx, int p, int q)
{
	int r;
	if (p < q)
	{
		r = partition(nums, idx, p, q);
		qsort(nums, idx, p, r - 1);
		qsort(nums, idx, r + 1, q);
	}
}

int  Operations::partition(vector<uint1024_t>& nums, vector<int>& idx, int p, int q)
{
	int left;
	int right;

	auto pivot = nums[idx[p]];
	left = p;
	right = q;

	while (left < right)
	{
		while (nums[idx[right]] > pivot)
		{
			right--;
		}
		while ((left < right) && ((nums[idx[left]] <= pivot)))
		{
			left++;
		}

		if (left < right)
		{
			swap(idx[left], idx[right]);
		}
	}

	swap(idx[p], idx[right]);

	return right;
}

