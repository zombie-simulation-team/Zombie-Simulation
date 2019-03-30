/*!
 * @file
 * @brief Test for Trap class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Trap.h"

TEST_GROUP(TrapTest)
{
	Trap *trap;

	void setup()
	{
		trap = new Trap();
	}

	void teardown()
	{
		delete trap;
	}
};

TEST(TrapTest, ShouldInitializeATrap)
{
	int actualDefence = 100;

	int expectedDefence = trap->getDefence();

	CHECK_EQUAL(actualDefence, expectedDefence);
}

TEST(TrapTest, ShouldSetTheAttack)
{
	int actualAttack = 45;

	trap->setAttack(45);

	int expectedAttack = trap->getAttack();

	CHECK_EQUAL(actualAttack, expectedAttack);
}

TEST(TrapTest, ShouldSetAttackEqualToMaximum)
{
	int actualAttack = 100;

	trap->setAttack(200);

	int expectedAttack = trap->getAttack();

	CHECK_EQUAL(actualAttack, expectedAttack);
}

TEST(TrapTest, ShouldSetAttackEqualToMinimum)
{
	int actualAttack = 0;

	trap->setAttack(-200);

	int expectedAttack = trap->getAttack();

	CHECK_EQUAL(actualAttack, expectedAttack);
}
