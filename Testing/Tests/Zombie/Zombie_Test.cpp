/*!
 * @file
 * @brief Test for Zombie class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Zombie.h"

#include "RandomGenerator_Mock.h"

enum
{
	SomeDefenseValue = 60,
	SomeHealthValue = 40,
	X = 3,
	Y = 3
};

TEST_GROUP(ZombieTest)
{
	Zombie *zombie;
	I_Random *randomGenerator;

	void setup()
	{
		zombie = new Zombie(X,Y, randomGenerator);
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

	int actualDefense = zombie->GetDefense();
	int actualHealth = zombie->GetHealth();
	CellColor_e actualColor = zombie->GetColor();
	int actualX = zombie->GetX();
	int actualY = zombie->GetY();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(ZombieTest, ShouldInitializeAZombieWithGivenHealthAndDefense)
{
	Zombie *testZombie = new Zombie(
			8,
			7,
			SomeHealthValue,
			SomeDefenseValue,
			randomGenerator);

	int expectedDefense = SomeDefenseValue;
	int expectedHealth = SomeHealthValue;

	int actualDefense = testZombie->GetDefense();
	int actualHealth = testZombie->GetHealth();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}
