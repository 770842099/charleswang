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
	shortestPath();
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

					cout << "length:" << g.adj[start][i] << " i:" << i << endl;
					q1.push(i);
				}
			}
		};
		count--;
	}
	if (count == -1)
		cout << "bad loop" << endl;
	cout << g.adj[start][4] << endl;

}

