/*
 * Zombie.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#include "Zombie.h"
#include <stdlib.h>
#include <time.h>

Zombie::Zombie(int x, int y)
	: Actor(x, y, color, defaultHealth, defaultDefense)
{
	travel = defaultTravelAmount;
	srand(time(NULL));
}

Zombie::Zombie(int x, int y, int healthValue, int defenseValue)
	: Actor(x, y, color, healthValue, defenseValue)
{
	travel = defaultTravelAmount;
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
	int randNum = rand() % 4 + 1;

	if(randNum == 1)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() - 1);
	}
	else if(randNum == 2)
	{
		this->SetNextX(this->GetX() + 1);
		this->SetNextY(this->GetY());
	}
	else if (randNum == 3)
	{
		this->SetNextX(this->GetX());
		this->SetNextY(this->GetY() + 1);
	}
	else if(randNum == 4)
	{
		this->SetNextX(this->GetX() - 1);
		this->SetNextY(this->GetY());
	}
}
