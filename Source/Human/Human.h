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
	attackZombieHealth = -20,
	humanDefaultHealth = 100,
	humanDefaultDefense = 100
};

class Human: public Actor
{
private:
	//void Eat(Resource *cell);
	void Defend(Cell *cell);

public:
	Human();
	Human(int, int);
	Human(int, int, int, int);
	virtual ~Human();
	void Move(Cell *cell);
	void Attack(Cell *cell);
	void Tick();
	void SetNextCell();
	void Eat(Resource *cell); // public for now so that it can be tested
};

#endif
