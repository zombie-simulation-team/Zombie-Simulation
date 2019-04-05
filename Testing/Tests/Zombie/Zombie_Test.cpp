/*!
 * @file
 * @brief Test for Zombie class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Zombie.h"
#include "I_Random.h"
#include "FakeRandomGenerator.h"

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
	FakeRandomGenerator *random;
	I_Random *r;

	void setup()
	{
		random = new FakeRandomGenerator();
		r = (I_Random *)random;
		zombie = new Zombie(X,Y, r);
	}

	void teardown()
	{
		mock().checkExpectations();
		mock().clear();

		delete zombie;
		delete random;
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
	Zombie *testZombie = new Zombie(8, 7, SomeHealthValue, SomeDefenseValue, r);

	int expectedDefense = SomeDefenseValue;
	int expectedHealth = SomeHealthValue;

	int actualDefense = testZombie->GetDefense();
	int actualHealth = testZombie->GetHealth();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testZombie;
}

TEST(ZombieTest, ShouldMoveZombieUp)
{
	random->SetRandomNumber(1);

	int expectedNextX = X;
	int expectedNextY = Y - 1;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieRightUp)
{
	random->SetRandomNumber(2);

	int expectedNextX = X + 1;
	int expectedNextY = Y - 1;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieRight)
{
	random->SetRandomNumber(3);

	int expectedNextX = X + 1;
	int expectedNextY = Y;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieRightDown)
{
	random->SetRandomNumber(4);

	int expectedNextX = X + 1;
	int expectedNextY = Y + 1;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieDown)
{
	random->SetRandomNumber(5);

	int expectedNextX = X;
	int expectedNextY = Y + 1;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieLeftDown)
{
	random->SetRandomNumber(6);

	int expectedNextX = X - 1;
	int expectedNextY = Y + 1;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieLeft)
{
	random->SetRandomNumber(7);

	int expectedNextX = X - 1;
	int expectedNextY = Y;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ZombieTest, ShouldMoveZombieLeftUp)
{
	random->SetRandomNumber(8);

	int expectedNextX = X - 1;
	int expectedNextY = Y - 1;

	zombie->Tick();

	int actualNextX = zombie->GetNextX();
	int actualNextY = zombie->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}
