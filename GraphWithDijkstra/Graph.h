/*
 * Graph.h
 *
 *  Created on: May 10, 2020
 *      Author: Mahmoud
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include "Graph.h"

using namespace std;
// implement graph via adjacent list
#define MAXVERTEX 100

typedef struct vertex{
	int data;
	int weight;
	struct vertex *next;
}Vertex;

class Graph
{
public:

	Graph() {}

	Graph(int verticeNum);

	Graph(int verticeNum, double density);

	int getVerticeNum() const { return verSize; }

	// tests whether there is an edge from node x to node y
	bool adjacent(int x, int y) const;

	// lists all nodes y such that there is an edge from
	// x to y
	std::vector<int> neighbors(int x) const;

	// return all vertices in the graph
	std::vector<int> getVertices() const;

	bool addEdge(int x, int y, int weight);

	bool deleteEdge(int x, int y);

	int getEdgeValue(int x, int y) const;

	void setEdgeValue(int x, int y, int value);

private:
	int  verSize; //size of Graph Vertex
	Vertex* vertexList[MAXVERTEX];
};

#endif /* GRAPH_H_ */
