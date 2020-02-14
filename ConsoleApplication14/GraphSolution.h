#pragma once
#include "Graph.h"
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


class GraphSolution
{
public:
	Graph init();
	bool isCircled();
	int shortestConnected();
	bool topOrder();
	void test();
	void shortestPath();
};

