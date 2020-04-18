#include "Stradegy_Solution.h"
#include "LibInclude.h"
#include "LFUCache.h"

void Stradegy_Solution::test()
{
	//transfer();
	//rate21();

	//twoCitySchedCost();

	//assignBikes();

	//removeCoveredIntervals();

	//minTaps();
	//maxEvents();

	//fireBomb();

	//uglyNumber();

	LFU();
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

void Stradegy_Solution::removeCoveredIntervals()
{
	vector<pair<int, int>> input = {{1,4},{3,6},{2,8}};
	sort(input.begin(), input.end(), [](const pair<int,int>&a, const pair<int,int>&b) {
		return a.first < b.first;
	});

	int maxRight = input[0].first;
	for (int i = 1; i < input.size(); i++)
	{
		if (input[i].second <= maxRight)
			cout << input[i].first << " " << input[i].second << endl;

		if (input[i].second > maxRight)
			maxRight = input[i].second;
	}
}

void Stradegy_Solution::minTaps()
{
	int n = 5;
	vector<int> input = { 3, 4, 1, 1, 0, 0 };

	vector<vector<int>> ranges;
	for (int i = 0; i < input.size(); i++)
	{
		vector<int> v{ i - input[i], i + input[i], i };
		ranges.emplace_back(v);
	}
	sort(ranges.begin(), ranges.end(), [](const vector<int>&a, const vector<int>&b) {
		return a[0] < b[0];
	});

	int minRange = 0;
	int i = 0;
	int maxRange = -1;
	int maxIndex = -1;
	vector<int> mins;
	while (true)
	{
		int num = 0;
		while (i <ranges.size() && (ranges[i][0]<= minRange))
		{
			if (ranges[i][1] >= maxRange)
			{
				maxRange = ranges[i][1];
				maxIndex = ranges[i][2];
			}	
			num++;
			i++;
		}
		
		if (num == 0)
		{
			cout << "unable" << endl;
			break;
		}
		
		mins.push_back(maxIndex);
		minRange = maxRange;
		if (minRange >= input.size() - 1)
			break;
	}
	for (int&i : mins)
	{
		cout << i << " ";
	}
}

void Stradegy_Solution::maxEvents()
{
	vector<vector<int>> events = { {1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1} };
	unordered_set<int> visited;
	
	sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
		return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
	});

	for (int i = 0; i < events.size(); i++)
	{
		for (int j = events[i][0]; j <= events[i][1]; j++)
		{
			if (!visited.count(j))
			{
				visited.insert(j);
				continue;
			}
		}
	}
	cout << visited.size();
}

void Stradegy_Solution::fireBomb()
{
	vector<int> input{ 10,3,5, 4, 3, 8, 9 };
	multiset<int> set;

	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		std::multiset<int>::iterator iter=set.lower_bound(input[i]);
		if (iter == set.end())
		{
			count++;
			set.insert(input[i]);
		}
		else
		{
			set.erase(iter);
			set.insert(input[i]);
		}
	}
	cout << count;
}

void Stradegy_Solution::uglyNumber()
{
	int n = 10;
	vector<int> result;
	int index2 = 0, index3 = 0, index5 = 0;
	result.push_back(1);
	unordered_set<int> existed_set;
	existed_set.insert(1);
	for (int i = 1; i < n; i++)
	{
		while (existed_set.count(result[index2] * 2))
			index2++;
		
		while (existed_set.count(result[index3] * 3))
			index3++;

		while (existed_set.count(result[index5] * 3))
			index5++;

		int nextIndex;
		int nextValue;
		if (result[index2] * 2 < result[index3] * 3)
		{
			nextIndex = 2;
			nextValue = result[index2] * 2;
		}
		else
		{
			nextIndex = 3;
			nextValue = result[index3] * 3;
		}

		if (result[index5] * 5 < nextValue)
		{
			nextIndex = 5;
			nextValue = result[index5] * 5;
		}

		result.push_back(nextValue);
		existed_set.insert(nextValue);

		switch (nextIndex)
		{
		case 2:
			index2++;
			break;
		case 3:
			index3++;
			break;
		case 5:
			index5++;
			break;
		}
	}

	for (int i : result)
		cout << i << " ";
}

void Stradegy_Solution::LFU()
{
	LFUCache cache(3);
	cache.put(2, 2);
	cache.put(1, 1);
	cout << cache.get(2) << ",";
	cout << cache.get(1) << ",";
	cout << cache.get(2) << ",";
	cache.put(3, 3);
	cache.put(4, 4);
	cout << cache.get(3) << ",";
	cout << cache.get(2) << ",";
	cout << cache.get(1) << ",";
	cout << cache.get(4) << endl;

}
