/*
 * Zombie.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#include "Zombie.h"

Zombie::Zombie(int x, int y, I_Random *random)
	: Actor(x, y, color, defaultHealth, defaultDefense)
{
	travel = defaultTravelAmount;
	this->random = random;
}

Zombie::Zombie(int x, int y, int healthValue, int defenseValue, I_Random *random)
	: Actor(x, y, color, healthValue, defenseValue)
{
	travel = defaultTravelAmount;
	this->random = random;
}

Zombie::~Zombie()
{
}

void Zombie::Move(Cell *cell)
{
}

void Zombie::Attack(Cell *cell)
{
}

void Zombie::Tick()
{
	int randNum = random->GenerateRandom(1,8);

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
