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
	bool expectedIsValid = true;

	CHECK_EQUAL(expectedX, empty->getX());
	CHECK_EQUAL(expectedY, empty->getY());
	CHECK_EQUAL(expectedColor, empty->getColor());
	CHECK_EQUAL(expectedIsValid, empty->isValid());
}

TEST(EmptyCellTest, ShouldInitializeAnInvalidEmptyCell)
{
	EmptyCell *myEmptyCell = new EmptyCell(4, 4, false);

	int expectedX = 4;
	int expectedY = 4;
	int expectedColor = Transparent;
	bool expectedIsValid = false;

	CHECK_EQUAL(expectedX, myEmptyCell->getX());
	CHECK_EQUAL(expectedY, myEmptyCell->getY());
	CHECK_EQUAL(expectedColor, myEmptyCell->getColor());
	CHECK_EQUAL(expectedIsValid, myEmptyCell->isValid());

	delete myEmptyCell;
}

TEST(EmptyCellTest, ShouldInitializeAnInvalidEmptyCellWithColor)
{
	EmptyCell *myEmptyCell = new EmptyCell(4, 4, Black, false);

	int expectedX = 4;
	int expectedY = 4;
	int expectedColor = Black;
	bool expectedIsValid = false;

	CHECK_EQUAL(expectedX, myEmptyCell->getX());
	CHECK_EQUAL(expectedY, myEmptyCell->getY());
	CHECK_EQUAL(expectedColor, myEmptyCell->getColor());
	CHECK_EQUAL(expectedIsValid, myEmptyCell->isValid());

	delete myEmptyCell;
}

TEST(EmptyCellTest, ShouldTickEmptyCellOnce)
{
	mock().expectOneCall("tick").onObject(empty);
	mock().actualCall("tick").onObject(empty);
	mock().checkExpectations();
}
