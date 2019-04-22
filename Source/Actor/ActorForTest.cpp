/*
 * ActorForTest.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#include "ActorForTest.h"

ActorForTest::ActorForTest(
		int x,
		int y,
		CellColor_e color,
		int health,
		int defense,
		I_Random *randomGenerator)
	: Actor(x, y, color, health, defense, randomGenerator)
{
	this->randomGenerator = randomGenerator;
}

ActorForTest::~ActorForTest(){}

void ActorForTest::Attack(Cell* cell)
{
	//needs development
}

void ActorForTest::Tick()
{
	this->SetDirectionIndex(randomGenerator->GenerateRandom(MoveUp, MoveLeftUp));
	this->Move();
}
