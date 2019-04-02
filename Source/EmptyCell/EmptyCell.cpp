/*
 * EmptyCell.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: javiervega
 */

#include "EmptyCell.h"

EmptyCell::EmptyCell() : Cell()
{
}

EmptyCell::EmptyCell(int x, int y, CellColor_e color, bool valid)
	: Cell(x, y, color, valid)
{
}

EmptyCell::EmptyCell(int x, int y, bool valid)
	: Cell(x, y, valid)
{
}

EmptyCell::~EmptyCell()
{

}

void EmptyCell::Tick()
{
	//do nothing
}

