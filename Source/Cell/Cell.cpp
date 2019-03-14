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
	valid = true;
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
	return valid;
}

void Cell::setValid(bool value)
{
	valid = value;
}
