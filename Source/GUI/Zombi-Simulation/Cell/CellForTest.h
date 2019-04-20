/*
 * CellForTest.h
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#ifndef CELLFORTEST_H
#define CELLFORTEST_H

#include "Cell.h"

class CellForTest : public Cell
{
public:
	CellForTest();
	CellForTest(int, int, CellColor_e, bool);
	CellForTest(int, int, CellColor_e);
	CellForTest(int, int, bool);
	CellForTest(int, int);
	virtual ~CellForTest();
	void Tick();
};

#endif /* CELLFORTEST_H */
