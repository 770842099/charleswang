#pragma once
#include "Graph.h"
#include "LibInclude.h"
struct GraphValue {
	int from;
	int to;
	int value;

	GraphValue(int _from, int _to, int _value)
	{
		from = _from;
		to = _to;
		value = _value;
	}
};

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	UndirectedGraphNode() {};
};

class GraphSolution
{
public:
	Graph init();
	bool isCircled();
	int shortestConnected();
	bool topOrder();
	bool topOrder2();
	void test();
	void shortestPath();
	void dijkstra();

	void graphColoring();
	void graphColoringDetails(bool graph[4][4], int m, int color[], int v);

	//leetcode 1059
	void leadsToDestination();

	//leetcode 1168
	void minCostToSupplyWater();

	//leetcode 1192  tarjan
	void criticalConnections();

	int criticalConnectionsDetails(int node, int parent, int &clock, vector<vector<int>>& graph, vector<int>& visited, vector<int>& visitTime, vector<int>& Highestparent, vector<vector<int>>& ans);

	//leetcode floyid 1334
	void findTheCity();

	int findParent(int p, vector<int>& parent);
	void unionGroup(vector<int>& parent, int i, int j);

	vector<UndirectedGraphNode*> createGraph(vector<vector<int>> v);
};

