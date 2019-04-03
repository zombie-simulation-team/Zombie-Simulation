/*
* Human.cpp
*
*  Created on: Mar 31, 2019
*      Author: Alex Rivero
*/

#include "Human.h"
#include <stdlib.h>
#include <time.h>

Human::Human(): Actor()
{
  srand(time(NULL));
}

Human::Human(int x, int y)
  : Actor(x, y, Blue, humanDefaultHealth, humanDefaultDefense)
{
  srand(time(NULL));
}

Human::Human(int x, int y, int health, int defense)
  :Actor(x,y,Blue,health,defense)                  // Blue color for human cell for now;
{
  srand(time(NULL));
}

Human::~Human()
{
}

void Human::Eat(Resource *cell)
{
  this->ChangeHealth(cell->GetFood()); //update human health
}

void Human::Defend(Cell *cell)
{
  // need the code for assigning the trap to the location of the cell in the array
  // Optional implementation
  // delete array[Continent#][cell->getX()][cell->getY()];
  // arena[Continent#][cell->getX()][cell->getY()] = new Trap(cell->getX(), cell->getY(), defaultAttack);
}

void Human::Move(Cell *cell)
{
  // needs to be done
  CellColor_e color = cell->GetColor();

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
// needs to be finished
  while(!(this->IsLegalMove())) // find a valid cell
  {
    this->SetNextCell();
  }

}

void Human::SetNextCell()
{
  //Posible cells to move starting from 1 on the 12 o'clock position and going clockwise
  /*
    ->origin is at upper-left corner
    ->rows increment down
    ->columns increment to the right

    8   1   2
      \ | /
    7 - C - 3
      / | \
    6   5   4

  */

  int randNumber = rand() % 7 + 1;
  switch (randNumber) {
    case 1:                             // x(row)--
      this->SetNextX(this->GetX() - 1);
      this->SetNextY(this->GetY());
      break;

    case 2:                             // x(row)-- , y(col)++
    this->SetNextX(this->GetX() - 1);
    this->SetNextY(this->GetY() + 1);
      break;

    case 3:                             // y(col)++
      this->SetNextX(this->GetX());
      this->SetNextY(this->GetY() + 1);
      break;

    case 4:                             // x(row)++ , y(col)++
      this->SetNextX(this->GetX() + 1);
      this->SetNextY(this->GetY() + 1);
      break;

    case 5:                             // x(row)++
      this->SetNextX(this->GetX() + 1);
      this->SetNextY(this->GetY());
      break;

    case 6:                             // x(row)++ , y(col)--
      this->SetNextX(this->GetX() + 1);
      this->SetNextY(this->GetY() - 1);
      break;

    case 7:                             // y(col)--
      this->SetNextX(this->GetX());
      this->SetNextY(this->GetY() - 1);
      break;

    case 8:                             // x(row)--, y(col)--
      this->SetNextX(this->GetX() - 1);
      this->SetNextY(this->GetY() - 1);
      break;

    default:                            // no change
      break;
  }
}
