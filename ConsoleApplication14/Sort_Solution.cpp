#include "Sort_Solution.h"
void Sort_Solution::test()
{
	missionscheduler();
}

void Sort_Solution::missionscheduler()
{
	vector<char> v = { 'A', 'A', 'A', 'B', 'B', 'B', 'C','C' };
	int n = 2;

	priority_queue< missionscheduler_obj> p;
	queue<missionscheduler_obj> q;
	vector<int> times(26, 0);
	for (char c : v)
	{
		times[c - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (times[i] != 0)
			p.emplace(i + 'A', times[i]);
	}

	vector<char> result;
	for (int i = 0; i < n; i++)
	{
		missionscheduler_obj o = p.top();
		result.push_back(o.c);
		p.pop();

		o.times--;
		if (o.times != 0)
			q.push(o);
	}

	while (!p.empty())
	{
		if (!q.empty())
		{
			p.push(q.front());
			q.pop();
		}
		missionscheduler_obj o = p.top();
		result.push_back(o.c);
		p.pop();

		o.times--;
		if (o.times != 0)
			q.push(o);
	}

	cout << !q.empty() << endl;
	for (char c : result)
		cout << c << " " << endl;
}

void Sort_Solution::mostcources()
{
	vector<vector<int>> v = { {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
	sort(v.begin(), v.end(), comp);
	priority_queue<int> q;
	int dur = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (dur + v[i][0] <= v[i][1])
		{
			dur += v[i][0];
			q.push(v[i][0]);
		}
		else if (!q.empty() && q.top() > v[i][0])
		{
				dur += v[i][0] - q.top();
				q.pop();
				q.push(v[i][0]);
		}
	}
	cout << q.size();
}
