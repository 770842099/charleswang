#pragma once
#include "LibInclude.h"
class Sort_Solution
{
public:
	void test();

	void missionscheduler();
	//leetcode621 missionscheduler

	//leetcode630
	void mostcources();
	static bool comp(const vector<int>& v1, const vector<int>& v2) {
		return v1[1] < v2[1];
	}




};

struct missionscheduler_obj
{
	char c;
	int times;

	missionscheduler_obj(char c, int times)
	{
		this->c = c;
		this->times = times;
	}


	bool operator< (const missionscheduler_obj& e) const
	{
		return times < e.times;
	}
	//bool operator< (const people& e) const
};

