/*!
 * @file
 * @brief Test for Obstacle class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Obstacle.h"

TEST_GROUP(ObstacleTest)
{
	Obstacle *obstacle;

	void setup()
	{
		obstacle = new Obstacle();
	}

	void teardown()
	{
		delete obstacle;
	}
};

TEST(ObstacleTest, ShouldInitializeAnObstacle)
{
	int actualDefence = 0;

	int expectedDefence = obstacle->getDefence();

	CHECK_EQUAL(actualDefence, expectedDefence);
}

TEST(ObstacleTest, ShouldSetDefenceOfAnObstacle)
{
	int actualDefence = 60;

	obstacle->setDefence(60);
	int expectedDefence = obstacle->getDefence();

	CHECK_EQUAL(actualDefence, expectedDefence);
}

TEST(ObstacleTest, ShouldSetDefenceLessThanOrEqualToMaximum)
{
	int actualDefence = 100;

	obstacle->setDefence(150);
	int expectedDefence = obstacle->getDefence();

	CHECK_EQUAL(actualDefence, expectedDefence);
}

TEST(ObstacleTest, ShouldSetDefenceGreaterThanOrEqualToMinimum)
{
	int actualDefence = 0;

	obstacle->setDefence(-100);
	int expectedDefence = obstacle->getDefence();

	CHECK_EQUAL(actualDefence, expectedDefence);
}

