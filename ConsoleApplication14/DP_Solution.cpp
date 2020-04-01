#include "DP_Solution.h"
#include "LibInclude.h"

void DP_Solution::test()
{
	//boatCarryCarAccrossRiver();
	//shortestSubStringSequence();

	//bag01();

	//bitDP();
	//guessNumbers();

	//ing();

	//AllArrangement();
	//maxiumnOneAndZero();

	//basicBag01();

	//removeCharacters();
	//findLongestChain1();
	//findLongestChain2();

	//largestSumOfAverages();

	//profitPlan();
	//numMusicPlaylists();

	//distinctSubseqII();
	tallestBillboard();
}

#define CARS 7
void DP_Solution::boatCarryCarAccrossRiver()
{
	int carArriveTime[CARS] = { 0,10,20,30,40,60,70 };
	int shipTime = 10;
	int maxCars = 2;

	int dp[CARS][2];
	fill(dp[0], dp[0] + CARS * 2, 999999);

	int dpShipStart[CARS];
	fill(dpShipStart, dpShipStart + CARS, 999999);

	dpShipStart[0] = 0;
	int preShip[CARS];

	for (int i = 0; i < CARS; i++)
	{
		for (int j = 0; j < maxCars; j++)
		{
			if (i + j < CARS)
			{
				dp[i + j][j] = max(dpShipStart[i], carArriveTime[i + j]) + shipTime;
			}
		}
		if (i + 1 < CARS)
		{
			for (int j = 0; j < maxCars; j++)
			{
				if (dp[i][j] != 999999)
				{
					if (dpShipStart[i + 1] > dp[i][j] + shipTime)
					{
						dpShipStart[i + 1] = dp[i][j] + shipTime;
						preShip[i + 1] = i + 1 - (j + 1);
					}
					//dpShipStart[i + 1] = min(dpShipStart[i + 1], dp[i][j] + shipTime);
				}
			}
		}
	}

	int time = 99999;
	for (int j = 0; j < maxCars; j++)
	{
		time = min(time, dp[CARS - 1][j]);
	}

	cout << time;

}

void DP_Solution::shortestSubStringSequence()
{
	string a = "aabbccdddeffffea";
	string b = "11adcdfea";
	int dp[100][100];
	string same[100][100];

	for (int i = 0; i <= a.size(); i++)
	{
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				same[i][j] = same[i - 1][j - 1] + a[i - 1];
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					same[i][j] = same[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
					same[i][j] = same[i][j - 1];
				}
			}
		}
	}
	cout << dp[a.size()][b.size()] << endl;
	cout << same[a.size()][b.size()].c_str() << endl;
}

void DP_Solution::bag01()
{
	int candidates[7] = { 10, 1, 2, 7, 6, 1, 5 };
	sort(candidates, candidates + 7);

	vector<pair<int, int>> c(7);
	int index = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || (candidates[i] != candidates[i - 1]))
		{
			if (i != 0)
				index++;
			c[index].first = candidates[i];
			c[index].second = 1;
		}
		else
		{
			c[index].second++;
		}
	}

	int dp[8][11] = { 0 };
	vector<vector<int>> s[8][11];
	
	dp[0][0] = 1;
	for (int i = 1; i <= index; i++)
	{
		for (int k = 10; k >= 0; k--)
		{
			dp[i][k] = dp[i - 1][k];
			s[i][k] = s[i - 1][k];
			for (int j = 1; j <= c[i - 1].second; j++)
			{
				if (k >= c[i - 1].first*j)
				{
					dp[i][k] += dp[i - 1][k - c[i - 1].first*j];

					if (dp[i - 1][k - c[i - 1].first*j] >= 1)
					{
						vector<vector<int>> values = s[i - 1][k - c[i - 1].first*j];
						if (values.size() > 0)
						{
							for (vector<int> value : values)
							{
								vector<int> temp = value;
								int times = j;
								while (times > 0)
								{
									temp.push_back(c[i - 1].first);
									times--;
								}
								s[i][k].push_back(temp);
							}
						}
						else
						{
							vector<int> temp;
							int times = j;
							while (times > 0)
							{
								temp.push_back(c[i - 1].first);
								times--;
							}
							s[i][k].push_back(temp);
						}
					}
				}
			}
		}
	}
	cout << dp[index][8] << endl;
	for (vector<int> v : s[index][8])
	{
		for (int v2 : v)
		{
			cout << v2 << " ";
		}
		cout << endl;
	}
}

void DP_Solution::bitDP()
{
	int pos = 0, x = 9;
	vector<int> bit(40);
	int dp[40][2];
	memset(dp, -1, sizeof(dp));
	while (x)
	{
		bit[pos++] = x % 2;
		x /= 2;
	}
	cout << bitDPDetails(pos - 1, 0, 1, bit, dp);
}

int DP_Solution::bitDPDetails(int pos, int pre, bool limit, vector<int> bit, int dp[][2])
{
	if (pos == -1) return 1;
	if (limit == 0 && dp[pos][pre] != -1) return dp[pos][pre];
	int up = limit ? bit[pos] : 1;
	int ans = 0;
	for (int i = 0; i <= up; i++)
	{
		if (pre == 1 && i == 1)
		{
			//ans+=dfs(pos-1,i,limit&&i==up);
		}
		else
		{
			ans += bitDPDetails(pos - 1, i, limit&&i == up, bit, dp);
		}
	}
	if (limit == 0) dp[pos][pre] = ans;
	return ans;
}

void  DP_Solution::guessNumbers()
{
	int n = 10;
	vector<vector<int>> dp(n+1, { vector<int>(n+1, 99999999) });
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 0;
	}

	for (int i = 2; i <=n; i++)
	{
		for (int j = 1; j <= n - i+1; j++)
		{
			dp[j][j + i - 1] = min(dp[j][j + i - 1], j + dp[j + 1][j + i - 1]);
			for (int inter = 1; inter < i-1; inter++)
			{
				dp[j][j + i - 1] = min(dp[j][j + i - 1], 
					max(
						dp[j][j + inter - 1],
						dp[j + inter + 1][j + i - 1]
					)+ j + inter);
			}
			dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][j + i - 2]+ (j + i -1));
		}
	}
	cout << dp[1][n];
}



void DP_Solution::Swing()
{
	vector<int> x = {1,17,5,10,13,15,10,5,16,8};
	vector<vector<int>> dp{ x.size(),vector<int>(2,0) };

	//up
	dp[0][0] = 1;
	//down
	dp[0][1] = 1;

	for (int i = 1; i < dp.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (x[i]> x[j])
				dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			if (x[i] < x[j])
				dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}
	}
	cout << max(dp[x.size() - 1][0], dp[x.size() - 1][1]);
}  

void  DP_Solution::AllArrangement()
{
	vector<int> s = { 1, 2, 3 };
	int target = 4;
	vector<int> dp(5,0);
	dp[0] = 1;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (i - s[j] >=0)
				dp[i] += dp[i - s[j]];
		}
	}
	cout << dp[4] << endl;
}

void DP_Solution::maxiumnOneAndZero()
{
	vector<string> arrays = { "10", "0001", "111001", "1", "0" };
	vector<pair<int, int>> numbers;
	for (string s : arrays)
	{
		pair<int, int>p(0, 0);
		for (char c : s)
		{
			if (c == '1')
				p.first++;
			else
				p.second++;
		}
		numbers.push_back(p);
	}

	int m = 3, n = 5;
	vector<vector<vector<int>>> dp(arrays.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
	for (int i = 1; i <= arrays.size(); i++)
	{
		for (int j = m; j >=1; j--)
		{
			for (int k=n; k>=1; k--)
			{
	
				dp[i][j][k] = dp[i - 1][j][k];
				
				if (j >= numbers[i-1].first && k >= numbers[i-1].second)
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j - numbers[i-1].first][k - numbers[i-1].second]+1);
			}
		}
	}
	cout << dp[arrays.size()][m][n];
}

void DP_Solution::basicBag01()
{
	vector<int> v{ 1,2,3,4,5 };
	int num = 6;
	vector<vector<int>> dp(v.size()+1, vector<int>(num+1,0));
	dp[0][0] = 1;

	for (int i = 1; i <= v.size(); i++)
	{
		for (int j = num; j >= 0; j--)
			dp[i][j] = dp[i - 1][j];
		
		for (int j = num; j >= v[i - 1]; j--)
		{
			dp[i][j] += dp[i - 1][j - v[i - 1]];
		}
	}
	cout << dp[v.size()][num];
}

void DP_Solution::removeCharacters()
{
	string s1 = "sea", s2 = "eat";
	vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
	for (int i = 0; i <= s1.size(); i++)
		dp[i][0] = i;
	for (int i = 0; i <= s2.size(); i++)
		dp[0][i] = i;

	for (int i=1; i<=s1.size();i++)
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
		}
	cout << dp[s1.size()][s2.size()];

}

void DP_Solution::findLongestChain1()
{
	vector<vector<int>> pairs = { {1, 3},{2, 3},{4, 5}, {2,4}, {6,8} };
	sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
		return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
	});
	int n = pairs.size();
	int res = 1;
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (pairs[j][1] < pairs[i][0])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res;
}

void DP_Solution::findLongestChain2()
{
	vector<vector<int>> pairs = { {1, 3},{2, 3},{4, 5}, {2,4}, {6,8} };
	sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
		return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
	});
	vector<int> dp(pairs.size());
	dp[0] = 1;
	vector<int> lastValue{ pairs[0][1] };
	for (int i = 1; i < pairs.size(); i++)
	{
		dp[i] = dp[i - 1];
		int l= lower_bound(lastValue.begin(), lastValue.end(), pairs[i][0])- lastValue.begin()-1;
		if (l >= 0)
			dp[i] = max(dp[i], dp[l]+1);
		lastValue.push_back(pairs[i][1]);
	}
	cout << dp[pairs.size() - 1];
}

void DP_Solution::largestSumOfAverages()
{
	vector<int> v{ 9, 1, 2, 3, 9 };
	int k = 3;
	vector<vector<int>> dp(v.size() + 1, vector<int>(k + 1, 0));
	vector<int> sum(v.size()+1);

	sum[0] = 0;
	for (int i = 1; i <= v.size(); i++)
	{
		sum[i] = sum[i - 1] + v[i-1];
	}

	for (int j = 1; j <= k; j++)
	{
		for (int i = j; i <= v.size(); i++)
		{
			for (int p = j-1; p < i; p++)
			{
				dp[i][j] = max(dp[i][j], dp[p][j - 1] + (sum[i] - sum[p]) / (i - p));
			}
		}
	}
	cout << dp[v.size()][k] << endl;
}

void DP_Solution::profitPlan()
{
	int G = 5, P = 3;
	vector<int> group = { 2, 2 }, profit = { 2, 3 };
		int N = profit.size();
		vector<vector<vector<long> > > dp(N + 1, vector<vector<long> >(G + 1, vector<long>(P + 1, 0)));
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= G; ++j) {
				dp[i][j][0] = 1;
			}
		}
		for (int i = 1; i <= N; ++i) {
			int g = group[i - 1];
			int p = profit[i - 1];
			for (int j = 1; j <= G; ++j) {
				for (int k = 0; k <= P; ++k) {
					dp[i][j][k] = dp[i - 1][j][k];
					if (j >= g) {
						dp[i][j][k] += dp[i - 1][j - g][max(k - p, 0)];
					}
				}
			}
		}
		cout<< dp[N][G][P];
}

void DP_Solution::numMusicPlaylists()
{
	int N = 3, L = 3, K = 1;
	vector<vector<int>> dp(L + 1, vector<int>(N + 1, 0));

	dp[0][0] = 1;
	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] += dp[i - 1][j - 1] * (N - j + 1);
			dp[i][j] += dp[i - 1][j] * max(j - K, 0);
		}
	}
	cout << dp[L + 1][N + 1];
}

void DP_Solution::distinctSubseqII()
{
	string s = "aba";
	vector<int> dp(s.size());
	vector<int> lastPosition(26, -1);
	dp[0] = 2;
	lastPosition[s[0] - 'a'] = 0;
	for (int i = 1; i < s.size(); i++)
	{
		dp[i] = 2 * dp[i - 1];
		if (lastPosition[s[i] - 'a']!=-1)
			dp[i] -= dp[lastPosition[s[i] - 'a']];
		lastPosition[s[i] - 'a'] = i;
	}
	cout << dp[s.size() - 1]--;

}
void DP_Solution::tallestBillboard()
{
	vector<int> data = { 1, 2, 3, 4, 5, 6 };
	int sum = 0;
	for (int i = 0; i < data.size(); i++)
	{
		sum += data[i];
	}
	vector<vector<int>> dp(data.size() + 1, vector<int>(sum + 1, 0));
	vector<int> visited(sum+1, false);
	visited[0] = true;
	
	for (int i = 1; i <= data.size(); i++)
	{
		vector<int> visitedTemp = visited;
		for (int j = 0; j <= sum; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if (visitedTemp[abs(j - data[i - 1])])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][abs(j - data[i - 1])] + data[i - 1]);
				visited[j] = true;
			}

			if (j + data[i - 1] <= sum && visitedTemp[j + data[i - 1]])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j + data[i - 1]] + data[i - 1]);
				visited[j] = true;
			}
		}
	}

	cout << dp[data.size()][0];
}