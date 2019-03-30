/*
 * ActorsForTest.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#ifndef ACTORSFORTEST_H_
#define ACTORSFORTEST_H_

#include "Actors.h"

class ActorsForTest: public Actors
{
public:
  ActorsForTest();
  ActorsForTest(int,int, CellColor_e, int, int);
  virtual ~ActorsForTest();
  void move(Cell*);
  void attack(Cell*);
};

#endif
