#pragma once
#include "LibInclude.h"
class Number_Solution
{
public:
	void test();

	//leetcode 254
	void allPossibleFactor();
	void allPossibleFactorDetails(int remianing, int last, vector<int> result);

	//leetcode 556
	void nextBigNumber();

	//leetcode 1491
	void numberOf2sInRange();

	//leetcode 1286
	void CombinationIterator();
	void CombinationIteratorDetails(string&s, vector<int>& points);

};

