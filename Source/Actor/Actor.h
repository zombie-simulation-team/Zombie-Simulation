/*
 * Trap.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include "Cell.h"

enum
{
	maxHealth = 100,
	maxDefense = 100,
	minHealth = 0,
	minDefense = 0
};

class Actor: public Cell
{
private:
	int health;
	int defense;

public:
	Actor();
	Actor(int x, int y, CellColor_e color , int healthValue, int defenseValue);
	virtual ~Actor();
	virtual void move(Cell* cell) = 0;
	virtual void attack(Cell* cell) = 0;
	int getDefense();
	int getHealth();
	void changeDefense(int);
	void changeHealth(int);
};

#endif /* ACTOR_H_ */
