#include "Stradegy_Solution.h"
#include "LibInclude.h"


void Stradegy_Solution::test()
{
	//transfer();
	rate21();
}

//leetcode 294
void Stradegy_Solution::transfer()
{
	string s = "++++++";
	map<string, bool> memo;
	memo.insert(make_pair("dfdf", 33));
	cout<<transferDetails(memo, s);
}

bool Stradegy_Solution::transferDetails(map<string, bool>& memo, string s)
{
	if (memo.find(s)!=memo.end())
		return memo[s];

	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == '+' && s[i + 1] == '+')
		{
			string t = s;
			t[i] = t[i + 1] = '-';
			if (!transferDetails(memo, t))
			{
				memo[s] = true;
				return true;
			}
		}
	}
	memo[s] = false;
	return false;
}

void Stradegy_Solution::rate21()
{
	int n = 10, k = 1, w = 10;
	vector<double> dp(max(k + w+1, n+w+1), 0);
	dp[0] = 1;
	for (int i = 0; i < k; i++)
	{
		for (int p = 1; p <= w; p++)
		{
			dp[i + p] += dp[i] * 1 / w;
		}
	}
	double sum = 0;
	for (int j = n; j <k + w; j++)
	{
		sum += dp[j];
	}
	cout << 1 - sum;
}
