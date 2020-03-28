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
		//	queryRange(10, 14) : true ������[10, 14) �е�ÿ���������ڱ����٣�
		//	queryRange(13, 15) : false ��δ��������[13, 15) ���� 14, 14.03, 14.17 ���������֣�
	    //	queryRange(16, 17) : true ������ִ����ɾ������������[16, 17) �е����� 16 ��Ȼ�ᱻ��
	}

	void addRange(int left, int right) 
	{
		//̫ǿ��
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

