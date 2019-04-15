/*
* Human.cpp
*
*  Created on: Mar 31, 2019
*      Author: Alex Rivero
*/

#include "Human.h"
#include <stdlib.h>
#include <time.h>

Human::Human(int x, int y, int health, int defense, I_Random *randomGenerator)
	:Actor(x , y, color, health, defense, randomGenerator)
{
}

Human::Human(int x, int y, I_Random *randomGenerator)
  : Actor(x, y, color, humanDefaultHealth, humanDefaultDefense, randomGenerator)
{
}

Human::~Human()
{
}

void Human::Eat(Resource *cell)
{
  this->ChangeHealth(cell->GetFood()); //update human health
}

void Human::Defend(Cell *cell) {}

void Human::Attack(Cell *cell) {}

void Human::Tick()
{
	this->Move();
	this->ChangeHealth(-20);
}
