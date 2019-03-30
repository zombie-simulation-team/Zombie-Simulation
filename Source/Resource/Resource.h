/*
 * Resources.h
 *
 *  Created on: Mar 24, 2019
 *      Author: javiervega
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "Obstacle.h"

enum
{
	minFood = 0,
	maxFood = 100,
	defaultFood = 50
};

class Resource: public Obstacle
{
private:
	int food;
	static const CellColor_e color = White;

public:
	Resource(int, int);
	Resource(int, int, int);
	void tick();
	int getFood();
	void setFood(int);
	virtual ~Resource();
};

#endif /* RESOURCE_H_ */
