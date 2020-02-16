#include "Array_Solution.h"
#include "LibInclude.h"
void Array_Solution::test()
{
	//kthLargerNumberStack();
	slibingMaxValue();
}

void Array_Solution::kthLargerNumber()
{
	vector<int> a = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int k = 4;
	cout<<kthLargerNumberDetails(a, a.size(), 0, a.size() - 1, k);
}

void Array_Solution::kthLargerNumberStack()
{
	vector<int> a = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int k = 4;
	priority_queue<int, vector<int>, greater<int>> p;
	int i = 0;
	for (; i < k; i++)
	{
		p.push(a[i]);
	}
	for (; i < a.size(); i++)
	{
		if (a[i] > p.top())
		{
			p.pop();
			p.push(a[i]);
		}
	}
	cout << p.top();
}

int Array_Solution::kthLargerNumberDetails(vector<int> a, int length, int begin, int end, int num)
{
	int first = a[begin];
	int firstIndex = begin;
	int endtemp = end;
	while (true)
	{
		while (begin<end && a[end]>first)
		{

			end--;
		}
		while (begin < end && a[begin]<=first)
		{
			begin++;
		}
		int temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
		if (begin == end)
			break;
	}

	int temp = a[firstIndex];
	a[firstIndex] = a[begin];
	a[begin] = temp;

	int curNumber = endtemp - begin;
	if (curNumber == num - 1)
		return a[firstIndex];
	else if(curNumber>num-1)
		return kthLargerNumberDetails(a, length, begin + 1, endtemp, num);
	else
	{
		return kthLargerNumberDetails(a, length, firstIndex, begin, num-curNumber);
	}
}

void Array_Solution::slibingMaxValue()
{
	vector<int> v= { 1, 3, -1, -3, 5, 3, 6, 7 };
	int k = 3;

	deque<pair<int,int>> s;

	for (int i = 0; i < v.size(); i++)
	{
		while (!s.empty() && s.back().first < v[i])
		{
			s.pop_back();
		}
		s.emplace_back(v[i], i);
		if (i>=k-1)
			cout << s.front().first<<" ";
		if (s.front().second == i - k + 1)
			s.pop_front();
	}
}