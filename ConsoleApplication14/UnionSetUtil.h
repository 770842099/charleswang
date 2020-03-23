#pragma once
#include "LibInclude.h"
class UnionSetUtil
{
public:
	void init(int num);
	void unionGroup(int i, int j);
	int getParent(int i);

public:
	vector<int> v;

};

