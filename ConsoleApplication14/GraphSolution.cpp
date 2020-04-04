#include "GraphSolution.h"
#include "Graph.h"
#include <queue>
#include <limits>
#include <iostream>
#include <vector>
#include "LibInclude.h"
using namespace std;
Graph GraphSolution::init()
{
	Graph g(6);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 2, 20);
	g.addEdge(1, 3, 35);
	g.addEdge(3, 4, 30);
	g.addEdge(4, 5, 40);
	g.addEdge(5, 6, 12);
	return g;
}

void  GraphSolution::test()
{
	//topOrder();
	//shortestPath();

	//graphColoring();

	leadsToDestination();
}

bool GraphSolution::isCircled()
{
	Graph g(6);
	g.addEdge(0, 1, 10); g.addEdge(1, 2, 20); g.addEdge(1, 3, 35);
	g.addEdge(3, 4, 30); g.addEdge(4, 5, 40); 

	g.addEdge(5, 1, 10);

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	int visited[6] = { false };
	visited[0] = true;

	while (!q.empty())
	{
		pair<int, int> v = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			if (i == v.second)
				continue;
			if (g.adj[v.first][i] != INT_MAX / 4)
			{
				if (visited[i])
					return false;
				else
				{
					q.push(make_pair(i,v.first));
					visited[i] = true;
				}
			}
		}
	}
	return true;
}

int findParent(int p, int parent[])
{
	while (parent[p] != p)
		p = parent[p];
	return p;
}

void unionGroup(int parent[], int i, int j)
{
	//if (j<i)
	parent[parent[i]] = parent[j];
	//else
		//parent[parent[j]] = parent[i];
}

int GraphSolution::shortestConnected()
{
	//Graph g(6);
	//g.addEdge(0, 1, 10); g.addEdge(1, 2, 20); g.addEdge(1, 3, 20);
	//g.addEdge(3, 4, 30); g.addEdge(4, 5, 30); g.addEdge(1, 3, 35);

	vector<ConenctedEdge> v;
	v.emplace_back(0, 1, 10);
	v.emplace_back(1, 2, 20);
	v.emplace_back(1, 3, 20);
	v.emplace_back(3, 4, 30);
	v.emplace_back(4, 5, 30);
	v.emplace_back(1, 3, 10);

	sort(v.begin(), v.end());

	int parent[6];
	for (int i = 0; i < 6; i++)
	{
		parent[i] = i;
	}
	int path = 0;
	int distance = 0;
	for (auto& k : v)
	{
		if (findParent(k.from, parent) != findParent(k.to, parent))
		{
			unionGroup(parent, k.from, k.to);
			path++;
			distance += k.value;
		}
		if (path == 5)
			break;
	}

	return distance;
}

bool GraphSolution::topOrder()
{
	vector<vector<int>> gSuccess{ {5,4}, {6,4}, {4,3}, {3,1}, {4,1},{4,2},{1,0},{2,0} };
	vector<unordered_set<int>> output(7);
	vector<unordered_set<int>> input(7);

	for (auto g: gSuccess)
	{
		output[g[0]].insert(g[1]);
		input[g[1]].insert(g[0]);
	}

	queue<int> q;
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		if (output[i].size() == 0)
		{
			q.push(i);
			count++;
			cout << i << endl;
		}
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto v : input[node])
		{
			output[v].erase(node);
			if (output[v].size() == 0)
			{
				count++;
				q.push(v);
				cout << v << endl;
			}
		}
	}
	cout << (count == 7) << endl;
	return 1;
}

void GraphSolution::shortestPath()
{
	Graph g(5);
	g.addEdge(0, 4, 30);
	g.addEdge(0, 3, 10);
	g.addEdge(0, 2, 3);
	g.addEdge(0, 1, 2);
	g.addEdge(1, 2, 4);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 4, 5);

	queue<int> q;
	queue<int> q1;
	int start = 0;
	for (int i = 0; i < 5; i++)
	{
		if (i != start && g.adj[start][i] != INT_MAX / 4)
			q1.push(i);
	}
	int count = 5;
	while (!q1.empty() && count >= 0)
	{
		q = q1;
		q1 = queue<int>();

		unordered_set<int> sets;

		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (int i = 0; i < 5; i++)
			{
				if (i == node || i == start)
					continue;
				if (g.adj[start][node] + g.adj[node][i] < g.adj[start][i])
				{
					g.adj[start][i] = g.adj[start][node] + g.adj[node][i];
					if (sets.count(i) == 0)
					{
						q1.push(i);
						sets.emplace(i);
					}
				}
			}
		};
		count--;
	}
	if (count == -1)
		cout << "bad loop" << endl;
	cout << g.adj[start][4] << endl;

}

void GraphSolution::graphColoring()
{
	bool graph[4][4] = 
  { { 0, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 1, 1, 0, 1 },
	{ 1, 0, 1, 0 },
	};
	int m = 4; // Number of colors

	int color[4];
	for (int i = 0; i < 4; i++)
		color[i] = 0;
	graphColoringDetails(graph, m, color, 0);

}

void GraphSolution::graphColoringDetails(bool graph[4][4], int m, int color[], int v)
{
	if (v == 4)
	{
		for (int i = 0; i < 4; i++)
			cout << color[i] << " ";
		cout << endl;
		return;
	}

	for (int c = 1; c <= m; c++)
	{
		bool isSafe=true;
		for (int i = 0; i < 4; i++)
			if (graph[v][i] && c == color[i])
				isSafe= false;

		/* 检查颜色C到V的分配是否正确*/
		if (isSafe)
		{
			color[v] = c;
			/* 递归为其余顶点指定颜色 */
			graphColoringDetails(graph, m, color, v + 1);
			/* 如果指定颜色C不会导致解决方案然后删除它 */
			color[v] = 0;
		}
	}
}

void GraphSolution::leadsToDestination()
{
	int n = 4, source = 0, destination = 3;
	vector<vector<int>> edges = { {0, 1},{0, 3}, {1, 2}, {2, 1} };
	
	vector<vector<int>> output(n,vector<int>());
	for (vector<int> v : edges)
	{
		output[v[0]].push_back(v[1]);
	}

	vector<bool> visited(n, false);

	queue<int> q;
	q.push(source);
	visited[source] = true;

	bool matched = true;
	while (!q.empty() && matched)
	{
		int node = q.front();
		q.pop();

		if (output[node].size() == 0 && node != destination)
		{
			matched = false;
			break;
		}

		for (int next:output[node])
		{
			if (visited[next])
			{
				matched = false;
				break;
			}
			else
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
	cout << matched;
}




