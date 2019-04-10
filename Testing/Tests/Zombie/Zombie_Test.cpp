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
	I_Random *randomGeneratorInterface;
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();
		randomGeneratorInterface = (I_Random *)randomGeneratorMock;

		zombie = new Zombie(X,Y, randomGeneratorInterface);
	}

	void teardown()
	{
		delete zombie;
		delete randomGeneratorMock;
	}

	void RandomGeneratorShouldBeCalledAndReturn(int val)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 1)
					.withParameter("end", 8)
					.andReturnValue(val);
	}

	void ZombieHealthShouldBeZero(int expected, int actual)
	{
		CHECK_EQUAL(expected, actual);
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
			randomGeneratorInterface);

	int expectedDefense = SomeDefenseValue;
	int expectedHealth = SomeHealthValue;

	int actualDefense = testZombie->GetDefense();
	int actualHealth = testZombie->GetHealth();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}

TEST(ZombieTest, ShouldDecrementHealthByTwentyAfterOneTick)
{
	Zombie *testZombie = new Zombie(4, 3, randomGeneratorInterface);

	RandomGeneratorShouldBeCalledAndReturn(MoveDown);

	testZombie->Tick();

	int expectedHealth = DefaultHealth - 10;
	int actualHealth = testZombie->GetHealth();

	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}

TEST(ZombieTest, ShouldDecrementHealthToZero)
{
	Zombie *testZombie = new Zombie(1, 1, randomGeneratorInterface);

	int expectedHealth;
	int actualHealth;

	for(int i = 1; i <= 10; i++)
	{
		RandomGeneratorShouldBeCalledAndReturn(MoveDown);

		testZombie->Tick();

		expectedHealth = DefaultHealth - (10 * i);
		actualHealth = testZombie->GetHealth();

		CHECK_EQUAL(expectedHealth, actualHealth);
	}

	expectedHealth = 0;

	ZombieHealthShouldBeZero(expectedHealth, actualHealth);

	delete testZombie;
}

