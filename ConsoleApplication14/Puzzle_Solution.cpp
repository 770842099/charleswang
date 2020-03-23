#include "Puzzle_Solution.h"
#include "LibInclude.h"
void Puzzle_Solution::test()
{
	//cal24();
	//hannuoTa();
	//allCalculationByBrace();

	isPossible();
}

void Puzzle_Solution::cal24()
{
	float n[4] = { 13,5,6,9 };
	string s[4] = { "13","5","6","9" };
	calcDetail(n, 4, s);
}

void Puzzle_Solution::calcDetail(float a[], int num, string s[])
{
	if (num == 1)
	{
		//cout << a[0] << endl;
		if (abs(a[0] - 24) < 0.0002)
			cout << s[0].c_str()<<endl;
	}

	for (int i = 0; i < num -1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			float tempa = a[i];
			float tempb = a[j];
			string stempa = s[i];
			string stempb = s[j];
			
			float calculated;
			string scalc;
			for (int k = 0; k < 8; k++)
			{
				switch (k)
				{
				case 0:
					calculated = a[i] + a[j];
					scalc = LibHelper::string_sprintf("(%s+%s)", s[i].c_str(), s[j].c_str());
					break;
				case 1:
					calculated = a[i] - a[j];
					scalc = LibHelper::string_sprintf("(%s-%s)", s[i].c_str(), s[j].c_str());
					break;
				case 2:
					calculated = a[j] - a[j];
					scalc = LibHelper::string_sprintf("(%s-%s)", s[j].c_str(), s[i].c_str());
					break;
				case 3:
					calculated = a[i] * a[j];
					scalc = LibHelper::string_sprintf("(%s*%s)", s[i].c_str(), s[j].c_str());
					break;
				case 4:
					calculated = a[i] / a[j];
					scalc = LibHelper::string_sprintf("(%s/%s)", s[i].c_str(), s[j].c_str());
					break;
				case 5:
					calculated = a[j] + a[i];
					scalc = LibHelper::string_sprintf("(%s+%s)", s[j].c_str(), s[i].c_str());
					break;
				case 6:
					calculated = a[j] * a[i];
					scalc = LibHelper::string_sprintf("(%s*%s)", s[j].c_str(), s[i].c_str());
					break;
				case 7:
					calculated = a[j] / a[i];
					scalc = LibHelper::string_sprintf("(%s/%s)", s[j].c_str(), s[i].c_str());
					break;
				default:
					break;
				}
				a[i] = calculated;
				a[j] = a[num - 1];
				s[i] = scalc;
				s[j] = s[num - 1];
				calcDetail(a, num - 1, s);

				a[i] = tempa;
				a[j] = tempb;
				s[i] = stempa;
				s[j] = stempb;
			}
		}
	}
}

void Puzzle_Solution::hannuoTa()
{
	char s[3] = { 'a','b','c' };
	int length = sizeof(s) / sizeof(s[0]);
	hannuoTaDetail('a', 'c', s, length, 4);
}

void Puzzle_Solution::hannuoTaDetail(char start, char end, char s[], int length, int n)
{
	if (n == 0)
		return;

	unordered_set<char> set;
	for (int i = 0; i < length; i++)
	{
		set.insert(s[i]);
	}
	set.erase(start);
	set.erase(end);
	char extra = *set.begin();

	hannuoTaDetail(start, extra, s, length, n - 1);
	cout << n << " from " << start << " to " << end << endl;
	hannuoTaDetail(extra, end, s, length, n - 1);
}

void Puzzle_Solution::allCalculationByBrace()
{
	string s = "2*3-4*5";
	vector<int> v;
	vector<char> calc;
	vector<int> dp[10][10];
	int cur = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*' || s[i] == '-' || s[i] == '+')
		{
			v.push_back(cur);
			cur = 0;
			calc.push_back(s[i]);
		}
		else
		{
			cur = cur * 10 + (s[i] - '0');
		}
	}
	v.push_back(cur);

	int nums = v.size();
	for (int i = 0; i < nums; i++)
	{
		dp[i][i].push_back(v[i]);
	}

	for (int l = 2; l <= nums; l++)
	{
		for (int i = 0; i < nums - l + 1; i++)
		{
			for (int j = 0; j < l-1; j++)
			{
				for (int first : dp[i][i + j])
				{
					for (int second : dp[i + j + 1][i + l - 1])
					{
						switch (calc[i+j])
						{
						case '+':
							dp[i][i + l - 1].push_back(first + second);
							break;
						case '-':
							dp[i][i + l - 1].push_back(first - second);
							break;
						case '*':
							dp[i][i + l - 1].push_back(first * second);
							break;
						}
					}
				}
			}
		}
	}
	for (int result : dp[0][0 + v.size()-1])
	{
		cout << result << endl;
	}

}


void Puzzle_Solution::isPossible()
{
	vector<int> nums = { 1, 2, 3, 3, 4, 4, 5, 5 };
	
	unordered_map<int, int> freq, need;
	for (int num : nums) ++freq[num];
	for (int num : nums) {
		if (freq[num] == 0) continue;
		if (need[num] > 0) {
			--need[num];
			++need[num + 1];
		}
		else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
			--freq[num + 1];
			--freq[num + 2];
			++need[num + 3];
		}
		else
			cout << "false" << endl;
		--freq[num];
	}
	cout<<"true";
}
