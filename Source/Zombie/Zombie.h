/*
 * Zombie.h
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "Actor.h"

enum
{
	defaultHealth = 100,
	defaultDefense = 100,
	defaultTravelAmount = 1
};

class Zombie: public Actor
{
private:
	int travel;
	static const CellColor_e color = Red;

public:
	Zombie(int x, int y);
	Zombie(int x, int y, int healthValue, int defenseValue);
	virtual ~Zombie();
	void Attack(Cell *cell);
	void Move(Cell *cell);
	void Tick();
};

#endif /* ZOMBIE_H_ */
