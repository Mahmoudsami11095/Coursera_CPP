/*
 * KruskalMST.h
 *
 *  Created on: May 27, 2020
 *      Author: Mahmoud
 */

#ifndef KRUSKALMST_H_
#define KRUSKALMST_H_

#include "MinSpanTree.h"

class KruskalMST: public MinSpanTree
{
public:
	int generateMST(const Graph&, std::vector<EdgeNode>&) const;
};




#endif /* KRUSKALMST_H_ */
