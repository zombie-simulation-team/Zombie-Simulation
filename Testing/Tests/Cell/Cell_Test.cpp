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

	int actualX = cell->GetX();
	int actualY = cell->GetY();
	int actualColor = cell->GetColor();
	bool actualIsValid = cell->IsValid();

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

	int actualX = myCell->GetX();
	int actualY = myCell->GetY();
	int actualColor = myCell->GetColor();
	int actualIsValid = myCell->IsValid();

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

	int actualX = myCell->GetX();
	int actualY = myCell->GetY();
	int actualColor = myCell->GetColor();
	int actualIsValid = myCell->IsValid();

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

	int actualX = myCell->GetX();
	int actualY = myCell->GetY();
	int actualColor = myCell->GetColor();
	int actualIsValid = myCell->IsValid();

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

	int actualX = myCell->GetX();
	int actualY = myCell->GetY();
	int actualColor = myCell->GetColor();
	int actualIsValid = myCell->IsValid();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}

TEST(CellTest, ShouldSetCellXPosition)
{
	int expectedX = 20;

	cell->SetX(20);

	int actualX = cell->GetX();

	CHECK_EQUAL(expectedX, actualX);
}

TEST(CellTest, ShouldSetCellYPosition)
{
	int expectedY = 20;

	cell->SetY(20);

	int actualY = cell->GetY();

	CHECK_EQUAL(expectedY, actualY);
}

TEST(CellTest, ShouldSetCellColor)
{
	int expectedColor = Red;

	cell->SetColor(Red);

	int actualColor = cell->GetColor();

	CHECK_EQUAL(expectedColor, actualColor);
}

TEST(CellTest, ShouldSetAnInvalidCell)
{
	CellForTest *myCell = new CellForTest(4, 5, Red, false);

	int expectedIsValid = false;

	int actualIsValid = myCell->IsValid();

	CHECK_EQUAL(expectedIsValid, actualIsValid);

	delete myCell;
}

TEST(CellTest, ShouldGetAZombieCell)
{
	CellForTest *myCell = new CellForTest(4, 5, Red, false);

	int expected = true;

	int actual = myCell->IsZombie();

	CHECK_EQUAL(expected, actual);

	delete myCell;
}

TEST(CellTest, ShouldGetAHumanCell)
{
	CellForTest *myCell = new CellForTest(4, 5, Green, false);

	int expected = true;

	int actual = myCell->IsHuman();

	CHECK_EQUAL(expected, actual);

	delete myCell;
}

TEST(CellTest, ShouldGetAResourceCell)
{
	CellForTest *myCell = new CellForTest(4, 5, White, false);

	int expected = true;

	int actual = myCell->IsResource();

	CHECK_EQUAL(expected, actual);

	delete myCell;
}

TEST(CellTest, ShouldGetATrapCell)
{
	CellForTest *myCell = new CellForTest(4, 5, Black, false);

	int expected = true;

	int actual = myCell->IsTrap();

	CHECK_EQUAL(expected, actual);

	delete myCell;
}

TEST(CellTest, ShouldGetAEmptyCell)
{
	CellForTest *myCell = new CellForTest(4, 5, Grey, false);

	int expected = true;

	int actual = myCell->IsEmpty();

	CHECK_EQUAL(expected, actual);

	delete myCell;
}
