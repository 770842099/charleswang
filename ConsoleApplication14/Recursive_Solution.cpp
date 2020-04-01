#include "Recursive_Solution.h"
#include "LibInclude.h"


void Recursive_Solution::test()
{
	//stackString();

	leastOpsExpressTarget();
}

void Recursive_Solution::stackString()
{
	string s = "(ab(bcd(gh)1)2(ef)3)4";
	stack<string> storage;
	string cur = "";
	for(int index =0; index<s.size();)
	{
		if (s[index] == '(')
		{
			storage.push(cur);
			cur = "";
		}
		else if (s[index] == ')')
		{
			int times = s[++index]-'0';
			string r;
			while (times> 0)
			{
				r += cur;
				times--;
			}
			r = storage.top() + r;
			storage.pop();
			cur = r;
		}
		else
		{
			cur += s[index];
		}
		index++;
	}
	cout << cur.c_str() << endl;
}


void Recursive_Solution::leastOpsExpressTarget()
{
	unordered_map<int, int> m;
	vector<int> factValues{ 0 };
	int n = 19;
	int factor = 3;

	int sum = factor;
	while (sum < n)
	{
		factValues.push_back(sum);
		sum *= factor;
	}
	factValues.push_back(sum);

	int lessValue = 100000;

	leastOpsExpressTargetDetails(n, factor, m, factValues,lessValue, 0);
	cout << lessValue;
}


int Recursive_Solution::leastOpsExpressTargetDetails(int n, int factor, unordered_map<int, int>& m, vector<int>& factValues,
	int& lessValue, int times)
{
	if (times > lessValue)
		return 0;


	int location = lower_bound(factValues.begin(), factValues.end(), n) - factValues.begin() - 1;
	if (location == 0)
	{
		times += min(factor - n, n);
		lessValue = min(lessValue, times);
		//m[n] = times;
		return 0;
	}

	leastOpsExpressTargetDetails(n - factValues[location], factor, m, factValues, lessValue, times + location);
	leastOpsExpressTargetDetails(factValues[location + 1] - n, factor, m, factValues, lessValue, times + location + 1);
}