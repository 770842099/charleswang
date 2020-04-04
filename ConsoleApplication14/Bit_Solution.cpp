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