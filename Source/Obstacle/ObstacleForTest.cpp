/*
 * ObstacleForTest.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: javiervega
 */

#include "ObstacleForTest.h"

ObstacleForTest::ObstacleForTest()
{
}

ObstacleForTest::ObstacleForTest(int x, int y, int defence, CellColor_e color)
	: Obstacle(x, y, defence, color)
{
}

ObstacleForTest::~ObstacleForTest() {
	// TODO Auto-generated destructor stub
}

void ObstacleForTest::Tick()
{

}

