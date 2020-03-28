#pragma once
#include "LibInclude.h"

//leetcode 

class RangeModule {
private:
	map<int, int> leftRight;
	queue<map<int, int>::const_iterator> q;
public:
	RangeModule() { }

	void test()
	{
		addRange(1, 5);
		addRange(2, 6);
		addRange(3, 7);
		addRange(4, 8);
		addRange(5, 20);
		removeRange(14, 16);
		cout << queryRange(10, 14);
		cout << queryRange(13, 15);
		cout << queryRange(16, 17);
		//addRange(10, 20) : null
		//	removeRange(14, 16) : null
		//	queryRange(10, 14) : true （区间[10, 14) 中的每个数都正在被跟踪）
		//	queryRange(13, 15) : false （未跟踪区间[13, 15) 中像 14, 14.03, 14.17 这样的数字）
	    //	queryRange(16, 17) : true （尽管执行了删除操作，区间[16, 17) 中的数字 16 仍然会被跟
	}

	void addRange(int left, int right) 
	{
		//太强了
		for (auto it = leftRight.lower_bound(left); it != leftRight.end() && it->second <= right; ++it)
			q.push(it);

		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			left = min(left, it->second);
			right = max(right, it->first);
			leftRight.erase(it);
		}

		leftRight.insert(make_pair(right, left));
	}

	bool queryRange(int left, int right) {
		auto it = leftRight.lower_bound(right);
		return it != leftRight.end() && it->second <= left;
	}

	void removeRange(int left, int right) {
		for (auto it = leftRight.upper_bound(left); it != leftRight.end() && it->second < right; ++it)
			q.push(it);

		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			int oldRight = it->first;
			int oldLeft = it->second;
			leftRight.erase(it);
			if (oldLeft < left)
				leftRight.insert(make_pair(left, oldLeft));
			if (oldRight > right)
				leftRight.insert(make_pair(oldRight, right));
		}
	}
};

