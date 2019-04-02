/*
* Human.h
*
*  Created on: Mar 31, 2019
*      Author: Alex Rivero
*/

#ifndef HUMAN_H_
#define HUMAN_H_

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
	void Eat(Resource *cell);
	void Defend(Cell *cell);

public:
	Human();
	Human(int, int, int, int);
	virtual ~Human();
	void Move(Cell *cell);
	void Attack(Cell *cell);
	void Tick();
};

#endif
