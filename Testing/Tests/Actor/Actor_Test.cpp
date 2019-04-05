/*!
 * @file
 * @brief Test for Trap class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "ActorForTest.h"
#include "I_Random.h"
#include "FakeRandomGenerator.h"

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
	FakeRandomGenerator *random;
	I_Random *r;

	void setup()
	{
		random = new FakeRandomGenerator();
		r = (I_Random *)random;
		actor = new ActorForTest(
				X,
				Y,
				Green,
				MaximumHealth,
				SomeDefenseValue, r);
	}

	void teardown()
	{
		delete actor;
		delete random;
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
	random->SetRandomNumber(1);

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
	random->SetRandomNumber(2);

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
	random->SetRandomNumber(3);

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
	random->SetRandomNumber(4);

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
	random->SetRandomNumber(5);

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
	random->SetRandomNumber(6);

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
	random->SetRandomNumber(7);

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
	random->SetRandomNumber(8);

	int expectedNextX = X - 1;
	int expectedNextY = Y - 1;

	actor->Tick();

	int actualNextX = actor->GetNextX();
	int actualNextY = actor->GetNextY();

	CHECK_EQUAL(expectedNextX, actualNextX);
	CHECK_EQUAL(expectedNextY, actualNextY);
}
