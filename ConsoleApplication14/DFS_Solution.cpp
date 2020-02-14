#include "DFS_Solution.h"
#include "LibInclude.h"
void DFS_Solution::test()
{
	placePlates();
}

void DFS_Solution::placePlates()
{
	//place m to multiple level, the plates on the high level should be bigger than previous one
	stack<int> s;
	int n = 12;
	placePlatesDetails(n, s);
}

void DFS_Solution::placePlatesDetails(int n, stack<int> s)
{
	if (n == 0)
	{
		cout << endl;
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}	
		return;
	}
	int last;
	if (!s.empty())
		last = s.top();
	else
		last = n;
	for (int i = last - 1; i > 0; i--)
	{
		s.push(i);
		n -= i;
		placePlatesDetails(n, s);

		//restore
		s.pop();
		n += i;
	}
}


