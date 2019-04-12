/*!
 * @file
 * @brief Test for World class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "World.h"
#include "RandomGenerator_Mock.h"

enum
{
	ContinentSize = 10,
	NumberOfContinents = 1,

};

TEST_GROUP(WorldTest)
{
	World *world;
	I_Random *randomInterface;
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		world = new World(NumberOfContinents, NorthAmerica, randomInterface);
	}

	void teardown()
	{
		delete world;
	}
};

TEST(WorldTest, ShouldInitializeAWorld)
{

}
