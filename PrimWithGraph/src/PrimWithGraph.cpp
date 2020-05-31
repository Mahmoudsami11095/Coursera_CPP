//============================================================================
// Name        : PrimWithGraph.cpp
// Author      : Mahmoud_Sami
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph

#include <iostream>
#include <cstring>
#include <fstream>

#include "Graph.h"
#include "PrimMST.h"
#include "KruskalMST.h"

using namespace std;

#define V 5
// Driver program to test above functions
// based on this graph
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
int main(int argc, char *argv[])
{
////	// create the graph of 9 nodes
//	Graph G(9);
////	G.addEdge(0, 1, 4);
////	G.addEdge(0, 7, 8);
////	G.addEdge(1, 2, 8);
////	G.addEdge(1, 7, 11);
////	G.addEdge(7, 8, 7);
////	G.addEdge(7, 6, 1);
////	G.addEdge(8, 2, 2);
////	G.addEdge(8, 6, 6);
////	G.addEdge(6, 5, 2);
////	G.addEdge(2, 3, 7);
////	G.addEdge(2, 5, 4);
////	G.addEdge(3, 5, 14);
////	G.addEdge(3, 4, 9);
////	G.addEdge(5, 4, 10);
//
//    G.addEdge(0, 1, 4);
//    G.addEdge(0, 7, 8);
//    G.addEdge(1, 2, 8);
//    G.addEdge(1, 7, 11);
//    G.addEdge(2, 3, 7);
//    G.addEdge(2, 8, 2);
//    G.addEdge(2, 5, 4);
//    G.addEdge(3, 4, 9);
//    G.addEdge(3, 5, 14);
//    G.addEdge(4, 5, 10);
//    G.addEdge(5, 6, 2);
//    G.addEdge(6, 7, 1);
//    G.addEdge(6, 8, 6);
//    G.addEdge(7, 8, 7);


	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " test_data_file" << endl;
		return 1;
	}

	ifstream input(argv[1]);
	Graph G(input);
	//input.close();

    PrimMST primMST;
    int mstCost = 0;
    vector<EdgeNode> primMSTree;

    mstCost = primMST.generateMST(G,primMSTree);
    for (auto node : primMSTree)
    {
   	 cout << node.src;
     cout << " -> ";
	 cout << node.des;
     cout << "  ";
	 cout << node.value;
     cout << "\n";
    }
    cout << mstCost << "\n";


    KruskalMST kruskalMST;
    vector<EdgeNode> kruskalMSTTree;

    mstCost = primMST.generateMST(G,kruskalMSTTree);
    for (auto node : kruskalMSTTree)
    {
   	 cout << node.src;
     cout << " -> ";
	 cout << node.des;
     cout << "  ";
	 cout << node.value;
     cout << "\n";
    }
    cout << mstCost;

	  return 0;

}

/*
0 -> 1  4
0 -> 7  8
7 -> 6  1
6 -> 5  2
5 -> 2  4
2 -> 8  2
2 -> 3  7
3 -> 4  9
37
0 -> 1  4
0 -> 7  8
7 -> 6  1
6 -> 5  2
5 -> 2  4
2 -> 8  2
2 -> 3  7
3 -> 4  9
37
\\\\\\\\\\\\\\\\\\\\\\\\\\
          0 - 1
          1 - 2
          2 - 3
          3 - 4
          2 - 5
          5 - 6
          6 - 7
          2 - 8
          */

