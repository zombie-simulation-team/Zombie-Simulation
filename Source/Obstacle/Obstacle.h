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
	minDefence = 0,
	defaultDefece = 100
};

class Obstacle: public Cell
{
private:
	int defence;

public:
	Obstacle();
	Obstacle(int, int, int , CellColor_e);
	Obstacle(int, int, CellColor_e);
	virtual ~Obstacle();
	virtual void tick() = 0;
	void setDefence(int);
	int getDefence(void);
};

#endif /* OBSTACLE_H_ */
