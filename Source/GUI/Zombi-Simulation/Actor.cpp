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
	currMove = 0;
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
    int nextMove;
    if(currMove == 0){
        nextMove = randomGenerator->GenerateRandom(1,8);
        currMove = nextMove;
    }else{
        currMove = currMove%8 + 1;
        nextMove = currMove;
    }


	if(nextMove == MoveUp)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() - 1);
	}
	else if(nextMove == MoveRightUp)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY() - 1);
	}
	else if (nextMove == MoveRight)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY());
	}
	else if(nextMove == MoveRightDown)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY() + 1);
	}
	else if(nextMove == MoveDown)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() + 1);
	}
	else if(nextMove == MoveLeftDown)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY() + 1);
	}
	else if(nextMove == MoveLeft)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY());
	}
	else if(nextMove == MoveLeftUp)
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
int Actor::GetCurrMove()
{
    return currMove;
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
