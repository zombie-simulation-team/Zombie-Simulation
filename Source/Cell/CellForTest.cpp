/*
 * CellForTest.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#include "CellForTest.h"

CellForTest::CellForTest() : Cell()
{

}

CellForTest::CellForTest(int x, int y, CellColor_e c, bool valid)
	: Cell(x, y, c, valid)
{
}

CellForTest::CellForTest(int x, int y, CellColor_e c)
	: Cell(x, y, c)
{
}

CellForTest::CellForTest(int x, int y, bool valid)
	: Cell(x, y, valid)
{
}

CellForTest::CellForTest(int x, int y) : Cell(x, y)
{
}

CellForTest::~CellForTest() {
}

void CellForTest::Tick()
{
	//do-nothing
}

