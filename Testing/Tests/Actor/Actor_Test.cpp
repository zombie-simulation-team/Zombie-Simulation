/*!
 * @file
 * @brief Test for Trap class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "ActorForTest.h"

enum
{
	MaximumHealth = 100,
	MinimumHealth = 0,
	MaximumDefense = 100,
	MinimumDefense = 0,
	SomeDefenseValue = 20
};

TEST_GROUP(ActorTest)
{
	ActorForTest *actor;

	void setup()
	{
		actor = new ActorForTest(4, 5, Green, MaximumHealth, SomeDefenseValue);
	}

	void teardown()
	{
		delete actor;
	}
};

TEST(ActorTest, ShouldInitializeAnActor)
{
	int expectedDefense = SomeDefenseValue;
	int expectedHealth = MaximumHealth;
	CellColor_e expectedColor = Green;
	int expectedX = 4;
	int expectedY = 5;

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
