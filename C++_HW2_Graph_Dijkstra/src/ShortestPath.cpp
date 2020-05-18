/*
 * ShortestPath.cpp
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud
 */

#include <cassert>
#include <algorithm>
#include <iostream>

#include "ShortestPath.h"

using namespace std;

vector<int> ShortestPath::path(const Graph &graph, int src, int des)
{
	vector<int> route;

	if (dijkstra(graph, src, des) == INT_MAX)
	{
		return route;
	}

	int cur = des;
	do
	{
		route.push_back(cur);
		cur = traces[cur].src;

	} while (cur != src);

	route.push_back(src);

	reverse(route.begin(), route.end());

	return route;
}

int ShortestPath::pathSize(const Graph &graph, int src, int des)
{
	return dijkstra(graph, src, des);
}

int ShortestPath::dijkstra(const Graph &graph, int src, int des)
{

	int size = graph.getVerticeNum();
	assert(src>=0 && src<size && des>=0 && des<size);

	// initiate traces;
	traces.clear();
    traces.resize(size);

	vector<QueueNode> pqnodes={src};
	pqnodes[0].priority=0;
	PriorityQueue pQueue(pqnodes);

	traces[src].dis = 0;


	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (pQueue.size() > 0)
	{
		QueueNode top = pQueue.top();
		pQueue.pop();


		// relax path
		auto neighbors = graph.neighbors(top.ver);
		QueueNode node;
		for (int i=0; i<neighbors.size(); i++)
		{
			node.ver = neighbors[i];

				int edge = graph.getEdgeValue(top.ver, node.ver);

				if (edge + traces[top.ver].dis  < traces[node.ver].dis)
				{
					traces[node.ver].dis= edge + traces[top.ver].dis;
					traces[node.ver].src= top.ver;
					node.priority = edge + top.priority;
					pQueue.insert(node);
				}
		}
	}

	return traces[des].dis;

}

