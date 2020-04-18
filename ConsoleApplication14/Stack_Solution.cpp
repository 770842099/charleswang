#include "Stack_Solution.h"

void Stack_Solution::test()
{
	//removeNToSmallest();
	//stockSpanner();
	//sumSubarrayMins();
	//validSubarrays();

	stackSorting();
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

void Stack_Solution::validSubarrays()
{
	vector<int> input = { 1,4,2,5,3 };
	stack<pair<int, int>> s;
	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		while (!s.empty())
		{
			if (input[i] < s.top().first)
			{
				count += i - s.top().second;
				s.pop();
			}
			else
			{
				s.emplace(input[i], i);
				break;
			}
		}
		if (s.empty())
		{
			s.emplace(input[i], i);
		}
	}
	
	while (!s.empty())
	{
		count += input.size() - s.top().second;
		s.pop();
	}
	cout << count;
}

void Stack_Solution::stackSorting()
{
	stack<int>stk;
	stk.push(4);
	stk.push(2);
	stk.push(1);
	stk.push(3);
	stack<int> tmp;
	while (!stk.empty()) {
		if (!stk.empty() && (tmp.empty() || tmp.top() >= stk.top())) {
			tmp.push(stk.top());
			stk.pop();
		}
		else {
			int value = stk.top(); stk.pop();
			while (!tmp.empty() && tmp.top() <= value) {
				stk.push(tmp.top());
				tmp.pop();
			}
			stk.push(value);
			while (!tmp.empty()) {
				stk.push(tmp.top());
				tmp.pop();
			}
		}
	}
	while (!tmp.empty()) {
		stk.push(tmp.top());
		tmp.pop();
	}


}


