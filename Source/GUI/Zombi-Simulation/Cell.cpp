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

bool Cell::IsHuman()
{
	return this->color == Green;
}

bool Cell::IsZombie()
{
	return this->color == Red;
}

bool Cell::IsResource()
{
	return this->color == White;
}

bool Cell::IsTrap()
{
	return this->color == Black;
}

bool Cell::IsEmpty()
{
	return this->color == Grey;
}

void Cell::SetPosition(int x, int y)
{
	SetX(x);
	SetY(y);
}
