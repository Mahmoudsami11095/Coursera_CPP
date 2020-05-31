/*
 * KruskalMST.cpp
 *,
 *  Created on: May 27, 2020
 *      Author: Mahmoud
 */


#include "KruskalMST.h"
#include "PriorityQueue.h"
#include "DisjointSet.h"
#include "algorithm"

using namespace std;

bool cmp(const EdgeNode &a, const EdgeNode &b)
{
	return a.value < b.value;
}

int KruskalMST::generateMST(const Graph &G, vector<EdgeNode> &mstEdges) const
{
	// 1-Edge Sorting
	vector<EdgeNode> edges;
	for (int i=0; i < G.getVerticeNum()-1; i++)
	{
		//need to be optimized ( only loop for nabour )
		for (int j=i+1; j<G.getVerticeNum(); j++)
		{
			if (G.adjacent(i, j))
			{
				edges.push_back(EdgeNode(i, j, G.getEdgeValue(i,j)));
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);

	// 2-Create Set
	DisjointSet sets(G.getVerticeNum());

	int n = 0;
	int totalCost = 0;
	while (mstEdges.size() != G.getVerticeNum()-1 && n < edges.size())
	{
		if (sets.find(edges[n].src,edges[n].des))
		{
			totalCost += edges[n].value;
			mstEdges.push_back(edges[n]);
			sets.unionSets(edges[n].src,edges[n].des);
		}
		n++;
	}
	  return totalCost;

}




