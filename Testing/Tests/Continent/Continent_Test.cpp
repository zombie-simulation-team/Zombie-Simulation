/*!
 * @file
 * @brief Test for Continent class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Continent.h"
#include <iostream>

TEST_GROUP(ContinentTest)
{
	Continent *continent;

	void setup()
	{
		continent = new Continent();
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

		for(int i = 0; i < continent->getSize(); i++) {
			for(int j = 0; j < continent->getSize(); j++) {
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

TEST(ContinentTest, ShouldInitializeADefaultContinent)
{
	int expectedSize = 10;
	int actualSize = continent->getSize();

	CHECK_EQUAL(expectedSize, actualSize);

	Cell ***actualShape = continent->getShape();

	CheckShape(actualShape, actualSize);
}

TEST(ContinentTest, ShouldInitializeAContinentWithNameAndSize)
{
	Continent *theContinent = new Continent(10, "America");

	int expectedSize = 10;
	string expectedName = "America";

	int actualSize = continent->getSize();
	string actualName = theContinent->getName();

	CHECK_EQUAL(expectedSize, actualSize);
	CHECK_EQUAL(expectedName, actualName);

	delete theContinent;
}

TEST(ContinentTest, ShouldSetContinentNameToEurope)
{
	continent->setName("Europe");

	string expectedName = "Europe";
	string actualName = continent->getName();

	CHECK_EQUAL(expectedName, actualName);
}

