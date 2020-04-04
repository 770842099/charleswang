#include "Stradegy_Solution.h"
#include "LibInclude.h"


void Stradegy_Solution::test()
{
	//transfer();
	//rate21();

	//twoCitySchedCost();

	assignBikes();
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

void Stradegy_Solution::twoCitySchedCost()
{
	vector<vector<int>> input = { {10, 20}, {30, 200}, {400, 50},{30, 20}};
	vector<vector<int>> diff;
	for (int i = 0; i < input.size(); i++)
	{		
		diff.emplace_back(vector<int>{input[i][1] - input[i][0], i});
	}
	sort(diff.begin(), diff.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0]>b[0];
	});

	int sum = 0;
	for (int i = 0; i < input.size(); i++)
		sum += input[i][1];
	for (int i = 0; i < diff.size() / 2; i++)
		sum -= diff[i][0];
	cout << sum;
}

void Stradegy_Solution::assignBikes()
{
	//vector<vector<int>> workers = { {0, 0}, {1, 1}, {2, 0} }, bikes = { {1, 0}, {2, 2}, {2, 1}};

	vector<vector<int>> workers = { {0, 0}, {1, 1}, {2, 0},{3, 0}, {4, 1}, {2, 2},{-1, 0}, {1, 3}, {-2, 0} }, 
		bikes = { {1, 0}, {2, 2}, {2, 1},{1, 0}, {2, 2}, {2, 1},{1, 0}, {2, 2}, {2, 1} };
	int n = workers.size();
	vector<int> dp(1 << n, 10000000);

	vector<vector<int>> distance(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		q.emplace(1 << i, distance[0][i]);
		dp[1 << i] = distance[0][i];
	}

	int workerNum = 1;
	while (!q.empty() && workerNum<n)
	{
		queue<pair<int, int>>qtemp;
		while (!q.empty())
		{
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
			{
				if (!(p.first & 1 << i))
				{
					int r = p.first | 1 << i;
					if (p.second + distance[workerNum][i] < dp[r])
					{
						dp[r] = p.second + distance[workerNum][i];
						qtemp.emplace(r, dp[r]);
					}
				}
			}
		}
		q = qtemp;
		workerNum++;
	}
	cout << dp[(1 << n) - 1];
}