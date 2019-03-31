/*
 * ActorForTest.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#include "ActorForTest.h"

ActorForTest::ActorForTest()
	: Actor()
{
}

ActorForTest::ActorForTest(int x,int y, CellColor_e color, int health, int defense)
	: Actor(x,y,color,health,defense)
{
}

ActorForTest::~ActorForTest(){}

void ActorForTest::move(Cell* cell)
{
	//needs development
}

void ActorForTest::attack(Cell* cell)
{
	//needs development
}

void ActorForTest::tick()
{
	//needs development
}
