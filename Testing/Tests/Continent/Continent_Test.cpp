/*!
 * @file
 * @brief Test for Continent class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Continent.h"
#include <iostream>

enum
{
	ContinentSize = 10
};

TEST_GROUP(ContinentTest)
{
	Continent *continent;

	void setup()
	{
		continent = new Continent(ContinentSize, "America");
	}

	void teardown()
	{
		delete continent;
	}

	void CheckShape(Cell ***actualShape, int size)
	{
		bool expectedIsValid = true;
		int expectedX;
		int expectedY;

		for(int i = 0; i < ContinentSize; i++) {
			for(int j = 0; j < ContinentSize; j++) {
				EmptyCell *emptyCell = dynamic_cast<EmptyCell*>(actualShape[i][j]);

				expectedX = i;
				expectedY = j;

				int actualX = emptyCell->getX();
				int actualY = emptyCell->getY();
				bool actualIsValid = emptyCell->isValid();

				CHECK_EQUAL(expectedX, actualX);
				CHECK_EQUAL(expectedY, actualY);
				CHECK_EQUAL(expectedIsValid, actualIsValid);
			}
		}
	}
};

TEST(ContinentTest, ShouldInitializeAContinentWithEmptyCells)
{
	int expectedSize = ContinentSize;
	string expectedName = "America";

	int actualSize = continent->getSize();
	string actualName = continent->getName();

	Cell ***actualShape = continent->getShape();

	CHECK_EQUAL(expectedSize, actualSize);
	CheckShape(actualShape, actualSize);
}

TEST(ContinentTest, ShouldSetContinentNameToEurope)
{
	continent->setName("Europe");

	string expectedName = "Europe";
	string actualName = continent->getName();

	CHECK_EQUAL(expectedName, actualName);
}
