/*
 * ActorForTest.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Alex Rivero
 */

#ifndef ACTOR_FORTEST_H_
#define ACTOR_FORTEST_H_

#include "Actor.h"

class ActorForTest: public Actor
{
private:
	I_Random *randomGenerator;
public:
	ActorForTest(int,int, CellColor_e, int, int, I_Random *);
	virtual ~ActorForTest();
	void Attack(Cell*);
	void Tick();
};

#endif	/* ACTOR_FORTEST_H_ */
