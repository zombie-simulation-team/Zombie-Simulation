/*
 * Obstacle.h
 *
 *  Created on: Mar 14, 2019
 *      Author: javiervega
 */

#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include "Cell.h"

enum
{
	maxDefence = 100,
	minDefence = 0
};

class Obstacle: public Cell
{
private:
	int defence;

public:
	Obstacle();
	virtual ~Obstacle();
	void tick();
	void setDefence(int);
	int getDefence(void);
};

#endif /* OBSTACLE_H_ */
