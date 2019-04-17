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
#include "Utils.h"

enum
{
	ActorMaxHealth = 100,
	ActorMaxDefense = 100,
	ActorMinHealth = 0,
	ActorMinDefense = 0,
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
	int nextX;
	int nextY;
	bool moved;
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
	void SetNextX(int x);
	void SetNextY(int y);
	int GetNextX();
	int GetNextY();
	void SetNextPosition(int nextX, int nextY);
	void ResetNextPosition();
	bool HasMoved();
	void SetMove(bool value);
};

#endif /* ACTOR_H_ */
