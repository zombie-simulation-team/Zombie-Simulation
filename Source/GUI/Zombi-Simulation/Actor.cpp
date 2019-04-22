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
	moved = false;
	moveDirectionsIndex = 0;
	for(int i = 0; i < MoveDirectionSize; i++)
	{
		moveDirections[i] = false;
	}
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
	7   0   1
	  \ | /
	6 - C - 2
	  / | \
	5   4   3
  */
void Actor::Move()
{
	if(moveDirections[moveDirectionsIndex] == true)
	{
		for(int i = moveDirectionsIndex; i < MoveDirectionSize + moveDirectionsIndex; i++)
		{
			if(moveDirections[i % MoveDirectionSize] == false)
			{
				moveDirectionsIndex = i % MoveDirectionSize;
				break;
			}
		}

		int count = 0;
		for(int i = 0; i < MoveDirectionSize; i++)
		{
			if(moveDirections[i] == true)
			{
				count++;
			}
		}

		if(count == MoveDirectionSize)
		{
			this->ResetNextPosition();
			return;
		}
	}

	if(moveDirectionsIndex == MoveUp)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() - 1);
	}
	else if(moveDirectionsIndex == MoveRightUp)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY() - 1);
	}
	else if (moveDirectionsIndex == MoveRight)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY());
	}
	else if(moveDirectionsIndex == MoveRightDown)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY() + 1);
	}
	else if(moveDirectionsIndex == MoveDown)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() + 1);
	}
	else if(moveDirectionsIndex == MoveLeftDown)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY() + 1);
	}
	else if(moveDirectionsIndex == MoveLeft)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY());
	}
	else if(moveDirectionsIndex == MoveLeftUp)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY() - 1);
	}

	moveDirections[moveDirectionsIndex] = true;
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

bool Actor::HasMoved()
{
	return moved;
}

void Actor::SetMove(bool value)
{
	moved = value;
}

void Actor::ChangeNextMoveIndex()
{
	moveDirectionsIndex = moveDirectionsIndex % MoveDirectionSize;
}

void Actor::SetDirectionIndex(int val)
{
	moveDirectionsIndex = val;
}

void Actor::ResetDirections()
{
	moveDirectionsIndex = 0;

	for(int i = 0; i < MoveDirectionSize; i++)
	{
		moveDirections[i] = false;
	}
}
