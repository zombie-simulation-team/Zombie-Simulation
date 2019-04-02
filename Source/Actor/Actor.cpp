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

	if(defense > actorMaxDefense)
	{
		defense = actorMaxDefense;
	}
	else if(defense < actorMinDefense)
	{
		defense = actorMinDefense;
	}
}

void Actor::ChangeHealth(int value)
{
	health += value;                 // increment or decrement health

	if( health > actorMaxHealth)
	{
		health = actorMaxHealth;
	}
	else if(health < actorMinHealth)
	{
		health = actorMinHealth;
	}
}
