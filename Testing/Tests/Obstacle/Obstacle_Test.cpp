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
	int expectedDefence = 0;

	int actualDefence = obstacle->getDefence();

	CHECK_EQUAL(expectedDefence, actualDefence);
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

