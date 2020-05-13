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

	struct vernode {int src;int dis;};
	bool visited[9]={false,false,false,false,false,false,false,false,false};
	vernode nodes[9]={{INT_MAX,0},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX},{INT_MAX,INT_MAX}};
	for (int j = 0 ;  j<9 ; j++ )
	{
		//get min node dist and not visited yet
		int minDis=INT_MAX;
		int minInd=INT_MAX;
		for (int i = 0 ; i<9  ;i++)
		{
			if (minDis> nodes[i].dis && visited[i]== false)
			{
				minDis=nodes[i].dis;
				minInd=i;
			}
		}
		visited[minInd]= true;
		vector<int> verNeighbors = G.neighbors(minInd);
		for (auto ver : verNeighbors)
		{
			if (nodes[ver].dis > nodes[minInd].dis + G.getEdgeValue(minInd,ver)
					&& G.getEdgeValue(minInd,ver)  && nodes[minInd].dis != INT_MAX
					&& visited[ver]== false)
			{
				nodes[ver].dis = nodes[minInd].dis + G.getEdgeValue(minInd,ver);
				nodes[ver].src = minInd;
			}
		}
	}

	//print calculated data
	for (int i = 1 ; i<9  ;i++)
	{
	    cout<<"ver "<<i<<" \nMin Distance = "<<nodes[i].dis<<endl;
	    cout<<"Path "<<i<<" <- " << nodes[i].src;

	    int src = nodes[i].src;
	    while (src!=0)
	    {
		    src = nodes[src].src;
		    cout<<" <- "<<src;
	    }
	    cout<<"\n\n";

	}

	return 0;
}

