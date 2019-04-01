/*
* Human.cpp
*
*  Created on: Mar 31, 2019
*      Author: Alex Rivero
*/

#include "Human.h"


Human::Human(): Actor()
{
}

Human::Human(int x, int y, int health, int defense)
  :Actor(x,y,Blue,health,defense)                  // Blue color for human cell for now;
{
}

Human::~Human()
{
}

void Human::eat(Resource *cell)
{
  this->changeHealth(cell->getFood()); // casting down to a derived class in the inheretance structure
}

void Human::defend(Cell *cell)
{
  // need the code for assigning the trap to the location of the cell in the array
  // Optional implementation
  // delete array[Continent#][cell->getX()][cell->getY()];
  // arena[Continent#][cell->getX()][cell->getY()] = new Trap(cell->getX(), cell->getY(), defaultAttack);
}

void Human::move(Cell *cell)
{
  // needs to be done
  CellColor_e color = cell->getColor();

  switch(color)
  {
    case Transparent : // empty cell
      break;

    case Green:         // resource cell(can be changed)
      break;

    default:
      break;
  }

}

void Human::attack(Cell *cell) // humans only attack zombies
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

void Human::tick()
{
// needs to be done
}
