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
	nextX = -1;
	nextY = -1;
	color = Transparent;
	is_valid = true;
}

Cell::Cell(int x, int y, CellColor_e color, bool valid)
{
	xPos = x;
	yPos = y;
	nextX = -1;
	nextY = -1;
	this->color = color;
	is_valid = valid;
}

Cell::Cell(int x, int y, CellColor_e color)
{
	xPos = x;
	yPos = y;
	nextX = -1;
	nextY = -1;
	this->color = color;
	is_valid = true;
}

Cell::Cell(int x, int y, bool valid)
{
	xPos = x;
	yPos = y;
	nextX = -1;
	nextY = -1;
	is_valid = valid;

	if(is_valid)
	{
		color = Grey;
	}
	else
	{
		color = Transparent;
	}
}

Cell::Cell(int x, int y)
{
	xPos = x;
	yPos = y;
	nextX = -1;
	nextY = -1;
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

void Cell::SetNextX(int x)
{
	nextX = x;
}

void Cell::SetNextY(int y)
{
	nextY = y;
}

int Cell::GetNextX()
{
	return nextX;
}

int Cell::GetNextY()
{
	return nextY;
}

void Cell::SetColor(CellColor_e color)
{
	this->color = color;
}

bool Cell::IsValid()
{
	return is_valid;
}
bool Cell::IsLegalMove()
{

  int x = this->GetNextX();
  int y = this->GetNextY();

  return (x < 0 || x > X_LIMIT || y < 0 || y > Y_LIMIT); // LIMIT numbers come from arena size
}
