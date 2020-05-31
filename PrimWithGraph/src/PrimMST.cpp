/*
 * PrimMST.cpp
 *
 *  Created on: May 26, 2020
 *      Author: Mahmoud
 */


#include "PrimMST.h"
#include "PriorityQueue.h"

using namespace std;

int PrimMST::generateMST(const Graph &G, vector<EdgeNode> &mstEdges) const
{

	 int no_edge;            // number of edge
	 int totalCost = 0;
	  // create a array to track selected vertex
	  // selected will become true otherwise false
	  vector<bool> selected(G.getVerticeNum());

	 // set selected false initially
	  for(auto ver : selected)
	  {
		  ver = false;
	  }

	 // set number of edge to 0
	  no_edge = 0;

	  // the number of egde in minimum spanning tree will be
	  // always less than (V -1), where V is number of vertices in
	  //graph

	  // choose 0th vertex and make it true
	  selected[0] = true;

	  EdgeNode edge;

	  // print for edge and weight
	  while (no_edge < G.getVerticeNum() - 1 ) {

	  //For every vertex in the set S, find the all adjacent vertices
	  // , calculate the distance from the vertex selected at step 1.
	  // if the vertex is already in the set S, discard it otherwise
	  //choose another vertex nearest to selected vertex  at step 1.

		  edge.value = INT_MAX;
	      edge.des=0;
	      edge.src=0;

	      for (int i = 0; i < G.getVerticeNum() ; i++) {
	        if (selected[i]) {
	            for (int j = 0; j < G.getVerticeNum() ; j++) {
	              if (!selected[j] && G.adjacent(i, j)) { // not in selected and there is an edge
	                  if (edge.value > G.getEdgeValue(i , j)) {
	                	  edge.value = G.getEdgeValue(i , j);
	                      edge.src = i;
	                      edge.des = j;
	                  }

	              }
	          }
	        }
	      }

	      selected[edge.des] = true;
	      mstEdges.push_back(edge);
	  	  totalCost += edge.value;
	      no_edge++;
	    }

	  return totalCost;

}

