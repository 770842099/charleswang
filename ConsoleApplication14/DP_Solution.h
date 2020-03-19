#pragma once
#include "LibInclude.h"
class DP_Solution
{
public:
	void test();

	//boat carry car across sea,  http://poj.org/problem?id=2336
	void boatCarryCarAccrossRiver();
	void shortestSubStringSequence();
	void bag01();



	//leetcode 600
	void bitDP();
	int bitDPDetails(int pos, int pre, bool limit, vector<int> bit, int dp[][2]);
};

