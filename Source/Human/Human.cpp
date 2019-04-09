/*
* Human.cpp
*
*  Created on: Mar 31, 2019
*      Author: Alex Rivero
*/

#include "Human.h"

Human::Human(int x, int y, int health, int defense, I_Random *randomGenerator)
	:Actor(x,y,Blue,health,defense, randomGenerator)
{
}

Human::~Human()
{
}

void Human::Eat(Resource *cell)
{
  this->ChangeHealth(cell->GetFood()); // casting down to a derived class in the inheretance structure
}

void Human::Defend(Cell *cell)
{
  // need the code for assigning the trap to the location of the cell in the array
  // Optional implementation
  // delete array[Continent#][cell->getX()][cell->getY()];
  // arena[Continent#][cell->getX()][cell->getY()] = new Trap(cell->getX(), cell->getY(), defaultAttack);
}

void Human::Attack(Cell *cell) // humans only attack zombies
{
  // needs more stuff after logic class is done
  // optional implementation
  // if(cell->getDefense() != 0) // zombie can defend itself still
  // {
  //   cell->changeDefense(attackZombieDefense)
  // }
  // else                        //zombie is defenseless
  // {
  //   cell->changeHealth(attackZombieHealth);
  // }
  //
  // if(cell->getHealth() == 0)  //zombie died
  // {

  // int x = cell->getX();
  // int y = cell->getY();
  // delete arena[Continent#][x][y]
  // arena[Continent#][x][y]  = new EmptyCell(x,y,color,true);
  // }
}

void Human::Tick()
{
// needs to be done
}
