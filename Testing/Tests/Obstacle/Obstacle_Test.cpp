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

	int actualDefense = obstacle->GetDefense();
	int actualX = obstacle->GetX();
	int actualY = obstacle->GetY();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(ObstacleTest, ShouldSetDefenseOfAnObstacle)
{
	int expectedDefense = 60;

	obstacle->SetDefense(60);
	int actualDefense = obstacle->GetDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ObstacleTest, ShouldSetDefenseLessThanOrEqualToMaximum)
{
	int expectedDefense = 100;

	obstacle->SetDefense(150);
	int actualDefense = obstacle->GetDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ObstacleTest, ShouldSetDefenseGreaterThanOrEqualToMinimum)
{
	int expectedDefense = 0;

	obstacle->SetDefense(-100);
	int actualDefense = obstacle->GetDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ObstacleTest, ShouldInitializeAnObstacleWithPositionAndDefense)
{
	ObstacleForTest *theObstacle = new ObstacleForTest(5, 10, 100, White);

	int expectedDefense = 100;
	int expectedX = 5;
	int expectedY = 10;
	CellColor_e expectedColor = White;

	int actualDefense = theObstacle->GetDefense();
	int actualX = theObstacle->GetX();
	int actualY = theObstacle->GetY();
	int actualColor = theObstacle->GetColor();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);

	delete theObstacle;
}

