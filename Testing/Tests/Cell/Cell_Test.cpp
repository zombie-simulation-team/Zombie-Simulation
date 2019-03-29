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

	//Initializes a Cell before every test.
	void setup()
	{
		cell = new CellForTest();
	}

	//destroys the Cell after test ends.
	void teardown()
	{
		delete cell;
	}
};

TEST(CellTest, ShouldInitializeACell)
{
	int expectedX = 0;
	int expectedY = 0;
	int expectedColor = Transparent;
	bool expectedIsValid = true;

	int actualX = cell->getX();
	int actualY = cell->getY();
	int actualColor = cell->getColor();
	bool actualIsValid = cell->isValid();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedIsValid, actualIsValid);
}

TEST(CellTest, ShouldInitializeCellWithPositionColorAndValidity)
{
	CellForTest *myCell = new CellForTest(8, 6, Black, true);

	int expectedX = 8;
	int expectedY = 6;
	int expectedColor = Black;
	int expectedIsValid = true;

	int actualX = myCell->getX();
	int actualY = myCell->getY();
	int actualColor = myCell->getColor();
	int actualIsValid = myCell->isValid();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}

TEST(CellTest, ShouldInitializeCellWithPositionAndColor)
{
	CellForTest *myCell = new CellForTest(8, 6, Green);

	int expectedX = 8;
	int expectedY = 6;
	int expectedColor = Green;
	int expectedIsValid = true;

	int actualX = myCell->getX();
	int actualY = myCell->getY();
	int actualColor = myCell->getColor();
	int actualIsValid = myCell->isValid();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}

TEST(CellTest, ShouldInitializeCellWithPositionAndValidity)
{
	CellForTest *myCell = new CellForTest(8, 6, false);

	int expectedX = 8;
	int expectedY = 6;
	int expectedColor = Transparent;
	int expectedIsValid = false;

	int actualX = myCell->getX();
	int actualY = myCell->getY();
	int actualColor = myCell->getColor();
	int actualIsValid = myCell->isValid();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}

TEST(CellTest, ShouldInitializeCellOnlyWithPositionOnly)
{
	CellForTest *myCell = new CellForTest(8, 6);

	int expectedX = 8;
	int expectedY = 6;
	int expectedColor = Transparent;
	int expectedIsValid = true;

	int actualX = myCell->getX();
	int actualY = myCell->getY();
	int actualColor = myCell->getColor();
	int actualIsValid = myCell->isValid();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}

TEST(CellTest, ShouldSetCellXPosition)
{
	int expectedX = 20;

	cell->setX(20);

	int actualX = cell->getX();

	CHECK_EQUAL(expectedX, actualX);
}

TEST(CellTest, ShouldSetCellYPosition)
{
	int expectedY = 20;

	cell->setY(20);

	int actualY = cell->getY();

	CHECK_EQUAL(expectedY, actualY);
}

TEST(CellTest, ShouldSetCellColor)
{
	int expectedColor = Red;

	cell->setColor(Red);

	int actualColor = cell->getColor();

	CHECK_EQUAL(expectedColor, actualColor);
}

TEST(CellTest, ShouldSetAnInvalidCell)
{
	CellForTest *myCell = new CellForTest(4, 5, Red, false);

	int expectedIsValid = false;

	int actualIsValid = myCell->isValid();

	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}
