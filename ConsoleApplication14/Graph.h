#pragma once
#include <limits>
class Graph
{
public:
	int V;    // No. of vertices 

	// adj[u][v] would be true if there is an edge 
	// from u to v, else false 
	int **adj;
public:
	Graph(int V);   // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v, int value) { adj[u][v] = value;  adj[v][u] = value; }
	void print();
};

struct ConenctedEdge
{
	int from;
	int to;
	int value;

	ConenctedEdge(int _from, int _to, int _value)
	{
		from = _from;
		to = _to;
		value = _value;
	}


	bool operator<(ConenctedEdge& second)
	{
		return value < second.value;
	}
};
