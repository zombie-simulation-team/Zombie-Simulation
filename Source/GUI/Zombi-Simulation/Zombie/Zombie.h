/*
 * Zombie.h
 *
 *  Created on: Mar 31, 2019
 *      Author: javiervega
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "../Actor/Actor.h"

class Zombie: public Actor
{
private:
	int travel;
	static const CellColor_e color = Red;

public:
	Zombie(
		int x,
		int y,
		I_Random *randomGenerator);
	Zombie(
		int x,
		int y,
		int healthValue,
		int defenseValue,
		I_Random *randomGenerator);
	virtual ~Zombie();
	void Attack(Cell *cell);
	void Tick();
};

#endif /* ZOMBIE_H_ */
