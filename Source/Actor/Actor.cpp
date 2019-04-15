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
	nextX = -1;
	nextY = -1;
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

/*
	8   1   2
	  \ | /
	7 - C - 3
	  / | \
	6   5   4
  */
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

void Actor::SetNextX(int x)
{
	nextX = x;
}

void Actor::SetNextY(int y)
{
	nextY = y;
}

int Actor::GetNextX()
{
	return nextX;
}

int Actor::GetNextY()
{
	return nextY;
}

void Actor::ResetNextPosition()
{
	nextX = -1;
	nextY = -1;
}

void Actor::SetNextPosition(int x, int y)
{
	SetNextX(x);
	SetNextY(y);
}
