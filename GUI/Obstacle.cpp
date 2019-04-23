/*
 * Obstacle.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: javiervega
 */

#include "Obstacle.h"

Obstacle::Obstacle()
{
	defense = MaxDefense;
}

Obstacle::Obstacle(int x, int y, int defense, CellColor_e color)
	: Cell(x, y, color)
{
	this->defense = defense;
}

Obstacle::Obstacle(int x, int y, CellColor_e color)
	: Cell(x, y, color)
{
	this->defense = MaxDefense;
}

Obstacle::~Obstacle()
{

}

void Obstacle::SetDefense(int amount)
{
	if(amount >= MinDefense && amount <= MaxDefense)
	{
		defense = amount;
	}
	else if(amount > MaxDefense)
	{
		defense = MaxDefense;
	}
	else if(amount < MinDefense)
	{
		defense = MinDefense;
	}
}

int Obstacle::GetDefense()
{
	return defense;
}

