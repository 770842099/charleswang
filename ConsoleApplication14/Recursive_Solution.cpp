#include "Recursive_Solution.h"
#include "LibInclude.h"


void Recursive_Solution::test()
{
	stackString();
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
