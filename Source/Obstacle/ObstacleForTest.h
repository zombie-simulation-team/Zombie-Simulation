/*
 * ObstacleForTest.h
 *
 *  Created on: Mar 30, 2019
 *      Author: javiervega
 */

#ifndef OBSTACLEFORTEST_H_
#define OBSTACLEFORTEST_H_

#include "Obstacle.h"

class ObstacleForTest: public Obstacle
{
public:
	ObstacleForTest();
	ObstacleForTest(int, int, int, CellColor_e);
	void tick();
	virtual ~ObstacleForTest();
};

#endif /* OBSTACLEFORTEST_H_ */
