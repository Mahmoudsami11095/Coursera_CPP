/*
 * PriorityQueue.cpp
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud
 */



#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(const vector<QueueNode> &nodes)
{
	for (int i=0; i<nodes.size(); i++)
	{
			minHeap.push_back(nodes[i]);
		    // Fix the min heap property if it is violated
			//minHeapfy();
			upwards(i);
	}
}

PriorityQueue::PriorityQueue(const vector<int> &ver)
{
	for (int i=0; i<ver.size(); i++)
	{
		    QueueNode node(ver[i]);
			minHeap.push_back(node);
		    // Fix the min heap property if it is violated
			//minHeapfy();
			upwards(i);
	}
}

bool PriorityQueue::changePriority(const QueueNode &node)
{
	int index = 0;
	// if the node does not exist, return false;
	for(index=0 ; index<minHeap.size() ; index++)
	{
		if (minHeap[index].ver == node.ver)
		{
			if (minHeap[index].priority < node.priority)
			{
				minHeap[index].priority = node.priority;
				downwards(index);
			}
			else if (minHeap[index].priority > node.priority)
			{
				minHeap[index].priority = node.priority;
				upwards(index);
			}
			return true;
		}
	}
	return false;
}

QueueNode PriorityQueue::pop()
{
	assert (size() > 0);

	QueueNode root = minHeap[0];

	QueueNode &last = minHeap.back();
	minHeap[0].ver = last.ver;
	minHeap[0].priority = last.priority;

	minHeap.pop_back();

	downwards(0);

	return root;
}

bool PriorityQueue::insert(const QueueNode &node)
{
	// if the node exists, return false;
	for (auto pqNode : minHeap)
	{
		if (pqNode.ver == node.ver)
		{
			return false;
		}
	}

	minHeap.push_back(node);

	int index = size() - 1;
	upwards(index);
	return true;
}


void PriorityQueue::deleteNode( QueueNode &node)
{
	node.priority=INT_MIN;
	changePriority(node);
    pop();
}


void PriorityQueue::upwards(int index)
{
	while (index != 0 && minHeap[parent(index)].priority > minHeap[index].priority)
    {
       swap(minHeap[index], minHeap[parent(index)]);
       index = parent(index);
    }
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void PriorityQueue::minHeapfy()
{
	// parents nodes which have children need downwards heapfy
	// this method to heapify all tree
	// just start with the parent and skip all the children (the last layer)
	int start = (size() - 2) / 2;

	for (int i=start; i>=0; i--)
	{
		downwards(i);
	}
}

void PriorityQueue::downwards(int ParentIndex)
{
    int leftIndex = left(ParentIndex);
    int rightIndex = right(ParentIndex);
    int smallestIndex = ParentIndex;

    // if there is a node exist in this index and the left child is smaller than the parent
    if (leftIndex < size() && minHeap[leftIndex].priority < minHeap[smallestIndex].priority)
    {
    	smallestIndex = leftIndex;
    }

    // if there is a node exist in this index and the right child is smaller than the parent
    if (rightIndex < size() && minHeap[rightIndex].priority < minHeap[smallestIndex].priority)
    {
    	smallestIndex = rightIndex;
    }

    if (smallestIndex != ParentIndex)
    {
        swap(minHeap[ParentIndex], minHeap[smallestIndex]);
		downwards(smallestIndex);
    }


}

