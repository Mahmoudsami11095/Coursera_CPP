//============================================================================
// Name        : Converting_C++_Code_To_C.cpp
// Author      : Mahmoud_Sami
// Version     :
// Copyright   : Your copyright notice
// Description :  Convert this program to C++
//
// * change to C++ io
//
// * change to one line comments
//
// * change defines of constants to const
//
// * change array to vector<>
//
// * inline any short function
//
//
//============================================================================

#include <iostream>
#include <vector>

using namespace std;
//Vector Size
const int sizeVector = 40;
//Summing Function to sum elements in vector

inline void sum(int& sumVar, int size, vector<int> &d)
{
	//Iterator for looping index
	int i;
	//Accumulator for summing the Vector
	sumVar = 0;
	//Iterate on Vector
	for(i = 0; i < size; ++i)
	//Summing Elements
	sumVar = sumVar + 	d[i];
}


int main()
{
	//Iterator for looping index
	int i;
	//Accumulator for summing the Vector
	int accum = 0;
	//Vector For Data
	vector<int> data;
	//Push Data in Vector
	for(i = 0; i < sizeVector; ++i)
	{
		data.push_back(i);
	}
	//Sum Data in Vector
	sum(accum, sizeVector, data);
	//Print The Sum
	cout << "sum is \n" <<accum<< endl;

	return 0;
}
