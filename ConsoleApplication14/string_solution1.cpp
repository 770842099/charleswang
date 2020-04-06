#include "string_solution1.h"
#include <algorithm>
#include "LibInclude.h"

void string_solution::run()
{
	//two_same_strings();

	//test_function();
	//yixuci();
	//shortestContainingSubLength();

	//xiumStringContainsK();

	//shortestPath();
	//shortenString();

	//camelMatch();
	reverseParentheses();
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

void string_solution::maxiumStringContainsK()
{
	string s = "aabbcddbbbkaaaa";
	int k = 2;
	int length = 0;
	maxiumStringContainsKDetails(s, 0, s.length() - 1, 2, length);
	cout << length;
}

void string_solution::maxiumStringContainsKDetails(string s, int start, int end, int k, int& maxLength)
{
	vector<int> times(26, 0);
	for (int i = start; i <= end; i++)
	{
		times[s[i] - 'a']++;
	}
	unordered_set<char> unlegal;

	for (int i = 0; i < 26; i++)
	{
		if (times[i] != 0 && times[i] < k)
			unlegal.insert(i);
	}
	if (unlegal.size() == 0)
	{
		maxLength = max(maxLength, end - start + 1);
	}
	else
	{
		vector<int> unlegalLocation;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (unlegal.count(s[i]-'a') > 0)
				unlegalLocation.push_back(i);
		}
		
		for (int i = 0; i < unlegalLocation.size() - 1; i++)
		{
			if (unlegalLocation[i] + 1 != unlegalLocation[i + 1])
				maxiumStringContainsKDetails(s, unlegalLocation[i] + 1, unlegalLocation[i + 1] - 1, k, maxLength);
		}

	}
}

void  string_solution::shortestPath()
{
	vector<string> keywords{ "aabbe", "aabbf", "aacce" };
	string s = "aabce";

	vector<int> diff;
	for (string s1 : keywords)
	{
		int v = 0;
		for (int i = 0; i < s.length(); i++)
		{
			v <<= 1;
			if (s[i]!= s1[i])
				v += 1;
		}
		diff.push_back(v);
	}

	int types = 1 << s.size();
	int minValue = s.size();
	vector<int> vValue;
	for (int i = 0; i < types; i++)
	{
		int test = i;
		bool match = true;
		for (int j = 0; j < keywords.size(); j++)
		{
			if ((test & diff[j]) == 0)
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			int numof1;
			vector<int> vtemp = LibHelper::int_to_binary(i, numof1);
			if (numof1 < minValue)
			{
				vValue = vtemp;
				minValue = numof1;

				int length = vValue.size();
				for (int i = 0; i < s.size() - length; i++)
					vValue.insert(vValue.begin(), 0);
			}
		}
	}
	for (int i = 0; i < vValue.size(); i++)
		cout << vValue[i];
	cout << endl;

	int precending0 = 0;
	for (int i = 0; i < vValue.size(); i++)
	{
		if (vValue[i] == 0)
			precending0++;
		else
		{
			if (precending0 != 0)
			{
				cout << precending0;
				precending0 = 0;
			}
			cout << s[i];
		}
	}
	if (precending0 != 0)
		cout << precending0;
}

void string_solution::shortenString()
{
	string s = "abbbabbbcabbbabbbc";
	vector<vector<string>> d(s.size(), vector<string>(s.size(), ""));

	for (int len = 1; len <= s.size(); len++)
	{
		for (int i = 0; i + len-1<s.size(); i++)
		{
			int j = i + len - 1;
			string& ans = d[i][j];
			ans = s.substr(i, len);
			if (len > 5)
			{
				int p = (ans + ans).find(ans, 1);
				if (p < s.size())
				{
					ans = to_string(ans.size() / p) + "[" + d[i][i+p-1]+"]";
				}
				for (int k = i; k < j; k++)
				{
					if (d[i][k].size() + d[k + 1][j].size() < ans.size())
						ans = d[i][k] + d[k + 1][j];
				}
			}
		}
	}
	cout<< d[0][s.size() - 1];
}

void string_solution::camelMatch()
{
	vector<string> s{ "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
	string pattern = "FB";

	string temp = "FooBarTest";
	int i = 0, j = 0;
	vector<bool> removed(temp.size(), false);
	while (i < temp.size() && j < pattern.size())
	{
		if (temp[i] == pattern[j])
		{
			removed[i] = true;
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	bool result = true;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!removed[i] && temp[i] >= 'A' && temp[i] <= 'Z')
		{
			result = false;
			break;
		}
	}

	cout << result;
}

void string_solution::reverseParentheses()
{
	string s = "a(bcdefghijkl(mno)p)q";
	vector<char> vs;
	reverseParentheses_startToend(s, 0, s.size() - 1,vs);
	for (char& c : vs)
	{
		cout << c;
	}
}


void string_solution::reverseParentheses_startToend(string& s, int start, int end, vector<char>& vs)
{
	while (start <=end)
	{
		if (s[start] != '(')
			vs.push_back(s[start]);
		else
		{
			int sbegin = start + 1;
			int balance = 1;
			do
			{
				start++;
				if (s[start] == '(')
					balance++;
				else if (s[start] == ')')
					balance--;
			} while (balance != 0);
			reverseParentheses_endTostart(s, sbegin, start-1, vs);
		}

		start++;
	}
}
void string_solution::reverseParentheses_endTostart(string& s, int start, int end, vector<char>& vs)
{
	while (start <= end)
	{
		if (s[end] != ')')
			vs.push_back(s[end]);
		else
		{
			int balance = 1;
			int send = end - 1;
			do
			{
				end--;
				if (s[end] == '(')
					balance--;
				else if (s[end] == ')')
					balance++;
			} while (balance != 0);
			reverseParentheses_startToend(s, end+1, send, vs);
		}

		end--;
	}
}



