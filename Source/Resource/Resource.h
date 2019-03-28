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
	maxFood = 100
};

class Resource: public Obstacle
{
private:
	int food;

public:
	Resource();
	void tick();
	int getFood();
	void setFood(int);
	virtual ~Resource();
};

#endif /* RESOURCE_H_ */
