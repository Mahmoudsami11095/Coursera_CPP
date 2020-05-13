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
#include "Data.h"
#include "Graph.h"
#include "ShortestPath.h"

using namespace std;

// Driver program to test above functions
int main()
{
	// create the graph of 9 nodes with probaility of half edges
//	Graph G(9, .5);
//	vector<int> ver = G.neighbors(0);
//	for (int v:ver)
//	{
//	    cout<<v<<" ";
//	}



//	double densities[3] = {0.2, 0.4, 0.5};
//	int verticeNum = 50;
//	ShortestPath sp;
//
//	for (int i=0; i<3; i++)
//	{
//		int sum = 0;
//		int count = 0;
//		Graph graph(verticeNum, densities[i]);
//
//		for (int n=1; n<50; n++)
//		{
//			int pathSize = sp.pathSize(graph, 0, n);
//			if (pathSize != INFINITY)
//			{
//				sum += pathSize;
//				count++;
//			}
//		}
//
//		cout << "For the graph with density = " << densities[i];
//		cout << ", the average path length = " <<
//			(static_cast<double>(sum) / count) << endl;
//	}



	// create the graph of 9 nodes with probaility of half edges
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
	vernode nodes[9]={{INFINITY,0},{INFINITY,INFINITY},{INFINITY,INFINITY},{INFINITY,INFINITY},{INFINITY,INFINITY},{INFINITY,INFINITY},{INFINITY,INFINITY},{INFINITY,INFINITY},{INFINITY,INFINITY}};
	for (int j = 0 ;  j<9 ; j++ )
	{
		//get min node dist and not visited yet
		int minDis=INFINITY;
		int minInd=INFINITY;
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
					&& G.getEdgeValue(minInd,ver)  && nodes[minInd].dis != INFINITY
					&& visited[ver]== false)
			{
				nodes[ver].dis = nodes[minInd].dis + G.getEdgeValue(minInd,ver);
				nodes[ver].src = minInd;
			}
		}
	}

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

//		if (minDis< nodes[i].dis && visited[i]== false)
//		{
//			minDis=nodes[i].dis;
//			minInd=i;
//		}
//	    cout<<v<<" ";
	}

	return 0;
}

