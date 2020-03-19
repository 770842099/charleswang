#include "string_solution1.h"
#include <algorithm>
#include "LibInclude.h"

void string_solution::run()
{
	//two_same_strings();

	//test_function();
	//yixuci();
	shortestContainingSubLength();
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

void string_solution::yixuci()
{
	unordered_map<string, vector<string>> m;
	string s[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	int l = sizeof(s)/sizeof(s[0]);
	for (int i = 0; i<l; i++)
	{
		string temp = s[i];
		sort(temp.begin(), temp.end());
		if (m.count(temp))
		{
			m[temp].push_back(s[i]);
		}
		else
		{
			vector<string> tv{s[i]};
			m.insert(make_pair(temp, tv));
		}
	}

	for (pair<string, vector<string>> p : m)
	{
		for (string s : p.second)
			cout << s << " ";
		cout << endl;
	}
}

void  string_solution::shortestContainingSubLength()
{
	string s = "ADOBECODEBANC", t = "ABC";

	int ans = INT_MAX;
	int needCalculated[26] = { 0 };
	int tNumbers[26] = { 0 };
	int coverredChars = 0;
	for (int i = 0; i < t.length(); i++)
	{
		needCalculated[t[i] - 'A'] = 1;
	}

	int endPos = 0;
	int startPos = 0;

	while (true)
	{
		for (; endPos < s.length(); endPos++)
		{
			if (!needCalculated[s[endPos]-'A'])
				continue;

			if (tNumbers[s[endPos]-'A']>0)
			{
				tNumbers[s[endPos] - 'A']++;
			}
			else
			{
				coverredChars++;
				tNumbers[s[endPos] - 'A'] = 1;
				if (coverredChars == t.length())
				{
					ans = min(ans, endPos - startPos + 1);
					break;
				}
			}
		}
		if (endPos == s.length())
			break;

		bool stopAfterNoCalculated = false;
		for (; startPos < endPos; startPos++)
		{
			if (!needCalculated[s[startPos]-'A'])
				continue;
			
			if (stopAfterNoCalculated)
				break;
			if (tNumbers[s[startPos] - 'A'] > 1)
			{
				tNumbers[s[startPos] - 'A']--;
			}
			else
			{
				tNumbers[s[startPos] - 'A'] = 0;
				coverredChars--;
				if (coverredChars < t.length())
				{
					endPos++;
					stopAfterNoCalculated = true;
				}
			}
		}
	}
	cout << ans;
}

void string_solution::leetCode267_CurcleString()
{
	string s = "aaaabbcccceeff";
	int locations[26];
	memset(locations, -1, 26);

	char characters[26];
	memset(characters, 0, 26);

	vector<int> numbers;
	int index=0;
	for (char c : s)
	{
		if (locations[c - 'a'] == -1)
		{
			locations[c - 'a'] = index;
			characters[index] = c;
			numbers.push_back(1);
			index++;
		}
		else
		{
			numbers[locations[c - 'a']]++;
		}		
	}

	for (int&i : numbers)
	{
		i = i / 2;
	}
	leetCode267_CurcleStringDetail("", numbers, characters);
}

void string_solution::leetCode267_CurcleStringDetail(string s, vector<int> chars, char* characters)
{
	bool ended = true;
	for (int i = 0; i < chars.size(); i++)
	{
		if (chars[i] != 0)
		{
			string temp = s;
			temp += characters[i];
			chars[i]--;
			leetCode267_CurcleStringDetail(temp, chars, characters);

			chars[i]++;
			
			ended = false;
		}
	}
	if (ended)
		cout << s << endl;
}



