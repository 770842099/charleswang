#include "BFS_Solution.h"
void BFS_Solution::test()
{
	shortestPathLength();
}

void BFS_Solution::shortestPathLength()
{
	vector<vector<int>> adj = { {1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2} };
	int n = 1 << adj.size();
	int end = n - 1;
	vector<pair<int, int>> curs;
	vector<vector<int>> dist(n, vector<int>(n, 0));

	for (int i = 0; i < adj.size(); i++)
	{
		curs.push_back(make_pair(1<<i, i));
		dist[1 << i][i] = 1;
	}

	for (int level = 1; !curs.empty(); level++)
	{
		vector<pair<int, int>> next;
		for (pair<int, int> cur : curs)
		{
			for (int j : adj[cur.second])
			{
				int v = cur.first | (1 << j);
				if (v == end)
				{
					cout << level + 1;
					return;
				}
				if (!dist[v][j])
				{
					dist[v][j] = 1;
					next.emplace_back(v, j);
				}
			}
		}
		curs = next;
	}
}
