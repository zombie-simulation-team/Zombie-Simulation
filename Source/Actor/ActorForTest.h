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
public:
	ActorForTest();
	ActorForTest(int,int, CellColor_e, int, int);
	virtual ~ActorForTest();
	void move(Cell*);
	void attack(Cell*);
	void tick();
};

#endif	/* ACTOR_FORTEST_H_ */
