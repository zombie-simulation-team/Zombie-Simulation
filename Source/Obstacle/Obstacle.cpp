/*
 * Obstacle.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: javiervega
 */

#include "Obstacle.h"

Obstacle::Obstacle()
{
	defense = maxDefense;
}

Obstacle::Obstacle(int x, int y, int defense, CellColor_e color)
	: Cell(x, y, color)
{
	this->defense = defense;
}

Obstacle::Obstacle(int x, int y, CellColor_e color)
	: Cell(x, y, color)
{
	this->defense = maxDefense;
}

Obstacle::~Obstacle()
{

}

void Obstacle::SetDefense(int amount)
{
	if(amount >= minDefense && amount <= maxDefense)
	{
		defense = amount;
	}
	else if(amount > maxDefense)
	{
		defense = maxDefense;
	}
	else if(amount < minDefense)
	{
		defense = minDefense;
	}
}

int Obstacle::GetDefense()
{
	return defense;
}

