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
	Obstacle(int x, int y, int defense, CellColor_e color);
	Obstacle(int x, int y, CellColor_e color);
	virtual ~Obstacle();
	virtual void Tick() = 0;
	void SetDefense(int);
	int GetDefense(void);
};

#endif /* OBSTACLE_H_ */
