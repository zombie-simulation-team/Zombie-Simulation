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
	MoveUp = 0,
	MoveRightUp = 1,
	MoveRight = 2,
	MoveRightDown = 3,
	MoveDown = 4,
	MoveLeftDown = 5,
	MoveLeft = 6,
	MoveLeftUp = 7,
	MoveDirectionSize = 8
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
	bool moveDirections[MoveDirectionSize];
	int moveDirectionsIndex;

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
	void SetDirectionIndex(int val);
	void ChangeNextMoveIndex();
	void ResetDirections();
};

#endif /* ACTOR_H_ */
