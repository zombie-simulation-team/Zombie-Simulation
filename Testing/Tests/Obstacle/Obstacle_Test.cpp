/*!
 * @file
 * @brief Test for Obstacle class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "ObstacleForTest.h"

TEST_GROUP(ObstacleTest)
{
	ObstacleForTest *obstacle;

	void setup()
	{
		obstacle = new ObstacleForTest();
	}

	void teardown()
	{
		delete obstacle;
	}
};

TEST(ObstacleTest, ShouldInitializeAnObstacle)
{
	int expectedDefence = 0;
	int expectedX = 0;
	int expectedY = 0;

	int actualDefence = obstacle->getDefence();
	int actualX = obstacle->getX();
	int actualY = obstacle->getY();

	CHECK_EQUAL(expectedDefence, actualDefence);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(ObstacleTest, ShouldSetDefenceOfAnObstacle)
{
	int expectedDefence = 60;

	obstacle->setDefence(60);
	int actualDefence = obstacle->getDefence();

	CHECK_EQUAL(expectedDefence, actualDefence);
}

TEST(ObstacleTest, ShouldSetDefenceLessThanOrEqualToMaximum)
{
	int expectedDefence = 100;

	obstacle->setDefence(150);
	int actualDefence = obstacle->getDefence();

	CHECK_EQUAL(expectedDefence, actualDefence);
}

TEST(ObstacleTest, ShouldSetDefenceGreaterThanOrEqualToMinimum)
{
	int expectedDefence = 0;

	obstacle->setDefence(-100);
	int actualDefence = obstacle->getDefence();

	CHECK_EQUAL(expectedDefence, actualDefence);
}

TEST(ObstacleTest, ShouldInitializeAnObstacleWithPositionAndDefence)
{
	ObstacleForTest *theObstacle = new ObstacleForTest(5, 10, 100, White);

	int expectedDefence = 100;
	int expectedX = 5;
	int expectedY = 10;
	CellColor_e expectedColor = White;

	int actualDefence = theObstacle->getDefence();
	int actualX = theObstacle->getX();
	int actualY = theObstacle->getY();
	int actualColor = theObstacle->getColor();

	CHECK_EQUAL(expectedDefence, actualDefence);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);

	delete theObstacle;
}

