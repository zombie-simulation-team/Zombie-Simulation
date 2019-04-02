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

	CHECK_EQUAL(expectedX, empty->GetX());
	CHECK_EQUAL(expectedY, empty->GetY());
	CHECK_EQUAL(expectedColor, empty->GetColor());
	CHECK_EQUAL(expectedIsValid, empty->IsValid());
}

TEST(EmptyCellTest, ShouldInitializeAnInvalidEmptyCell)
{
	EmptyCell *myEmptyCell = new EmptyCell(4, 4, false);

	int expectedX = 4;
	int expectedY = 4;
	int expectedColor = Transparent;
	bool expectedIsValid = false;

	CHECK_EQUAL(expectedX, myEmptyCell->GetX());
	CHECK_EQUAL(expectedY, myEmptyCell->GetY());
	CHECK_EQUAL(expectedColor, myEmptyCell->GetColor());
	CHECK_EQUAL(expectedIsValid, myEmptyCell->IsValid());

	delete myEmptyCell;
}

TEST(EmptyCellTest, ShouldInitializeAnInvalidEmptyCellWithColor)
{
	EmptyCell *myEmptyCell = new EmptyCell(4, 4, Black, false);

	int expectedX = 4;
	int expectedY = 4;
	int expectedColor = Black;
	bool expectedIsValid = false;

	CHECK_EQUAL(expectedX, myEmptyCell->GetX());
	CHECK_EQUAL(expectedY, myEmptyCell->GetY());
	CHECK_EQUAL(expectedColor, myEmptyCell->GetColor());
	CHECK_EQUAL(expectedIsValid, myEmptyCell->IsValid());

	delete myEmptyCell;
}

TEST(EmptyCellTest, ShouldTickEmptyCellOnce)
{
	mock().expectOneCall("Tick").onObject(empty);
	mock().actualCall("Tick").onObject(empty);
	mock().checkExpectations();
}
