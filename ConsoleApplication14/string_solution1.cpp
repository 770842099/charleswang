#include "string_solution1.h"
#include <algorithm>
#include "LibInclude.h"

void string_solution::run()
{
	//two_same_strings();

	test_function();
}


void string_solution::two_same_strings()
{
	string s1 = "abbcde";
	string s2 = "bcdefbbcde";

	int ans = 0;

	//string::npos;
	//s1 = s1.append("sdfd");

	check_two_strings(s1, s2, ans);
	check_two_strings(s2, s1, ans);

	cout << ans;
}

void string_solution::check_two_strings(string s1, string s2, int& ans)
{
	//s1 is in front of s2
	for (int s1Index = 0; s1Index < s1.length(); s1Index++)
	{
		int s2index = 0;
		int templength = 0;

		int s1Cur = s1Index;
		int s2Cur = 0;

		while (s1Cur < s1.length() && s2Cur < s2.length())
		{
			if (s1[s1Cur] == s2[s2Cur])
			{
				templength++;
				ans = max(ans, templength);
			}
			else
				templength = 0;
			s1Cur++;
			s2Cur++;
		}
	}
}

void string_solution::test_function()
{
	string aa = "a";
	string bb = "b"	;
	aa.append(bb);

	aa += '0';
	aa += to_string(1);
	cout << aa<<endl;

	string a1 = "abcdef";
	string a2 = "22";
	a1= LibHelper::replace_string(a1, "abc", "e");
	cout << a1<<endl;
}

