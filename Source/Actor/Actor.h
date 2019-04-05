/*
 * Trap.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include "Cell.h"
#include "I_Random.h"

enum
{
	maxHealth = 100,
	maxDefense = 100,
	minHealth = 0,
	minDefense = 0,
	MoveUp = 1,
	MoveRightUp = 2,
	MoveRight = 3,
	MoveRightDown = 4,
	MoveDown = 5,
	MoveLeftDown = 6,
	MoveLeft = 7,
	MoveLeftUp = 8
};

class Actor: public Cell
{
private:
	int health;
	int defense;
	I_Random *randomGenerator;

public:
	Actor(
		int x,
		int y,
		CellColor_e color ,
		int healthValue,
		int defenseValue,
		I_Random *randomGenerator);
	virtual ~Actor();
	virtual void Move();
	virtual void Attack(Cell* cell) = 0;
	int GetDefense();
	int GetHealth();
	void ChangeDefense(int);
	void ChangeHealth(int);
};

#endif /* ACTOR_H_ */
