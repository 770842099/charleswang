#include "Array_Solution.h"
#include "LibInclude.h"
void Array_Solution::test()
{
	//kthLargerNumberStack();
	//slibingMaxValue();
	//MaxIncreasedSequence();

	//binarySearchEqual();
	//binarySearchBiggerEqual();
	binarySearchBigger();

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

void  Array_Solution::MaxIncreasedSequence()
{
	vector<int> n = { 10, 9, 2, 5, 3, 7, 101, 18 };
	vector<int> sequence;
	for (int i = 0; i < n.size(); i++)
	{
		int k=lower_bound(sequence.begin(), sequence.end(), n[i])-sequence.begin();
		if (k == sequence.size())
			sequence.push_back(n[i]);
		else
		{
			sequence[k] = n[i];
		}
	}
	for (int i : sequence)
	{
		cout << i << " " << endl;
	}
}

void Array_Solution::binarySearchEqual()
{
	vector<int> v = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int begin = 0;
	int end = v.size() - 1;
	int result = 6;
	sort(v.begin(), v.end());
	while (begin <= end)
	{
		int middle = (begin + end) / 2;
		if (v[middle] == result)
		{
			cout << middle;
			break;
		}
		else if (v[middle] < result)
		{
			begin = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	cout << false;
}

void Array_Solution::binarySearchBiggerEqual()
{
	vector<int> v = { 1, 2, 7, 9, 10, 20, 23, 25, 28, 30, 32, 35, 40, 100};
	int begin = 0;
	int end = v.size() - 1;
	int result = 10;
	sort(v.begin(), v.end());
	while (begin <= end)
	{
		int middle = (begin + end) / 2;
		if (v[middle] == result)
		{
			cout << middle;
			return;
		}
		else if (v[middle] < result)
		{
			begin = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	cout << begin;
}

void Array_Solution::binarySearchBigger()
{
	vector<int> v = { 1, 2, 7, 9, 10, 20, 23, 25, 28, 30, 32, 35, 40, 100 };
	int begin = 0;
	int end = v.size() - 1;
	int result = 2;
	sort(v.begin(), v.end());
	while (begin <= end)
	{
		int middle = (begin + end) / 2;

		if (v[middle] <= result)
		{
			begin = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	cout << begin;
}


int Array_Solution::bestRotation(vector<int>& A) {
	int N = A.size();
	vector<int> mark(N, 0);
	for (int i = 0; i < N; ++i) {
		int k_in = (i + 1) % N; // 得分区间入口
		int k_out = (N + i + 1 - A[i]) % N; // 得分区间出口
		++mark[k_in];
		--mark[k_out];
	}
	int res = 0;
	int score = 0;
	int max_score = INT_MIN;
	for (int i = 0; i < N; ++i) {
		score += mark[i]; // 寻找最大累计和，也就是最大重合区间数目
		if (score > max_score) {
			res = i;
			max_score = score;
		}
	}
	return res;
}
