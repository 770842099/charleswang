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

	//leetcode 375
	void guessNumbers();

	//leetcode 376
	void Swing();

	//leetcode 377
	void AllArrangement();

	//leetcode 474
	void maxiumnOneAndZero();

	//leetcode 494
	void basicBag01();

	//leetcode 583
	void removeCharacters();

	//leetcode 646
	void findLongestChain1();
	void findLongestChain2();

	//leetcode 813
	void largestSumOfAverages();

	//leetcode 879
	void profitPlan();

	//leetcode 920
	void numMusicPlaylists();

	//leetcode 940
	void distinctSubseqII();

	//leetcode 956
	void tallestBillboard();

	//leetcode 1186
	void maximumSum();

	//leetcode 1216
	void isValidPalindrome();

	//leetcode 1230
	void probabilityOfHeads();

	//lintcode 789
	int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts);

};


