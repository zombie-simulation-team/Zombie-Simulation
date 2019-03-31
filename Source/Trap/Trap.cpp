/*
 * Trap.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: javiervega
 */

#include "Trap.h"

Trap::Trap(int x, int y)
	: Obstacle(x, y, color)
{
	attack = defaultAttack;
}

Trap::Trap(int x, int y, int amount)
	: Obstacle(x, y, color)
{
	attack = amount;
}

Trap::~Trap()
{
}

void Trap::setAttack(int amount)
{
	if(amount >= minAttack && amount <= maxAttack)
	{
		attack = amount;
	}
	else if(amount > maxAttack)
	{
		attack = maxAttack;
	}
	else if(amount < minAttack)
	{
		attack = minAttack;
	}
}

int Trap::getAttack()
{
	return attack;
}

void Trap::tick()
{
	//do nothing
}

