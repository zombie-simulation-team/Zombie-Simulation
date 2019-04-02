/*
* Actor.cpp
*
*  Created on: Mar 29, 2019
*      Author: Alex Rivero
*/

#include "Actor.h"

Actor::Actor()
{
	health = defense = 0;
}

Actor::Actor(int x, int y, CellColor_e color , int healthValue, int defenseValue)
	: Cell(x,y,color,true)
{
	health = healthValue;
	defense = defenseValue;
}


Actor::~Actor()
{
	health = defense = 0;
}

int Actor::GetDefense()
{
	return defense;
}

int Actor::GetHealth()
{
	return health;
}

void Actor::ChangeDefense(int value)
{
	defense += value;                 // increment or decrement defense

	if(defense > maxDefense)
	{
		defense = maxDefense;
	}
	else if(defense < minDefense)
	{
		defense = minDefense;
	}
}

void Actor::ChangeHealth(int value)
{
	health += value;                 // increment or decrement health

	if( health > maxHealth)
	{
		health = maxHealth;
	}
	else if(health < minHealth)
	{
		health = minHealth;
	}
}
