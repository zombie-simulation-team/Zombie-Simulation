/*
 * Zombie.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#include "Zombie.h"

Zombie::Zombie(int x, int y)
	: Actor(x, y, color, defaultHealth, defaultDefense)
{
	travel = defaultTravelAmount;
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
}
