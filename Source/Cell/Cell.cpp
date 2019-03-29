/*
 * Cell.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#include "Cell.h"

Cell::Cell()
{
	xPos = 0;
	yPos = 0;
	color = Transparent;
	is_valid = true;
}

Cell::Cell(int x, int y, CellColor_e c, bool valid)
{
	xPos = x;
	yPos = y;
	color = c;
	is_valid = valid;
}

Cell::Cell(int x, int y, CellColor_e c)
{
	xPos = x;
	yPos = y;
	color = c;
	is_valid = true;
}

Cell::Cell(int x, int y, bool valid)
{
	xPos = x;
	yPos = y;
	is_valid = valid;
	color = Transparent;
}

Cell::Cell(int x, int y)
{
	xPos = x;
	yPos = y;
	color = Transparent;
	is_valid = true;
}

Cell::~Cell()
{
}

int Cell::getX()
{
	return xPos;
}

int Cell::getY()
{
	return yPos;
}

CellColor_e Cell::getColor()
{
	return color;
}

void Cell::setX(int x)
{
	xPos = x;
}

void Cell::setY(int y)
{
	yPos = y;
}

void Cell::setColor(CellColor_e color)
{
	this->color = color;
}

bool Cell::isValid()
{
	return is_valid;
}
