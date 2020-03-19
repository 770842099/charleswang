#include "Schedule_Solution.h"
#include "LibInclude.h"

void Schedule_Solution::test()
{
	meetingroom2();
}

bool Schedule_Solution_cmp(pair<int, int>a, pair<int, int>b)
{
	return a.first < b.first;
}

void Schedule_Solution::meetingroom2()
{
	vector<pair<int,int>> s = { { 0, 30 }, { 5, 10 }, { 15, 20 } };
	sort(s.begin(), s.end(), Schedule_Solution_cmp);

	int meetingNumber = 1;
	priority_queue<int, vector<int>, greater<int>> p;
	p.push(s[0].second);

	for (int i = 1; i < s.size(); i++)
	{
		if (s[i].first > p.top())
		{
			meetingNumber++;
			p.push(s[i].second);
		}
		else
		{
			p.pop();
			p.push(s[i].second);
		}
	}
	cout << meetingNumber;
}

