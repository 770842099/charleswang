#include "UnionSetUtil.h"
void UnionSetUtil::init(int num)
{
	this->v.resize(num);
	for (int i = 0; i < num; i++)
	{
		v[i] = i;
	}
}


void UnionSetUtil::unionGroup(int i, int j)
{
	if (getParent(i)< getParent(j))
	{
		v[getParent(j)] = getParent(i);
	}
	else if (getParent(i) > getParent(j))
	{
		v[getParent(i)] = getParent(j);
	}
}


int UnionSetUtil::getParent(int i)
{
	if (v[i] != i)
	{
		v[i] = getParent(v[i]);
	}
	return v[i];
}