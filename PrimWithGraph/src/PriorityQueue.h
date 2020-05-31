/*
 * PriortyQueue.h
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <cassert>

//the element of priority queue
struct QueueNode
{
	int ver;
	int priority;

	QueueNode(int symbol=-1, int priority=INT_MAX):
		ver(symbol), priority(priority)
	{
	}
};

// an indexed priority queue implemented via minHeap
class PriorityQueue
{
public:
	PriorityQueue() {}

	PriorityQueue(const std::vector<QueueNode> &nodes );

	PriorityQueue(const std::vector<int> &ver);

	bool changePriority(const QueueNode &node);

	// delete the top node
	QueueNode pop();

	inline bool contain(QueueNode &node);

    // to get index of parent of node at index i
    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

	// if the node exists, return false, otherwise, return true
	bool insert(const QueueNode &node);

	// get the minimum node
	inline QueueNode& top();

	void deleteNode( QueueNode &node) ;

	int size() const { return minHeap.size(); }

private:
	void minHeapfy();

	void downwards(int i);

	void upwards(int i);

	// swap corresponding nodes and indices
	inline void swap(QueueNode &node1, QueueNode &node2);

	std::vector<QueueNode> minHeap;
};

QueueNode& PriorityQueue::top()
{
	assert(size() > 0);

	return minHeap[0];
}

bool PriorityQueue::contain(QueueNode &node)
{
	for (auto qNode : minHeap )
	{
		if (node.ver == qNode.ver)
		return true;
	}

	return false;
}

void PriorityQueue::swap(QueueNode &node1, QueueNode &node2)
{
	QueueNode temp = node1;
	node1=node2;
	node2=temp;
}

#endif //PRIORITY_QUEUE_H
