#pragma once
#include "LibInclude.h"
class SegmentTree
{
public:
		void test();
};

struct SegmentTree_Node
{
	SegmentTree_Node* l;
	SegmentTree_Node* r;
	int s;
	int e;
	int m;
	int val;
	bool tag;
	SegmentTree_Node(int s, int e) : l(nullptr), r(nullptr), s(s), e(e), m((s + e) / 2), val(0), tag(false) {}

	SegmentTree_Node* Left() {
		if (s == e) return nullptr;
		l = l ? l : new SegmentTree_Node(s, m);
		return l;
	}

	SegmentTree_Node* Right() {
		if (s == e) return nullptr;
		r = r ? r : new SegmentTree_Node(m+1, e);
		return r;
	}

	void update(int start, int end, int newVal) {
		if (s == start && e == end)
		{
			val = newVal;
			tag = true;
			return;
		}

		if (tag) {
			Left()->update(s, m, val);
			Right()->update(m + 1, e, val);
			tag = false;
		}
		if (end <= m) Left()->update(start, end, newVal);
		else if (start >= m + 1) Right()->update(start, end, newVal);
		else {
			Left()->update(start, m, newVal);
			Right()->update(m + 1, end, newVal);
		}
		val = max(Left()->val, Right()->val);
	}

	int query(int start, int end) {
		if (s == start && e == end) return val;
		if (tag) return val;
		if (end <= m) return Left()->query(start, end);
		if (start >= m + 1) return Right()->query(start, end);
		return max(Left()->query(start, m), Right()->query(m + 1, end));
	}
};

