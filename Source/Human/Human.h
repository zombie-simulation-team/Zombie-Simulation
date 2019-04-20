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
	void Defend(Cell *cell);
	static const CellColor_e color = Green;

public:
	Human(int x, int y, I_Random *randomGenerator);
	Human(int x, int y, int health, int defense, I_Random *randomGenerator);
	virtual ~Human();
	void Attack(Cell *cell);
	void Tick();
	void SetNextCell();
	void Eat(Resource *cell); // public for now so that it can be tested
};

#endif
