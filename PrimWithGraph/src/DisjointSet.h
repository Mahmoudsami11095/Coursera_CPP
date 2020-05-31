/*
 * DisjointSet.h
 *
 *  Created on: May 28, 2020
 *      Author: Mahmoud
 */

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>

class DisjointSet
{
public:
	DisjointSet() {}

	DisjointSet(int setNum): sz(setNum, 1)
	{
		 for (int i = 0; i < setNum; i++) id[i] = i;
	}

	// union 2 sets which contain x and y respectively.
	void unionSets(int x, int y);

	// find the representative element of set containing x
	int find(int x  , int y);

	int root(int x);
private:
	std::vector<int> id;
	std::vector<int> sz;

};

#endif // DISJOINT_SET_H
