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
		resource = new Resource();
	}

	void teardown()
	{
		delete resource;
	}
};

TEST(ResourceTest, ShouldInitializeAResource)
{
	int expectedFood = 0;

	int actualFood = resource->getFood();

	CHECK_EQUAL(expectedFood, actualFood);
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
