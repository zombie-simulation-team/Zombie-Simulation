/*
 * Zombie.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#include "Zombie.h"

Zombie::Zombie(int x, int y, I_Random *randomGenerator)
	: Actor(x, y, color, DefaultHealth, DefaultDefense, randomGenerator)
{
	travel = DefaultTravelAmount;
}

Zombie::Zombie(
		int x,
		int y,
		int healthValue,
		int defenseValue,
		I_Random *randomGenerator)
	: Actor(x, y, color, healthValue, defenseValue, randomGenerator)
{
	travel = DefaultTravelAmount;
}

Zombie::~Zombie()
{
}
void Zombie::Attack(Cell *cell)
{
}

void Zombie::Tick()
{
	this->Move();
	if(!this->HasMoved())
	{
		this->ChangeHealth(-10);
	}
}
