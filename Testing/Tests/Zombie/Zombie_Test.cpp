/*!
 * @file
 * @brief Test for Zombie class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Zombie.h"
#include "RandomGenerator_Mock.h"

#define Times
#define AndReturn

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
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();

		zombie = new Zombie(X,Y, randomGeneratorMock);
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

	void RandomGeneratorShouldBeCalled(int n, int val)
	{
		mock().expectNCalls(n, "GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", MoveUp)
					.withParameter("end", MoveLeftUp)
					.andReturnValue(val);
	}

	void ShouldTick(Zombie *zombie, int n)
	{
		for(int i = 0; i < n; i++)
		{
			zombie->Tick();
		}
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
			randomGeneratorMock);

	int expectedDefense = SomeDefenseValue;
	int expectedHealth = SomeHealthValue;

	int actualDefense = testZombie->GetDefense();
	int actualHealth = testZombie->GetHealth();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}

TEST(ZombieTest, ShouldNotDecrementZombieHealth)
{
	Zombie *testZombie = new Zombie(1, 1, randomGeneratorMock);

	RandomGeneratorShouldBeCalled(10 Times, AndReturn MoveDown);

	ShouldTick(testZombie, 10 Times);

	int expectedHealth = 100;
	int actualHealth = testZombie->GetHealth();
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}

