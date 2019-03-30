/*
 * Obstacle.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: javiervega
 */

#include "Obstacle.h"

Obstacle::Obstacle()
{
	defence = 0;
}

Obstacle::Obstacle(int x, int y, int defence, CellColor_e color)
	: Cell(x, y, color)
{
	this->defence = defence;
}

Obstacle::~Obstacle()
{

}

void Obstacle::setDefence(int amount)
{
	if(amount >= minDefence && amount <= maxDefence)
	{
		defence = amount;
	}
	else if(amount > maxDefence)
	{
		defence = maxDefence;
	}
	else if(amount < minDefence)
	{
		defence = minDefence;
	}
}

int Obstacle::getDefence()
{
	return defence;
}

