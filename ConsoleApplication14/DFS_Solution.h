#pragma once
#include "LibInclude.h"
class DFS_Solution
{
public:
	void test();
	void placePlates();
	void placePlatesDetails(int n, stack<int> s);

	void go2DMaxtirx();
	void go2DMaxtirxDetail(string s, int index, int x, int y, vector<vector<char>> g, bool visited[3][4]);

	//leetcode 638


	//leetcode 1000
	void mergeStones();
	int mergeStonesDetails(vector<int> input, int start, int end, int k, vector<vector<int>>& dp, vector<int>& sum);

	void mergeStonesSplits(int start, int end, int k,int index, vector<int> split, vector<vector<int>>& splits);


	//leetcode 1125
	void smallestSufficientTeam();
};

struct DFS_Solution_smallestSufficientTeam
{
	int skills;
	int peoples;
	vector<int> peopleNum;

	DFS_Solution_smallestSufficientTeam(int _skills, int _people, vector<int> _peopleNum)
	{
		skills = _skills;
		peoples = _people;
		peopleNum = _peopleNum;
	}
};


