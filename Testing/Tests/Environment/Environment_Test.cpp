/*!
 * @file
 * @brief Test for Environment class using a derived class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "EnvironmentForTest.h"

TEST_GROUP(EnvironmentTest)
{
	EnvironmentForTest *environment;

	void setup()
	{
		environment = new EnvironmentForTest();
	}

	void teardown()
	{
		delete environment;
	}
};

TEST(EnvironmentTest, ShouldInitializeDefaultEnvironment)
{
	CHECK_EQUAL(0, environment->getHumanCount());
	CHECK_EQUAL(0, environment->getZombiCount());
	CHECK_EQUAL(0, environment->getTrapCount());
	CHECK_EQUAL(0, environment->getResourceCount());
}

TEST(EnvironmentTest, ShouldSetCountForEnvironmentObjects)
{
	//Test setting and getting human count
	environment->setHumanCount(1000);
	int expected = 1000;
	int actual = environment->getHumanCount();

	CHECK_EQUAL(expected, actual);

	//Test setting and getting zombie count
	environment->setZombiCount(500);
	expected = 500;
	actual = environment->getZombiCount();

	CHECK_EQUAL(expected, actual);

	//Test setting and getting trap count
	environment->setTrapCount(20);
	expected = 20;
	actual = environment->getTrapCount();

	CHECK_EQUAL(expected, actual);

	//Test setting and getting resources count
	environment->setResourceCount(100);
	expected = 100;
	actual = environment->getResourceCount();

	CHECK_EQUAL(expected, actual);
}

TEST(EnvironmentTest, ShouldInitializeAnEnvironmentWithActorsAndObstaclesCount)
{
	EnvironmentForTest *env = new EnvironmentForTest(10, 20, 4, 6);

	int expectedHumans = 10;
	int expectedZombies = 20;
	int expectedTraps = 4;
	int expectedResources = 6;

	CHECK_EQUAL(expectedHumans, env->getHumanCount());
	CHECK_EQUAL(expectedZombies, env->getZombiCount());
	CHECK_EQUAL(expectedTraps, env->getTrapCount());
	CHECK_EQUAL(expectedResources, env->getResourceCount());

	delete env;
}

