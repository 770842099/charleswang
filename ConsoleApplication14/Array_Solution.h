#pragma once
#include "LibInclude.h"
class Array_Solution
{
public:
	void test();
	int kthLargerNumberDetails(vector<int> a, int length, int begin, int end, int num);
	void kthLargerNumber();
	void kthLargerNumberStack();

	void slibingMaxValue();

	//leetcode 300
	void MaxIncreasedSequence();

	void MaxIncreasedSequence2();
	void binarySearchEqual();
	void binarySearchBiggerEqual();
	void binarySearchBigger();

	//leetcode 798
	int bestRotation(vector<int>& A);

	//leetcode 480
	void midNumber();

	//leetcode πÈ≤¢≈≈–Ú 493
	int mergesort_and_count(vector<int>& A, int start, int end);
	void merge(vector<int>& A, int start, int mid, int end);

	//leetcode560
	void totalSum();

	//leetcode567
	void containsSubString();
};

