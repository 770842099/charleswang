#include "Graph.h"
#include <limits>
Graph::Graph(int V)
{
	this->V = V;

	// Create a dynamic array of pointers 
	adj = new int*[V];

	// Create a row for every pointer 
	for (int i = 0; i < V; i++)
	{
		// Note : Rows may not be contiguous 
		adj[i] = new int[V];

		// Initialize all entries as false to indicate 
		// that there are no edges initially 
		for (int j = 0; j < V; j++)
			adj[i][j] = INT_MAX / 4;
	}
}