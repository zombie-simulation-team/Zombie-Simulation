/*
 * Trap.h
 *
 *  Created on: Mar 24, 2019
 *      Author: javiervega
 */

#ifndef TRAP_H_
#define TRAP_H_

#include "Obstacle.h"

enum
{
	minAttack = 0,
	maxAttack = 100,
	defaultAttack = 100
};

class Trap: public Obstacle
{
private:
	int attack;
	static const CellColor_e color = Black;

public:
	Trap(int x, int y);
	Trap(int x, int y, int amount);
	void setAttack(int amount);
	int getAttack();
	void tick();
	virtual ~Trap();
};

#endif /* SOURCE_TRAP_TRAP_H_ */
