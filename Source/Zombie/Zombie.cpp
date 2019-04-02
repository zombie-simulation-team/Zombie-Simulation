/*
 * Zombie.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#include "Zombie.h"
#include <stdlib.h>
#include <time.h>

Zombie::Zombie(int x, int y)
	: Actor(x, y, color, defaultHealth, defaultDefense)
{
	travel = defaultTravelAmount;
	srand(time(NULL));
}

Zombie::Zombie(int x, int y, int healthValue, int defenseValue)
	: Actor(x, y, color, healthValue, defenseValue)
{
	travel = defaultTravelAmount;
}

Zombie::~Zombie()
{
}

void Zombie::move(Cell *cell)
{
}

void Zombie::attack(Cell *cell)
{
}

void Zombie::tick()
{
	int randNum = rand() % 4 + 1;

	if(randNum == 1)
	{
		this->setNextX(this->getX());
		this->setNextY(this->getY() - 1);
	}
	else if(randNum == 2)
	{
		this->setNextX(this->getX() + 1);
		this->setNextY(this->getY());
	}
	else if (randNum == 3)
	{
		this->setNextX(this->getX());
		this->setNextY(this->getY() + 1);
	}
	else if(randNum == 4)
	{
		this->setNextX(this->getX() - 1);
		this->setNextY(this->getY());
	}
}
