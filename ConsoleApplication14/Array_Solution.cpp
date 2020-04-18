#include "Array_Solution.h"
#include "LibInclude.h"
void Array_Solution::test()
{
	//kthLargerNumberStack();
	//slibingMaxValue();
	//MaxIncreasedSequence();

	//binarySearchEqual();
	//binarySearchBiggerEqual();
	//binarySearchBigger();

	//midNumber();

	//vector<int> nums = { 2, 4, 3, 5, 1 };
	//cout<<mergesort_and_count(nums, 0, nums.size() - 1);

	//totalSum();

	//containsSubString();

	//minFlipsMonoIncr();

	//maxEqualFreq();
	//maxFreq();

	kthLargerNumber();
}

void Array_Solution::kthLargerNumber()
{
	vector<int> a = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int k = 4;

	nth_element(a.begin(), a.begin() + k, a.end());
	cout << a[k] << endl;

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

void Array_Solution::midNumber()
{
	vector<int> v{ 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> result;

	int k = 3;
	multiset<int> multimap;
	for (int i = 0; i < k; i++)
	{
		multimap.insert(v[i]);
	}

	multiset<int>::iterator p=	multimap.begin();
	for (int i = 0; i < k / 2; i++)
		p++;
	result.push_back(*p);
	for (int i = k; i < v.size(); i++)
	{
		// Insert incoming element
		multimap.insert(v[i]);
		if (v[i] < *p)
			p--;                  // same as mid = prev(mid)

		// Remove outgoing element
		if (v[i - k] <= *p)
			p++;                  // same as mid = next(mid)

		multimap.erase(multimap.lower_bound(v[i - k]));

		result.push_back(*p);
	}

	for (int value : result)
	{
		cout << value << " ";
	}
}


int Array_Solution::mergesort_and_count(vector<int>& A, int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
		int j = mid + 1;
		for (int i = start; i <= mid; i++) {
			while (j <= end && A[i] > A[j] * 2LL)
				j++;
			count += j - (mid + 1);
		}
		merge(A, start, mid, end);
		return count;
	}
	else
		return 0;
}


void Array_Solution::merge(vector<int>& A, int start, int mid, int end)
{
	int n1 = (mid - start + 1);
	int n2 = (end - mid);
	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = A[start + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];
	int i = 0, j = 0;
	for (int k = start; k <= end; k++) {
		if (j >= n2 || (i < n1 && L[i] <= R[j]))
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

void Array_Solution::totalSum()
{
	vector<int> nums = { 1,2,3,4,5,6,7 };
	int k = 9;
	int count = 0;
	unordered_map<int, int> m;
	m[0] = 1;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		count += m[sum-k];
		if (m.count(sum) > 0)
			m[sum]++;
		else
			m[sum] = 1;
	}
	cout << count;
}

void Array_Solution::containsSubString()
{
	string s1 = "abo", s2 = "eidbaoooba";
	vector<int> nums(26, 0);
	vector<int> cur(26, 0);
	int totalMatched = 0;
	for (char c : s1)
	{
		nums[c - 'a']++;
	}

	for (int i = 0; i < s1.size(); i++)
	{
		cur[s2[i] - 'a']++;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == cur[i] && nums[i] != 0)
			totalMatched++;
	}
	int count = totalMatched==s1.size() ? 1 : 0;

	for (int i = s1.size(); i < s2.size(); i++)
	{
		cur[s2[i] - 'a']++;
		if (cur[s2[i] - 'a'] == nums[s2[i] - 'a'])
			totalMatched++;

		int pre = i - s1.size();
		if (cur[s2[pre] - 'a'] == nums[s2[pre] - 'a'])
			totalMatched--;
		cur[s2[pre] - 'a']--;

		count+= totalMatched == s1.size() ? 1 : 0;
	}
	cout << count;

}

void Array_Solution::duplicatedOrder()
{
	vector<vector<int>> overlaps;
	
	vector<vector<int>> datas{ {10, 20 },{50, 60 },{10, 40 },{5, 15 },{5, 10 },{25, 55 } };

	for (vector<int> data:datas)
	{
		for (vector<int> iv : overlaps) {
			if (iv[0] < data[1] && data[0] < iv[1]) cout << false;
		}
		for (vector<int> iv : overlaps) {
			if (iv[0] < data[1] && data[0] < iv[1])
				overlaps.emplace_back(max(data[0], iv[0]), min(data[1], iv[1]));
		}
		cout << true;
	}
}

void Array_Solution::minFlipsMonoIncr()
{
	string s = "00110";
	vector<int> pre0(s.size());
	vector<int> suffix1(s.size());
	pre0[0] = s[0] != '0';
	for (int i = 1; i < s.size(); i++)
	{
		pre0[i] = pre0[i - 1] + (s[i] != '0');
	}

	suffix1[s.size() - 1] = s[s.size() - 1] != '1';
	for (int i = s.size()-2; i>=0; i--)
	{
		suffix1[i] = suffix1[i + 1] + (s[i] != '1');
	}

	int less = 9999;
	for (int i = 0; i < s.size()-1; i++)
	{
		less = min(pre0[i] + suffix1[i + 1], less);
	}
	less = min(less, pre0[s.size() - 1]);
	cout << less;
}

void Array_Solution::maxEqualFreq()
{
	vector<int> nums = { 2, 2, 1, 1, 5, 3, 3, 5, 6 };
	vector<int> cnt(100001, 0), fre(100001, 0);    //cnt计算数字出现的频率，fre[i]=j表示有j个数字频率为i
	int maxcnt = 0, ans = 0;
	for (int i = 0; i < nums.size(); ++i) {
		int num = nums[i];
		++cnt[num];
		++fre[cnt[num]];
		maxcnt = max(maxcnt, cnt[num]);
		//第一、四种情况 || 第二种情况 （i+1就是目前的前缀数组长度）
		if ((fre[maxcnt] == 1 && 1 + fre[maxcnt - 1] * (maxcnt - 1) == i + 1) || (fre[maxcnt] * maxcnt + 1 == i + 1))
			ans = i + 1;
	}
	if (maxcnt == 1)   //第三种情况
	{
		cout << nums.size();
		return;
	}
	cout << ans;
}

void Array_Solution::maxFreq()
{
	string s = "aababcaab";
	int maxLetters = 2, minSize = 3, maxSize = 4;
	unordered_map<string, int> map;

	for (int l = minSize; l <= maxSize; l++)
	{
		int totalLetters = 0;
		vector<int> letterNum(26, 0);

		int totalLength = 0;

		if (s.size() < l)
			continue;

		for (int i = 0; i < l; i++)
		{
			if (letterNum[s[i] - 'a'] == 0)
			{
				totalLetters++;
			}
			letterNum[s[i] - 'a']++;
		}
		if (totalLetters <= maxLetters)
		{
			string letter = s.substr(0, l);
			if (map.count(letter))
				map[letter]++;
			else
				map[letter] = 1;
		}


		for (int i = l; i < s.size(); i++)
		{
			if (letterNum[s[i] - 'a'] == 0)
			{
				totalLetters++;
			}
			letterNum[s[i] - 'a']++;
			if (letterNum[s[i - l] - 'a'] == 1)
			{
				totalLetters--;
			}
			letterNum[s[i - l] - 'a']--;
			if (totalLetters <= maxLetters)
			{
				string letter = s.substr(i-l+1, l);
				if (map.count(letter))
					map[letter]++;
				else
					map[letter] = 1;
			}
		}
	}

	string mostStr="";
	int mostNum=0;
	for (pair<string, int> v : map)
	{
		if (v.second > mostNum)
			mostStr = v.first;
	}
	cout << mostStr << endl;
	cout << mostNum << endl;
}