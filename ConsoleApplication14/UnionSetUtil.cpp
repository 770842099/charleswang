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
	int i1 = getParent(i);
	int j1 = getParent(j);

	if (i1 != j1)
		v[i1] = j1;
	
	//if (getParent(i)< getParent(j))
	//{
	//	v[getParent(j)] = getParent(i);
	//}
	//else if (getParent(i) > getParent(j))
	//{
	//	v[getParent(i)] = getParent(j);
	//}
}


int UnionSetUtil::getParent(int i)
{
	if (v[i] != i)
	{
		v[i] = getParent(v[i]);
	}
	return v[i];
}