/*!
 * @file
 * @brief Test for Trap class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "ActorForTest.h"
#include "I_Random.h"
#include "RandomGenerator_Mock.h"

enum
{
	MaximumHealth = 100,
	MinimumHealth = 0,
	MaximumDefense = 100,
	MinimumDefense = 0,
	SomeDefenseValue = 20,
	X = 3,
	Y = 3
};

TEST_GROUP(ActorTest)
{
	ActorForTest *actor;
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();
		actor = new ActorForTest(
				X,
				Y,
				Green,
				MaximumHealth,
				SomeDefenseValue,
				randomGeneratorMock);
	}

	void teardown()
	{
		delete actor;
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
};

TEST(ActorTest, ShouldInitializeAnActor)
{
	int expectedDefense = SomeDefenseValue;
	int expectedHealth = MaximumHealth;
	CellColor_e expectedColor = Green;
	int expectedX = X;
	int expectedY = Y;

	int actualDefense = actor->GetDefense();
	int actualHealth = actor->GetHealth();
	CellColor_e actualColor = actor->GetColor();
	int actualX = actor->GetX();
	int actualY = actor->GetY();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(ActorTest, ShouldDecrementHealthByFifty)
{
	int expectedHealth = 50;

	actor->ChangeHealth(-50);

	int actualHealth = actor->GetHealth();

	CHECK_EQUAL(expectedHealth, actualHealth);
}

TEST(ActorTest, ShouldNotIncrementHealthAboveMaximumHealth)
{
	int expectedHealth = MaximumHealth;

	actor->ChangeHealth(40);

	int actualHealth = actor->GetHealth();

	CHECK_EQUAL(expectedHealth, actualHealth);
}

TEST(ActorTest, ShouldNotDecrementHealthBelowMinimumHealth)
{
	int expectedHealth = MinimumHealth;

	actor->ChangeHealth(-300);

	int actualHealth = actor->GetHealth();

	CHECK_EQUAL(expectedHealth, actualHealth);
}

TEST(ActorTest, ShouldNotIncrementDefenseAboveMaximumDefense)
{
	int expectedDefense = MaximumDefense;

	actor->ChangeDefense(100);

	int actualDefense = actor->GetDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ActorTest, ShouldNotDecrementDefenseBelowMinimumDefense)
{
	int expectedDefense = MinimumDefense;

	actor->ChangeDefense(-300);

	int actualDefense = actor->GetDefense();

	CHECK_EQUAL(expectedDefense, actualDefense);
}

TEST(ActorTest, ShouldMoveActorUp)
{
	RandomGeneratorShouldBeCalledAndReturn(1);

	int expectedNextX = X;
	int expectedNextY = Y - 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorRightUp)
{
	RandomGeneratorShouldBeCalledAndReturn(2);

	int expectedNextX = X + 1;
	int expectedNextY = Y - 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorRight)
{
	RandomGeneratorShouldBeCalledAndReturn(3);

	int expectedNextX = X + 1;
	int expectedNextY = Y;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorRightDown)
{
	RandomGeneratorShouldBeCalledAndReturn(4);

	int expectedNextX = X + 1;
	int expectedNextY = Y + 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorDown)
{
	RandomGeneratorShouldBeCalledAndReturn(5);

	int expectedNextX = X;
	int expectedNextY = Y + 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorLeftDown)
{
	RandomGeneratorShouldBeCalledAndReturn(6);

	int expectedNextX = X - 1;
	int expectedNextY = Y + 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorLeft)
{
	RandomGeneratorShouldBeCalledAndReturn(7);

	int expectedNextX = X - 1;
	int expectedNextY = Y;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}

TEST(ActorTest, ShouldMoveActorLeftUp)
{
	RandomGeneratorShouldBeCalledAndReturn(8);

	int expectedNextX = X - 1;
	int expectedNextY = Y - 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}
