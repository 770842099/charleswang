#include "Stradegy_Solution.h"
#include "LibInclude.h"


void Stradegy_Solution::test()
{
	transfer();
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
