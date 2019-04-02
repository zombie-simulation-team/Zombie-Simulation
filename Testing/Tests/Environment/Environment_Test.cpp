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
		environment = new EnvironmentForTest(0, 0, 0, 0);
	}

	void teardown()
	{
		delete environment;
	}
};

TEST(EnvironmentTest, ShouldInitializeDefaultEnvironment)
{
	CHECK_EQUAL(0, environment->GetHumanCount());
	CHECK_EQUAL(0, environment->GetZombieCount());
	CHECK_EQUAL(0, environment->GetTrapCount());
	CHECK_EQUAL(0, environment->GetResourceCount());
}

TEST(EnvironmentTest, ShouldSetCountForEnvironmentObjects)
{
	//Test setting and Getting human count
	environment->SetHumanCount(1000);
	int expected = 1000;
	int actual = environment->GetHumanCount();

	CHECK_EQUAL(expected, actual);

	//Test setting and Getting Zombie count
	environment->SetZombieCount(500);
	expected = 500;
	actual = environment->GetZombieCount();

	CHECK_EQUAL(expected, actual);

	//Test setting and Getting trap count
	environment->SetTrapCount(20);
	expected = 20;
	actual = environment->GetTrapCount();

	CHECK_EQUAL(expected, actual);

	//Test setting and Getting resources count
	environment->SetResourceCount(100);
	expected = 100;
	actual = environment->GetResourceCount();

	CHECK_EQUAL(expected, actual);
}

TEST(EnvironmentTest, ShouldInitializeAnEnvironmentWithActorsAndObstaclesCount)
{
	EnvironmentForTest *env = new EnvironmentForTest(10, 20, 4, 6);

	int expectedHumans = 10;
	int expectedZombies = 20;
	int expectedTraps = 4;
	int expectedResources = 6;

	CHECK_EQUAL(expectedHumans, env->GetHumanCount());
	CHECK_EQUAL(expectedZombies, env->GetZombieCount());
	CHECK_EQUAL(expectedTraps, env->GetTrapCount());
	CHECK_EQUAL(expectedResources, env->GetResourceCount());

	delete env;
}

