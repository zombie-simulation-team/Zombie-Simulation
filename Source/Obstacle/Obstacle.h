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
	maxDefense = 100,
	minDefense = 0
};

class Obstacle: public Cell
{
private:
	int defense;

public:
	Obstacle();
	Obstacle(int, int, int , CellColor_e);
	Obstacle(int, int, CellColor_e);
	virtual ~Obstacle();
	virtual void tick() = 0;
	void setDefense(int);
	int getDefense(void);
};

#endif /* OBSTACLE_H_ */
