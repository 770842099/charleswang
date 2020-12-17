#include "GraphSolution.h"
#include "Graph.h"
#include "LibInclude.h"

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

	//leadsToDestination();
	//minCostToSupplyWater();

	//criticalConnections();
	//findTheCity();
	//dijkstra();

	findMinHeightTrees();
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

//并查集
int GraphSolution::findParent(int p, vector<int>& parent)
{
	if (parent[p] != parent[parent[p]])
		parent[p] = findParent(parent[p], parent);
	return parent[p];
}

void GraphSolution::unionGroup(vector<int>& parent, int i, int j)
{
	int i1 = findParent(i, parent);
	int j1= findParent(j, parent);
	if (i1!=j1)
		parent[i1] = j1;
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

	vector<int> parent(6);
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

bool GraphSolution::topOrder2()
{
	vector<int> start;
	vector<int> end;
	int n = 0;
	for (int s : start)
		n = max(n, s);
	for (int s : end)
		n = max(n, s);

	vector<vector<int>> graph(n + 1);
	vector<int> d(n + 1);
	for (int i = 0; i < start.size(); i++)
	{
		graph[start[i]].push_back(end[i]);
		d[end[i]]++;
	}

	queue<int> que;
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() && !d[i])
			que.push(i);
	}

	while (!que.empty())
	{
		int h = que.front();
		que.pop();

		for (int y : graph[h])
		{
			d[y]--;
			if (!d[y])
				que.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i])
			return true;
	}
	return false;
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

void GraphSolution::minCostToSupplyWater()
{
	int n = 3;
	vector<int> wells = { 1, 2, 2 };
	vector<vector<int>>	pipes = {{1, 2, 1}, {2, 3, 1} };

	vector<vector<pair<int,int>>> output(wells.size()+1, vector<pair<int,int>>());
	for (vector<int>& v : pipes)
	{
		output[v[0]].emplace_back(v[1], v[2]);
	}

	vector<int> shortestPath(wells.size()+1,INT32_MAX/4);
	
	queue<pair<int, int>> q;
	for (int i = 0; i < wells.size(); i++)
	{
		q.emplace(i+1, wells[i]);
		shortestPath[i+1] = wells[i];
	}

	while (!q.empty())
	{
		queue<pair<int, int>> qtemp;
		while (!q.empty())
		{
			pair<int, int> info = q.front();
			q.pop();
			int node = info.first;
			int value = info.second;

			for (pair<int, int> adj : output[node])
			{
				if (adj.second < shortestPath[adj.first])
				{
					shortestPath[adj.first] = adj.second;
				    qtemp.emplace(adj.first, adj.second);
				}
			}
		}
		q = qtemp;
	}

	int sum = 0;
	for (int i = 1; i <= wells.size(); i++)
	{
		sum += shortestPath[i];
	}
	cout << sum;
}

void GraphSolution::criticalConnections()
{
	int n = 4;
	vector<vector<int>> connections = { {0, 1},{1, 2},{2, 0},{1, 3} };

	vector<vector<int>> graph = vector<vector<int>>(n);
	vector<int> visited = vector<int>(n, 0);
	vector<int> visitTime = vector<int>(n, 0);
	vector<int> Highestparent = vector<int>(n, 0);
	vector<vector<int>> ans = vector<vector<int>>();

	for (int i = 0; i < connections.size(); i++)
	{
		graph[connections[i][0]].push_back(connections[i][1]);
		graph[connections[i][1]].push_back(connections[i][0]);
	}
	int clock = 0;
	criticalConnectionsDetails(0, -1, clock, graph, visited, visitTime, Highestparent, ans);
	for (vector<int> i : ans)
	{
		cout << i[0] << ',' << i[1] << endl;
	}
}

int GraphSolution::criticalConnectionsDetails(int node, int parent, int &clock,
	vector<vector<int>>& graph, vector<int>& visited, vector<int>& visitTime,
	vector<int>& Highestparent, vector<vector<int>>& ans)
{
	visited[node] = 1;

	// 设置 节点的访问时间 并初始化该节点能访问到的最早祖先为该节点自己
	visitTime[node] = Highestparent[node] = clock;

	for (int i = 0; i < graph[node].size(); ++i) {
		if (graph[node][i] != parent) { // 确保 dfs 是往更深处查询

			if (visited[graph[node][i]] == 0) {  // 该节点还问被访问

				// node的子节点能访问到的最早祖先, hp越小 表示 越早
				int hp = criticalConnectionsDetails(graph[node][i], node, ++clock, graph, visited, visitTime, Highestparent, ans);

				// 若该最早祖先 比 node 访问的还要早 则更新node所能访问到的最早祖先 
				// 举个例子：比如 0 -> 1 -> 2 -> 0 显然 2 可以访问到 0, 由于 2 又是 1 的子节点 则 1 定能访问到 0
				Highestparent[node] = min(Highestparent[node], hp);

				// 如果子节点 所能访问到的最早祖先 不早于 node 那么 node 与 该子节点的边 必然是关键路径
				if (hp > visitTime[node])
					ans.push_back({ node, graph[node][i] });

			}
			else // 该节点已经访问过 直接更新
				Highestparent[node] = min(Highestparent[node], Highestparent[graph[node][i]]);
		}
	}

	return Highestparent[node];
}

void GraphSolution::findTheCity()
{
	int n = 4, distanceThreshold = 4;
	vector<vector<int>> path(n, vector<int>(n, INT32_MAX / 4));
	vector<vector<int>> edges = { {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1} };
	for (int i = 0; i < edges.size(); i++)
	{
		path[edges[i][0]][edges[i][1]] = edges[i][2];
		path[edges[i][1]][edges[i][0]] = edges[i][2];
	}

	for (int k=0;k<path.size();k++)
		for (int i=0;i<path.size();i++)
			for (int j = 0; j < path.size(); j++)
			{
				if (path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];
			}

	vector<int> nums(n, 0);
	for (int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (i != j && path[i][j] <= distanceThreshold)
				nums[i]++;
		}
	int min=999999;
	int minIndex;
	for (int i = n-1; i>=0; i--)
	{
		if (nums[i] < min)
		{
			minIndex = i;
			min = nums[i];
		}
	}
	cout << minIndex;	
}

void GraphSolution::dijkstra()
{
	const int n = 5;
	int edge[5][5] =
	{
		{0,1,2,3,4},
		{1, 0, 2, 6, 4},
		{2, INT32_MAX/2, 0,3, INT32_MAX / 2},
		{3, 7, INT32_MAX / 2, 0, 1},
		{4, 5, INT32_MAX / 2, 12, 0}
	};
	int dis[n + 1];
	int book[n + 1];

	for (int i = 1; i < n; ++i)
		dis[i] = edge[0][i];

	memset(book, 0, sizeof(book));
	book[0] = 1;

	int min;
	for (int i = 1; i < n; i++)
	{
		min = INT32_MAX / 2;
		int u;
		for (int j = 1; j < n; ++j) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}

		book[u] = 1;
		for (int v = 1; v < n; ++v) {
			if (edge[u][v] < INT32_MAX / 2) {
				if (dis[v] > dis[u] + edge[u][v])
					dis[v] = dis[u] + edge[u][v];
			}
		}
	}

	for (int i = 1; i < n; ++i)
		cout << dis[i] << ' ';
}

vector<UndirectedGraphNode*> GraphSolution::createGraph(vector<vector<int>> v)
{
	vector<UndirectedGraphNode*> ans;

	unordered_map<int, UndirectedGraphNode*> map;
	for (vector<int> item : v)
	{
		UndirectedGraphNode* g = new UndirectedGraphNode(item[0]);
		map.insert(make_pair(item[0], g));
	}

	for (vector<int> item : v)
	{
		UndirectedGraphNode* g = map[item[0]];
		for (int i = 1; i < item.size(); i++)
		{
			g->neighbors.push_back(map[item[i]]);
		}
		ans.push_back(g);
	}

	return ans;
	
}

vector<int> GraphSolution::findMinHeightTrees()
{
	int n=6;
	vector<vector<int>> edges = { {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4} };
	
	vector<vector<int>> output(n);
	vector<int> inputNum(n, 0);

	for (vector<int>& v : edges)
	{
		output[v[0]].push_back(v[1]);
		output[v[1]].push_back(v[0]);

		inputNum[v[0]]++;
		inputNum[v[1]]++;
	}

	queue<int> que;
	queue<int> last;
	for (int i = 0; i < n; i++)
	{
		if (inputNum[i] == 1)
		{
			que.push(i);
			inputNum[i]--;
		}
	}
	int length = 1;
	while (!que.empty())
	{
		last = que;
		queue<int> q2;
		while (!que.empty())
		{
			int temp = que.front();
			que.pop();
			for (int& v : output[temp])
			{
				inputNum[v]--;
				if (inputNum[v] == 1)
					q2.push(v);
			}
		}
		length++;
		que = q2;
	}
	//cout << length;

	vector<int> ans;
	while (!last.empty())
	{
		ans.push_back(last.front());
		last.pop();
	}


		if (!ans.size())
		{
			vector<int> em{ 0 };
			return em;
		}
	return ans;
}

int GraphSolution::networkDelayTime(vector<vector<int>>& times, int N, int K) {
	const int INF = 0x3f3f3f3f;
	vector<int> dist(N + 1, INF); // 保存到起点的距离
	vector<bool> st(N + 1, false); // 是否最短
	typedef pair<int, int> PII;
	unordered_map<int, vector<PII>> edges; // 邻接表

	queue<int> q;
	q.push(K);
	dist[K] = 0;
	st[K] = true; // 是否在队列中

	for (auto &t : times) {
		edges[t[0]].push_back({ t[1], t[2] });
	}

	while (!q.empty()) { // 当没有点可以更新的时候，说明得到最短路
		auto t = q.front();
		q.pop();
		st[t] = false;
		for (auto &e : edges[t]) { // 更新队列中的点出发的 所有边
			int v = e.first, w = e.second;
			if (dist[v] > dist[t] + w) {
				dist[v] = dist[t] + w;
				if (!st[v]) {
					q.push(v);
					st[v] = true;
				}
			}
		}
	}
	int ans = *max_element(dist.begin() + 1, dist.end());
	return ans == INF ? -1 : ans;
}


