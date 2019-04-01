/*
* Human.h
*
*  Created on: Mar 31, 2019
*      Author: Alex Rivero
*/

#ifndef HUMAN_H_
#define HUMAN_H_

// humans interact with other cells
#include "Actor.h"
#include "Resource.h"
#include "Trap.h"

enum
{
  attackZombieDefense = -10,
  attackZombieHealth = -20
};

class Human: public Actor
{
private:
  void eat(Resource *cell);
	void defend(Cell *cell);

public:
  Human();
  Human(int, int, int, int);
  virtual ~Human();
  void move(Cell *cell);
  void attack(Cell *cell);
  void tick();
};

#endif
