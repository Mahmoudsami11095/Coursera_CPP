/*
 * Graph.h
 *
 *  Created on: May 10, 2020
 *      Author: Mahmoud
 */

#ifndef GRAPH_H_
#define GRAPH_H_


/*
 * Graph.c
 *
 *  Created on: May 10, 2020
 *      Author: Mahmoud
 */


#include <vector>

#include "Graph.h"
/*
using namespace std;
// implement graph via adjacent matrix
class Graph
{
public:

	Graph() {}

	Graph(int verticeNum);

	Graph(int verticeNum, double density);

	int getVerticeNum() const { return verticeNum; }

	int getEdgeNum() const { return edgeNum; }

	// tests whether there is an edge from node x to node y
	bool adjacent(int x, int y) const;

	// lists all nodes y such that there is an edge from
	// x to y
	std::vector<int> neighbors(int x) const;

	// return all vertices in the graph
	std::vector<int> getVertices() const;

	bool addEdge(int x, int y, int value);

	bool deleteEdge(int x, int y);

	int getEdgeValue(int x, int y) const;

	void setEdgeValue(int x, int y, int value);

private:
	int edgeNum;

	int verticeNum;

	std::vector<std::vector<int> > adMatrix;
};
*/

using namespace std;
// implement graph via adjacent list
#define MAXVERTEX 100

//typedef struct edge{
//	int endpoint;
//	struct edge *nextedge;
//}Edge;
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

//	int getEdgeNum() const { return edgeNum; }

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


/*
typedef struct edge{
	int endpoint;
	struct edge *nextedge;
}Edge;
typedef struct vertex{
	int entry;
	Edge *firstedge;
}Vertex;
typedef struct graphadjlistlinked{
	int n;//size
	Vertex entry[MAXVERTEX];
}Graph;
*/
/*
// stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};
// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};
class Graph{
    // insert new nodes into adjacency list from given graph
    adjNode* getAdjListNode(int value, int weight, adjNode* head)   {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head;   // point new node to current head
        return newNode;
    }
    int N;  // number of nodes in the graph
public:
    adjNode **head;                //adjacency list as array of pointers
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N)  {
        // allocate new node
        head = new adjNode*[N]();
        this->N = N;
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // construct directed graph by adding edges to it
        for (unsigned i = 0; i < n; i++)  {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            // insert in the beginning
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

                        // point head pointer to new node
            head[start_ver] = newNode;
             }
    }
      // Destructor
     ~DiaGraph() {
    for (int i = 0; i < N; i++)
        delete[] head[i];
        delete[] head;
     }
};
// print all adjacent vertices of given vertex
void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}
// graph implementation
int main()
{
    // graph edges array.
    graphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int N = 6;      // Number of vertices in the graph
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    // construct graph
    DiaGraph diagraph(edges, n, N);
    // print adjacency list representation of graph
    cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
    for (int i = 0; i < N; i++)
    {
        // display adjacent vertices of vertex i
        display_AdjList(diagraph.head[i], i);
    }
    return 0;
}
*/
