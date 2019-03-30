/*
 * Trap.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#ifndef ACTORS_H_
#define ACTORS_H_

#include "Cell.h"

enum
{
  maxHealth = 100,
  maxDefense = 100
};

class Actors: public Cell
{
private:
  int health;
  int defence;

public:
  Actors();
  Actors(int, int, CellColor_e, int, int);
  virtual ~Actors();
  virtual void move(Cell*) = 0;
  virtual void attack(Cell*) = 0;
  int getDefence();
  int getHealth();
  void changeDefence(int);
  void changeHealth(int);
};

#endif /* SOURCE_ACTORS_ACTORS_H_ */
