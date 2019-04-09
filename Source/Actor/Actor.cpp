/*
* Actor.cpp
*
*  Created on: Mar 29, 2019
*      Author: Alex Rivero
*/

#include "Actor.h"

Actor::Actor(
		int x,
		int y,
		CellColor_e color,
		int healthValue,
		int defenseValue,
		I_Random *randomGenerator)
	: Cell(x,y,color,true)
{
	health = healthValue;
	defense = defenseValue;
	this->randomGenerator = randomGenerator;
}

Actor::~Actor()
{
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
	defense += value;

	if(defense > MaxDefense)
	{
		defense = MaxDefense;
	}
	else if(defense < MinDefense)
	{
		defense = MinDefense;
	}
}

void Actor::ChangeHealth(int value)
{
	health += value;

	if( health > MaxHealth)
	{
		health = MaxHealth;
	}
	else if(health < MinHealth)
	{
		health = MinHealth;
	}
}

void Actor::Move()
{
	int randNum = randomGenerator->GenerateRandom(1,8);

	if(randNum == MoveUp)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() - 1);
	}
	else if(randNum == MoveRightUp)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY() - 1);
	}
	else if (randNum == MoveRight)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY());
	}
	else if(randNum == MoveRightDown)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY() + 1);
	}
	else if(randNum == MoveDown)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() + 1);
	}
	else if(randNum == MoveLeftDown)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY() + 1);
	}
	else if(randNum == MoveLeft)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY());
	}
	else if(randNum == MoveLeftUp)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY() - 1);
	}
}
