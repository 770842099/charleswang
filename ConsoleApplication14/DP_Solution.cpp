#include "DP_Solution.h"
#include "LibInclude.h"

void DP_Solution::test()
{
	//boatCarryCarAccrossRiver();
	shortestSubStringSequence();
}

#define CARS 7
void DP_Solution::boatCarryCarAccrossRiver()
{
	int carArriveTime[CARS] = { 0,10,20,30,40,60,70 };
	int shipTime = 10;
	int maxCars = 2;

	int dp[CARS][2];
	fill(dp[0], dp[0] + CARS*2, 999999);

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
				same[i][j] = same[i-1][j-1]+a[i - 1];
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
					dp[i][j] = dp[i][j-1];
					same[i][j] = same[i][j-1];
				}
			}
		}
	}
	cout << dp[a.size()][b.size()] << endl;
	cout << same[a.size()][b.size()].c_str() << endl;
}
