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

//快速排序
//void quickSort(int left, int right, vector<int>& arr)
//{
//	if (left >= right)
//		return;
//	int i, j, base, temp;
//	i = left, j = right;
//	base = arr[left];  //取最左边的数为基准数
//	while (i < j)
//	{
//		while (arr[j] >= base && i < j)
//			j--;
//		while (arr[i] <= base && i < j)
//			i++;
//		if (i < j)
//		{
//			temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//		}
//	}
//	//基准数归位
//	arr[left] = arr[i];
//	arr[i] = base;
//	quickSort(left, i - 1, arr);//递归左边
//	quickSort(i + 1, right, arr);//递归右边
//}
//
//


//归并排序
//template<typename T>
//void merge_sort_recursive(T arr[], T reg[], int start, int end) {
//	if (start >= end)
//		return;
//	int len = end - start, mid = (len >> 1) + start;
//	int start1 = start, end1 = mid;
//	int start2 = mid + 1, end2 = end;
//	merge_sort_recursive(arr, reg, start1, end1);
//	merge_sort_recursive(arr, reg, start2, end2);
//	int k = start;
//	while (start1 <= end1 && start2 <= end2)
//		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
//	while (start1 <= end1)
//		reg[k++] = arr[start1++];
//	while (start2 <= end2)
//		reg[k++] = arr[start2++];
//	for (k = start; k <= end; k++)
//		arr[k] = reg[k];
//}
//
//// merge_sort
//template<typename T>
//void merge_sort(T arr[], const int len) {
//	T reg[len];
//	merge_sort_recursive(arr, reg, 0, len - 1);
//}
