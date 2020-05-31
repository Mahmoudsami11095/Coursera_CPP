/*
 * Graph.cpp
 *
 *  Created on: May 10, 2020
 *      Author: Mahmoud
 */
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>

#include "Graph.h"

using namespace std;


Graph::Graph(int verticeNum): verSize(verticeNum)
{
	int i = 0 ;
	if (verticeNum <= 0)
	{
		this->verSize = 0;
		return;
	}
	for (i=0 ; i<MAXVERTEX ; i++)
	{
		vertexList[i]=nullptr;
	}
}

Graph::Graph(std::istream  &inputStream)
{
	inputStream >> verSize;
	if (checkVerticeNum() == false)
	{
		return;
	}

	int i, j, value;
	while (inputStream >> i >> j >> value)
	{
		addEdge(i, j, value);
	}
}

Graph::Graph(int verticeNum, double density): verSize(verticeNum)
{
	int i=0;
	if (verticeNum <= 0)
	{
		this->verSize = 0;
		return;
	}

	for (i=0 ; i<MAXVERTEX ; i++)
	{
		vertexList[i]=nullptr;
	}

	srand(time(0));
	for (int i=0; i<verticeNum-1; i++)
	{
		for (int j=0; j<verticeNum-1; j++)
		{
			if(i != j && !adjacent(i, j))
			{
				int randNum = rand();
				double prob = (rand() % 100) / 100.0;

				if (prob < density)
				{
					int weight = randNum % 10 + 1;
					addEdge(i, j, weight); // add edge in both way
				}
			}

		}
	}
}

bool Graph::adjacent(int src, int des) const
{
	assert(src>=0 && src<verSize && des>=0 && des<verSize);

	vertex * next = vertexList[src];
	while (	next != nullptr)
	{
		if(next->data == des)
		{
			return true;
		}
		next = next->next;
	}
	return false;
}

vector<int> Graph::neighbors(int src) const
{
	assert(src>=0 && src<verSize);

	vector<int> list;
	vertex * next = vertexList[src];

	while (next !=nullptr)
	{
			list.push_back(next->data);
			next = next->next;
	}

	return list;
}

vector<int> Graph::getVertices() const
{
	vector<int> vertices;

	for (int ver=0; ver<verSize; ver++)
	{
		vertices.push_back(ver);
	}

	return vertices;
}

//add  weight
bool Graph::addEdge(int src, int des, int weight)
{
	assert(src>=0 && src<verSize && des>=0 && des<verSize);

	// check if edge is add before
	vertex * next = vertexList[src];
	while (	next != nullptr)
	{
		if(next->data == des)
		{
			return false;
		}
		next = next->next;
	}

	//add new edge
	vertex * newNode =(vertex *) malloc(sizeof(vertex));
	newNode->data=des;
	newNode->weight=weight;
	newNode->next = vertexList[src];
	vertexList[src] = newNode;

	newNode =(vertex *) malloc(sizeof(vertex));
	newNode->data=src;
	newNode->weight=weight;
	newNode->next = vertexList[des];
	vertexList[des] = newNode;

	return true;
}

//this function need to be tested
//also it can be optimized using static variable
//to delete the reversed edge using recursion
bool Graph::deleteEdge(int src, int des)
{
	assert(src>=0 && src<verSize && des>=0 && des<verSize);

	vertex * nextNode = vertexList[src];
	vertex * prevNode = nullptr;

	//check if this edge at the beginning of list
	if(vertexList[src] != nullptr )
	{
		if( vertexList[src]->data == des )
		{
			free(vertexList[src]);
			vertexList[src]=vertexList[src]->next;
		}
	}
	while (	nextNode != nullptr)
	{
		if(nextNode->data == des)
		{
			//delete first edge
			prevNode->next = nextNode->next;
			free(nextNode);

			//delete reversed edge edge
			nextNode = vertexList[des];
			vertex * prevNode = nullptr;
			//check if this edge at the beginning of list
			if(vertexList[des] != nullptr )
			{
				if( vertexList[des]->data == src )
				{
					free(vertexList[des]);
					vertexList[des]=vertexList[des]->next;
				}
			}
			while (	nextNode != nullptr)
			{
				if(nextNode->data == des)
				{
					//delete  edge
					prevNode->next = nextNode->next;
					free(nextNode);
				}
			}
			return true;
		}
		prevNode = nextNode;
		nextNode = nextNode->next;
	}

	return false;
}
/**/
int Graph::getEdgeValue(int src, int des) const
{
	assert(src>=0 && src<verSize && des>=0 && des<verSize);

	vertex * next = vertexList[src];
	while (	next != nullptr)
	{
		if(next->data == des)
		{
			return next->weight;
		}
		next = next->next;
	}
	return 0;
}

bool Graph::checkVerticeNum()
{
	int i = 0 ;
	if (verSize <= 0)
	{
		this->verSize = 0;
		return false;
	}
	for (i=0 ; i<MAXVERTEX ; i++)
	{
		vertexList[i]=nullptr;
	}
	return true;
}
