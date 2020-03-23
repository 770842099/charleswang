#include "Stack_Solution.h"

void Stack_Solution::test()
{
	removeNToSmallest();
}

void Stack_Solution::removeNToSmallest()
{
	string num = "1432219";
	int k = 3;
	stack<char> s;
	int optimes = 0;
	for (char c : num)
	{
		while (!s.empty() && c < s.top() && optimes < 3)
		{
			s.pop();
			optimes++;
		}		
		s.push(c);
	}

	stack<char> reverse;
	while (!s.empty())
	{
		reverse.push(s.top());
		s.pop();
	}

	while (!reverse.empty())
	{
		cout << reverse.top();
		reverse.pop();
	}
}

