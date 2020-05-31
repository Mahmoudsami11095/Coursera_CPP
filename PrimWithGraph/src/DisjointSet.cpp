/*
 * DisjointSet.cpp
 *
 *  Created on: May 28, 2020
 *      Author: Mahmoud
 */


#include "DisjointSet.h"

using namespace std;

void DisjointSet::unionSets(int x, int y)
{
		 int i = root(x);
		 int j = root(y);

		 if (sz[i] < sz[j])
		 {
			 id[i] = j;
			 sz[j] += sz[i];
		 }
		 else
		 {
			 id[j] = i;
			 sz[i] += sz[j];
		 }
}

//check if p and q have same root
int DisjointSet::find(int x , int y)
{
	return root(x) == root(y);
}



 int DisjointSet::root(int x)
 {
 while (x != id[x])
	 {
	 id[x] = id[id[x]];
	 x = id[x];
	 }
 return x;

 /*
   	vector<int> traces;
	while (array[x] >= 0)
	{
		traces.push_back(x);
		x = array[x];
	}

	// compress the path
	for (auto itr = traces.begin(); itr != traces.end(); ++itr)
	{
		array[*itr] = x;
	}*/
 }


