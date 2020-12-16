#include "Bit_Solution.h"
#include "LibInclude.h"

void Bit_Solution::test()
{
	//AllCombition();
	countTriplets();
}

void Bit_Solution::AllCombition()
{
	int a[5] = { 1,2,3,4,5 };

	int length = sizeof(a) / sizeof(a[0]);
	int n = 1<<length;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i & 1 << j)
				cout << a[length-j-1]<<" ";
		}
		cout << endl;
	}
}

void Bit_Solution::countTriplets()
{
	vector<int> s {2,1,3};
	vector<int> cache(1 << 16,0);
	for (int i=0;i<s.size();i++)
		for (int j = 0; j < s.size(); j++)
		{
			cache[s[i]&s[j]]++;
		}

	int total = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < (1 << 16); j++)
		{
			if (cache[j] > 0 && (j&s[i]) == 0)
				total += cache[j];
		}
	}
	cout << total;
}

long long Bit_Solution::getMaxValue(int s, vector<int> &v, vector<int> &c) {
	int middle = v.size() / 2;
	vector<pair<long long, long long>> tempv;
	int middleNum = 1 << middle;
	for (int i = 0; i < middleNum; i++) {
		pair<long long, long long> temp = getCapacity(s, 0, v, c, i);
		if (temp.first<=s)
			tempv.push_back(temp);
	}
	sort(tempv.begin(), tempv.end(), [](pair<long long, long long>&a, pair<long long, long long>&b) {
		return a.first < b.first;
	});

	vector<pair<long long, long long>> firstv;
	int curWeight = tempv[0].second;
	firstv.push_back(tempv[0]);
	for (int i = 1; i < tempv.size(); i++) {
		if (tempv[i].second <= curWeight) {
			continue;		
		}
		firstv.push_back(tempv[i]);
		curWeight = tempv[i].second;
	}

	long long maxValue = 0;
	long long secondSize = v.size() - middle;
	int secondNum = 1 << secondSize;
	for (int i = 0; i < secondNum; i++) {
		pair<long long, long long> secondValue = getCapacity(s, middle, v, c, i);
		pair<long long, long long> tempValue = secondValue;
		tempValue.first = (long long)s - tempValue.first;
		vector<pair<long long, long long>>::iterator it=upper_bound(firstv.begin(),firstv.end(), tempValue
			, [](pair<long long, long long>a, pair<long long, long long>b) {
			return a.first < b.first;}
		);
		if (it != firstv.begin()) {
			maxValue = max(maxValue, (*(--it)).second + secondValue.second);
		}
	}
	return maxValue;

}

pair<long long, long long> Bit_Solution::getCapacity(int s, int start, vector<int> &v, vector<int> &c, int num) {
	long long totalSize = 0;
	long long totalWeight = 0;
	
	int offset = 0;
	while (num != 0) {
		if (num & 1) {
			totalWeight+= v[start + offset];
			totalSize += c[start + offset];
		}
		offset++;
		num >>= 1;
	}

	return make_pair(totalSize, totalWeight);
}