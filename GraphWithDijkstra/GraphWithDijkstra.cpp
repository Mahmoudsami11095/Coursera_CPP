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
// based on this graph
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
int main()
{
	// create the graph of 9 nodes
	Graph G(9);
	G.addEdge(0, 1, 4);
	G.addEdge(0, 7, 8);
	G.addEdge(1, 2, 8);
	G.addEdge(1, 7, 11);
	G.addEdge(7, 8, 7);
	G.addEdge(7, 6, 1);
	G.addEdge(8, 2, 2);
	G.addEdge(8, 6, 6);
	G.addEdge(6, 5, 2);
	G.addEdge(2, 3, 7);
	G.addEdge(2, 5, 4);
	G.addEdge(3, 5, 14);
	G.addEdge(3, 4, 9);
	G.addEdge(5, 4, 10);

	ShortestPath sp;
	for (int i = 1 ; i<9  ;i++)
	{
	    cout<<"ver "<<i<<" \nMin Distance = "<<sp.pathSize(G, 0, i)<<endl;
	    vector<int> path = sp.path(G, 0, i);

	    cout<<"Path ";
	    for(auto ver : path)
	    {
		    cout<<ver;
		    if (ver != i) { cout<<" -> ";  }
	    }
	    cout<<"\n\n";
	}

	return 0;
}

