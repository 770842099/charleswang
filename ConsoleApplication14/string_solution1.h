#pragma once

#include "LibInclude.h"
using namespace std;
class string_solution
{
public:
	void run();
	void two_same_strings();
	void check_two_strings(string s1, string s2, int& ans);

	void test_function();
	void yixuci();
	void shortestContainingSubLength();

	void leetCode267_CurcleString();
	void leetCode267_CurcleStringDetail(string s, vector<int> chars, char* characters);

	//leetcode 395
	void maxiumStringContainsK();
	void maxiumStringContainsKDetails(string s, int start, int end, int k, int& maxLengh);

	//leetcode 411
	void shortestPath();

	//leetcode 471
	void shortenString();

	//leetcode 1024
	void camelMatch();
};

