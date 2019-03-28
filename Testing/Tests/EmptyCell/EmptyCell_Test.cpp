/*!
 * @file
 * @brief Test for Empty Cell class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "EmptyCell.h"

TEST_GROUP(EmptyCellTest)
{
	EmptyCell *empty;

	void setup()
	{
		empty = new EmptyCell();
	}

	void teardown()
	{
		delete empty;
	}
};

TEST(EmptyCellTest, ShouldInitializeAnEmptyCell)
{
	int expectedX = 0;
	int expectedY = 0;
	int expectedColor = Transparent;

	CHECK_EQUAL(expectedX, empty->getX());
	CHECK_EQUAL(expectedY, empty->getY());
	CHECK_EQUAL(expectedColor, empty->getColor());
}

TEST(EmptyCellTest, ShouldTickEmptyCellOnce)
{
	mock().expectOneCall("tick").onObject(empty);
	mock().actualCall("tick").onObject(empty);
	mock().checkExpectations();
}
