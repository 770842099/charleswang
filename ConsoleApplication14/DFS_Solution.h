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
};

