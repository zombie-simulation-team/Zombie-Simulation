/*
 * Zombie.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#include "Zombie.h"

Zombie::Zombie(int x, int y, I_Random *randomGenerator)
	: Actor(x, y, color, defaultHealth, defaultDefense, randomGenerator)
{
	travel = defaultTravelAmount;
	this->random = random;
}

Zombie::Zombie(
		int x,
		int y,
		int healthValue,
		int defenseValue,
		I_Random *randomGenerator)
	: Actor(x, y, color, healthValue, defenseValue, randomGenerator)
{
	travel = defaultTravelAmount;
	this->random = random;
}

Zombie::~Zombie()
{
}
void Zombie::Attack(Cell *cell)
{
}

void Zombie::Tick()
{
}
