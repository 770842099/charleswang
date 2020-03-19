#include "DP_Solution.h"
#include "LibInclude.h"

void DP_Solution::test()
{
	//boatCarryCarAccrossRiver();
	//shortestSubStringSequence();

	//bag01();

	bitDP();
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
