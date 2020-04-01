#pragma once
#include "LibInclude.h"
class Recursive_Solution
{
public:
	void test();
	void stackString();

	//leetcode 964
	void leastOpsExpressTarget();
	int leastOpsExpressTargetDetails(int n, int factor, unordered_map<int,int>& m, vector<int>& factValues,int& lessValue, int times);
};

