/*!
 * @file
 * @brief Test for Cell class using a derived class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "CellForTest.h"

TEST_GROUP(CellTest)
{
	CellForTest *cell;

	void setup()
	{
		cell = new CellForTest();
	}

	void teardown()
	{
		delete cell;
	}
};

TEST(CellTest, ShouldInitializeCell)
{
	int actualX = 0;
	int actualY = 0;
	int actualColor = Transparent;

	CHECK_EQUAL(actualX, cell->getX());
	CHECK_EQUAL(actualY, cell->getY());
	CHECK_EQUAL(actualColor, cell->getColor());
}

TEST(CellTest, ShouldSetCellXPosition)
{
	int actualX = 20;

	cell->setX(20);

	CHECK_EQUAL(actualX, cell->getX());
}

TEST(CellTest, ShouldSetCellYPosition)
{
	int actualY = 20;

	cell->setY(20);

	CHECK_EQUAL(actualY, cell->getY());
}

TEST(CellTest, ShouldSetCellColor)
{
	int actualColor = Red;

	cell->setColor(Red);

	CHECK_EQUAL(actualColor, cell->getColor());
}
