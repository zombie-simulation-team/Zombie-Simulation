/*
 * CellForTest.h
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#ifndef CELLFORTEST_H
#define CELLFORTEST_H

#include "Cell.h"

class CellForTest : public Cell {
public:
	CellForTest();
	virtual ~CellForTest();
	void tick();
};

#endif /* CELLFORTEST_H */
