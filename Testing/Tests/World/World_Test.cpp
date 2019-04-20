/*!
 * @file
 * @brief Test for World class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "World.h"

enum
{
	ContinentSize = 10
};

TEST_GROUP(WorldTest)
{
	World *world;

	void setup()
	{
		world = new World(2);
	}

	void teardown()
	{
		delete world;
	}
};

TEST(WorldTest, ShouldInitializeAWorld)
{

}
