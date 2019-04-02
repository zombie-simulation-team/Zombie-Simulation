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

Cell::Cell(int x, int y, CellColor_e color, bool valid)
{
	xPos = x;
	yPos = y;
	this->color = color;
	is_valid = valid;
}

Cell::Cell(int x, int y, CellColor_e color)
{
	xPos = x;
	yPos = y;
	this->color = color;
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

int Cell::GetX()
{
	return xPos;
}

int Cell::GetY()
{
	return yPos;
}

CellColor_e Cell::GetColor()
{
	return color;
}

void Cell::SetX(int x)
{
	xPos = x;
}

void Cell::SetY(int y)
{
	yPos = y;
}

void Cell::SetColor(CellColor_e color)
{
	this->color = color;
}

bool Cell::IsValid()
{
	return is_valid;
}
