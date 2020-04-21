#include "Puzzle_Solution.h"
#include "LibInclude.h"
void Puzzle_Solution::test()
{
	//cal24();
	//hannuoTa();
	//allCalculationByBrace();

	//isPossible();

	printRectangle();
	getRectangleIndex();
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
			cout << s[0].c_str() << endl;
	}

	for (int i = 0; i < num - 1; i++)
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
			for (int j = 0; j < l - 1; j++)
			{
				for (int first : dp[i][i + j])
				{
					for (int second : dp[i + j + 1][i + l - 1])
					{
						switch (calc[i + j])
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
	for (int result : dp[0][0 + v.size() - 1])
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
	cout << "true";
}

void Puzzle_Solution::printRectangle()
{
	int n = 6;
	int direction = 1;   //1,2,3,4
	int i = 1;
	int maxLength = LibHelper::intSize(n*n) + 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cur = 0;
			int minIndex = 0;
			if (j >= i && j <= n - 1 - i)
			{
				cur = 0;
				minIndex = i;
			}
			else if (i >= (n - 1 - j) && i <= j)
			{
				cur = 1;
				minIndex = n - 1 - j;
			}
			else if (j >= (n - 1 - i) && j <= i)
			{
				cur = 2;
				minIndex = n - 1 - i;
			}
			else if (i >= j && i <= n - 1 - j)
			{
				cur = 3;
				minIndex = j;
			}

	

			int num = 1;
			int outEdge = n - 1;
			int outSize = minIndex;
			while (minIndex > 0)
			{
				num += 4 * outEdge;
				outEdge -= 2;
				minIndex--;
			}

			switch (cur)
			{
			case 0:
				num += j - i;
				break;
			case 1:
				num += outEdge + i- outSize;
				break;
			case 2:
				num += 2 * outEdge+(n-1-j-outSize);
				break;
			case 3:
				num += 3 * outEdge + (n - 1 - i - outSize);;
				break;
			}

			int space = maxLength - LibHelper::intSize(num);
			while (space > 0)
			{
				cout << " ";
				space--;
			}
			cout << num;
		}
		cout << endl;
	}
}

void Puzzle_Solution::getRectangleIndex()
{
	//i=2; j=1  n=32
	int size = 6;
	int n = 20;
	int outEdge = size - 1;
	int outsideSize = 0;
	while (n > (4*outEdge))
	{
		n -= 4 * outEdge;
		outEdge -= 2;
		outsideSize++;
	}
	if (n <= outEdge)
	{
		cout << outsideSize << " " << n + outsideSize-1;
	}
	else if (n <= 2 * outEdge)
	{
		cout << n - outEdge + outsideSize - 1 << " " << (size - 1 - outsideSize);
	}
	else if (n <= 3 * outEdge)
	{
		cout << (size - 1 - outsideSize) << " " << size- outsideSize -(n - 2*outEdge);
	}
	else
	{
		cout << (size-1-outsideSize)-(n-3*outEdge-1) << " " << outsideSize;
	}

}

void Puzzle_Solution::findRotateSteps()
{
	string ring = "ababcab", key = "acbaacba";
	
	int keyNum = key.size();
		int ringSize = ring.size();
		vector<vector<pair<int, int>>> dp(keyNum + 1);
		dp[0] = { make_pair(0,0) };

		vector<vector<int>> numPosition(26);
		for (int i = 0; i < ring.size(); i++)
		{
			numPosition[ring[i] - 'a'].push_back(i);
		}

		for (int i = 1; i <= keyNum; i++)
		{
			vector<int>& keyPos = numPosition[key[i - 1] - 'a'];
			vector<pair<int, int>> v;
			for (int j = 0; j < keyPos.size(); j++)
			{
				int pos = keyPos[j];
				int init = INT_MAX;
				for (pair<int, int> last : dp[i - 1])
				{
					int rotate = abs(last.first - pos);
					rotate = min(rotate, ringSize - rotate);
					int value = rotate + last.second;
					init = min(init, value);
				}
				v.push_back(make_pair(pos, init + 1));
			}
			dp[i] = v;
		}

		int ans = INT_MAX;
		for (pair<int, int>& v : dp[keyNum])
		{
			ans = min(ans, v.second);
		}
		return ans;
}

