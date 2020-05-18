//============================================================================
// Name        : C++_HW2_Graph_Dijkstra.cpp
// Author      : Mahmoud_Sami
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph

#include <iostream>
#include "Graph.h"
#include "ShortestPath.h"

using namespace std;

// Driver program to test above functions
int main()
{
	//different densities to test
	double densities[] = {0.2, 0.3, 0.4, 0.5, 0.6};
	// Number of verticeNum
	int verticeNum = 50;
	//use dijkstra to get the shortest path
	ShortestPath shortestPath;

	for (auto den : densities)
	{
		int sum = 0;
		int count = 0;
		//create graph of 50 ver
		Graph graph(verticeNum, den);

		for (int ver=1; ver<verticeNum; ver++)
		{
			int pathSize = shortestPath.pathSize(graph, 0, ver);
			if (pathSize != INT_MAX)
			{
				sum += pathSize;
				count++;
			}
		}

		cout << "For the graph with density = " << den;
		cout << ", the average path length = " <<
			(static_cast<double>(sum) / count) << endl;
	}
	return 0;
}

