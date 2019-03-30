/*
 * ActorsForTest.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#include "ActorsForTest.h"

ActorsForTest::ActorsForTest(): Actors()
{
}

ActorsForTest::ActorsForTest(int x,int y, CellColor_e color, int health, int defence)
  : Actors(x,y,color,health,defence)
{
}

ActorsForTest::~ActorsForTest(){}

void ActorsForTest::move(Cell* cell)
{
  //needs development
}

void ActorsForTest::attack(Cell* cell)
{
  //neds development
}
