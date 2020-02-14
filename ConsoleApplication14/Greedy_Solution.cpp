#include "Greedy_Solution.h"


void Greedy_Solution::testcmp()
{
	int a[7] = { 1,2,3,4,5,6,7 };
	int b[7] = { 2,4,6,7,8,9,10 };
	GreedyData d[7];
	for (int i = 0; i < 7; i++)
	{
		d[i].a = a[i];
		d[i].b = b[i];
	}
	//sort(d, d + 7, compare_GreedyData);
	for (auto& v : d)
	{
		cout << v.a << endl;
	}
}

void Greedy_Solution::multipleLinksSort()
{
	LinkedList a;
	a.addLast(1);
	a.addLast(2);
	a.addLast(3);
	a.addLast(4);

	LinkedList b;
	b.addLast(2);
	b.addLast(7);
	b.addLast(10);
	b.addLast(12);

	LinkedList c;
	c.addLast(32);
	c.addLast(38);
	c.addLast(46);
	c.addLast(50);

	LinkedList d;
	d.addLast(5);
	d.addLast(64);
	d.addLast(65);
	d.addLast(255);

	priority_queue<GreedyListData, vector<GreedyListData>> p;
	p.emplace(a.head->data, a.head->next);
	p.emplace(b.head->data, b.head->next);
	p.emplace(c.head->data, c.head->next);
	p.emplace(d.head->data, d.head->next);

	LinkedList result;
	while (!p.empty())
	{
		GreedyListData data = p.top();
		p.pop();
		result.addLast(data.v);

		if (data.l!=NULL)
			p.emplace(data.l->data, data.l->next);
	}

	result.print();
}
