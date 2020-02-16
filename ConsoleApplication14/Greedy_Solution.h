#pragma once
#include <algorithm>
#include <iostream>
#include "LibInclude.h"
#include "linked_list.h"
using namespace std;
struct GreedyData
{
	int a;
	int b;
};

struct compare_GreedyData
{
	bool operator()(const GreedyData & a, const GreedyData & b)
	{
		if (a.a == b.a)
			return a.b > b.b;
		else
			return a.a > b.a;
	}
};

struct GreedyListData
{
	int v;
	LinkedListNode * l;

	GreedyListData(int _v, LinkedListNode* _l)
	{
		v = _v;
		l = _l;
	}

	bool operator< (const GreedyListData& e) const
	{
		return v>e.v;
	}
};

class Greedy_Solution
{
public:
	void testcmp();
	void multipleLinksSort();
};

