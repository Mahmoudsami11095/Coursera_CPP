/*
 * ShortestPath.h
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud
 */

#ifndef SHORTESTPATH_H_
#define SHORTESTPATH_H_

#include <vector>
#include "Graph.h"
#include "PriorityQueue.h"

// implement Dijkstra algorithm
struct traceNode {
	int src;
	int dis;
	traceNode (int src=INT_MAX ,int dis=INT_MAX ): src(src), dis(dis)
	{
	}
};

class ShortestPath
{
public:
	// find the shortest path from u to w
	std::vector<int> path(const Graph &graph, int u, int w);

	// return the path cost associated with the shortest path
	int pathSize(const Graph &graph, int u, int w);

private:
	int dijkstra(const Graph &graph, int u, int w);

	// In order to construct the shorest path, store
	// each node's previous node
	std::vector<traceNode> traces;

};

#endif // SHORTEST_PATH_H

