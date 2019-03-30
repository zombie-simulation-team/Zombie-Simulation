/*!
 * @file
 * @brief Test for Resource class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Resource.h"

TEST_GROUP(ResourceTest)
{
	Resource *resource;

	void setup()
	{
		resource = new Resource(5, 5);
	}

	void teardown()
	{
		delete resource;
	}
};

TEST(ResourceTest, ShouldInitializeADefaultResource)
{
	int expectedFood = 50;
	CellColor_e expectedColor = White;

	int actualFood = resource->getFood();
	CellColor_e actualColor = resource->getColor();

	CHECK_EQUAL(expectedFood, actualFood);
	CHECK_EQUAL(expectedColor, actualColor);
}

TEST(ResourceTest, ShouldSetFoodValue)
{
	int expectedFood = 60;

	resource->setFood(60);

	int actualFood = resource->getFood();

	CHECK_EQUAL(expectedFood, actualFood);
}

TEST(ResourceTest, ShouldSetFoodEqualToMaximumFood)
{
	int expectedFood = 100;

	resource->setFood(160);

	int actualFood = resource->getFood();

	CHECK_EQUAL(expectedFood, actualFood);
}

TEST(ResourceTest, ShouldSetFoodEqualToMinimumFood)
{
	int expectedFood = 0;

	resource->setFood(-160);

	int actualFood = resource->getFood();

	CHECK_EQUAL(expectedFood, actualFood);
}

TEST(ResourceTest, ShouldInitializeARessurceWithPositionAndFood)
{
	Resource *theResource = new Resource(4, 9, 50);

	int expectedFood = 50;
	int expectedX = 4;
	int expectedY = 9;
	CellColor_e expectedColor = White;

	int actualFood = theResource->getFood();
	int actualX = theResource->getX();
	int actualY = theResource->getY();
	int actualColor = theResource->getColor();

	CHECK_EQUAL(expectedFood, actualFood);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
	CHECK_EQUAL(expectedColor, actualColor);

	delete theResource;
}
