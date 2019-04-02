/*!
 * @file
 * @brief Test for Continent class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Continent.h"

enum
{
	ContinentSize = 10
};

TEST_GROUP(ContinentTest)
{
	Continent *continent;

	void setup()
	{
		continent = new Continent(ContinentSize, NorthAmerica, 3, 2, 4, 5);
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
	std::string expectedName = "North America";

	int actualSize = continent->GetSize();
	std::string actualName = continent->GetName();

	Cell ***actualShape = continent->GetShape();

	CHECK_EQUAL(expectedSize, actualSize);
	CHECK_EQUAL(expectedName, actualName);
	CheckShape(actualShape, actualSize);
}

TEST(ContinentTest, ShouldSetContinentNameToEurope)
{
	continent->SetName(Europe);

	std::string expectedName = "Europe";
	std::string actualName = continent->GetName();

	CHECK_EQUAL(expectedName, actualName);
}
