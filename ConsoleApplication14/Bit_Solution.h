#pragma once
#include "LibInclude.h"
class Bit_Solution
{
public:
	void test();
	void AllCombition();

	//leetcode 982
	void countTriplets();

	//lintcode 1382
	long long getMaxValue(int s, vector<int> &v, vector<int> &c);

	pair<long long, long long> getCapacity(int s, int start, vector<int> &v, vector<int> &c, int num);
};

