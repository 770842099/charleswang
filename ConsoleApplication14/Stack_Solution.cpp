#include "Stack_Solution.h"

void Stack_Solution::test()
{
	//removeNToSmallest();
	//stockSpanner();
	sumSubarrayMins();
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

void Stack_Solution::stockSpanner()
{
	vector<int> s = { 100, 80, 60, 70, 60, 75, 85 };
	stack<pair<int,int>> stack;

    //[1, 1, 1, 2, 1, 4, 6]¡£
	vector<int> result{};

	for (int i = 0; i < s.size(); i++)
	{
		while (!stack.empty())
		{
			pair<int, int> v = stack.top();
			if (s[i] > v.first)
			{
				stack.pop();
			}
			else
			{
				result.push_back(i - v.second);
				stack.emplace(s[i], i);
				break;
			}
		}
		if (stack.empty())
		{
			result.push_back(i + 1);
			stack.emplace(s[i], i);
		}
	}

	for (int i : result)
		cout << i << " ";
}

void Stack_Solution::sumSubarrayMins()
{
	vector<int> s{ 3,1,2,4 };

	vector<int> rightMinLength (s.size());
	vector<int> leftMinLength (s.size());

	stack<pair<int, int>> rightStack;
	stack<pair<int, int>> leftStack;

	for (int i = 0; i < s.size(); i++)
	{
		while (!rightStack.empty())
		{
			pair<int, int> top = rightStack.top();
			if (top.first>s[i])
			{
				rightStack.pop();
				rightMinLength[top.second] = i - top.second;
			}
			else
			{
				rightStack.emplace(s[i], i);
				break;
			}
		}
		if (rightStack.empty())
		{
			rightStack.emplace(s[i], i);
		}
	}
	
	while (!rightStack.empty())
	{
		pair<int, int> top = rightStack.top();
		rightStack.pop();
		rightMinLength[top.second] = s.size() - top.second;
	}



	for (int i = s.size()-1; i >=0; i--)
	{
		while (!leftStack.empty())
		{
			pair<int, int> top = leftStack.top();
			if (top.first > s[i])
			{
				leftStack.pop();
				leftMinLength[top.second] = top.second-i;
			}
			else
			{
				leftStack.emplace(s[i], i);
				break;
			}
		}
		if (leftStack.empty())
		{
			leftStack.emplace(s[i], i);
		}
	}

	while (!leftStack.empty())
	{
		pair<int, int> top = leftStack.top();
		leftStack.pop();
		leftMinLength[top.second] = top.second+1;
	}

	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sum += (rightMinLength[i])*(leftMinLength[i])*s[i];
	}
	
}

