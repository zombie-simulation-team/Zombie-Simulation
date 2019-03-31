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
	int expectedDefense = 100;
	int expectedX = 0;
	int expectedY = 0;

	int actualDefense = obstacle->getDefense();
	int actualX = obstacle->getX();
	int actualY = obstacle->getY();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(ObstacleTest, ShouldSetDefenseOfAnObstacle)
{
	int expectedDefense = 60;

	obstacle->setDefense(60);
	int actualDefense = obstacle->getDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ObstacleTest, ShouldSetDefenseLessThanOrEqualToMaximum)
{
	int expectedDefense = 100;

	obstacle->setDefense(150);
	int actualDefense = obstacle->getDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ObstacleTest, ShouldSetDefenseGreaterThanOrEqualToMinimum)
{
	int expectedDefense = 0;

	obstacle->setDefense(-100);
	int actualDefense = obstacle->getDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ObstacleTest, ShouldInitializeAnObstacleWithPositionAndDefense)
{
	ObstacleForTest *theObstacle = new ObstacleForTest(5, 10, 100, White);

	int expectedDefense = 100;
	int expectedX = 5;
	int expectedY = 10;
	CellColor_e expectedColor = White;

	int actualDefense = theObstacle->getDefense();
	int actualX = theObstacle->getX();
	int actualY = theObstacle->getY();
	int actualColor = theObstacle->getColor();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);

	delete theObstacle;
}

