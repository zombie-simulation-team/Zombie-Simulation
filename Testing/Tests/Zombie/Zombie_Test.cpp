/*!
 * @file
 * @brief Test for Zombie class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Zombie.h"

enum
{
	DefaultHealth = 100,
	DefaultDefense = 100,
	SomeDefenseValue = 60,
	SomeHealthValue = 40,
	X = 3,
	Y = 3
};

TEST_GROUP(ZombieTest)
{
	Zombie *zombie;

	void setup()
	{
		zombie = new Zombie(X,Y);
	}

	void teardown()
	{
		delete zombie;
	}
};

TEST(ZombieTest, ShouldInitializeAZombie)
{
	int expectedDefense = DefaultDefense;
	int expectedHealth = DefaultHealth;
	CellColor_e expectedColor = Red;
	int expectedX = 3;
	int expectedY = 3;

	int actualDefense = zombie->getDefense();
	int actualHealth = zombie->getHealth();
	CellColor_e actualColor = zombie->getColor();
	int actualX = zombie->getX();
	int actualY = zombie->getY();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(ZombieTest, ShouldInitializeAZombieWithGivenHealthAndDefense)
{
	Zombie *testZombie = new Zombie(8, 7, SomeHealthValue, SomeDefenseValue);

	int expectedDefense = SomeDefenseValue;
	int expectedHealth = SomeHealthValue;

	int actualDefense = testZombie->getDefense();
	int actualHealth = testZombie->getHealth();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}
