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
		trap = new Trap(10, 10);
	}

	void teardown()
	{
		delete trap;
	}
};

TEST(TrapTest, ShouldInitializeATrap)
{
	int expectedAttack = 100;
	int expectedDefense = 100;
	CellColor_e expectedColor = Black;

	int actualAttack = trap->getAttack();
	int actualDefense = trap->getDefense();
	CellColor_e actualColor = trap->getColor();

	CHECK_EQUAL(expectedAttack, actualAttack);
	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedColor, actualColor);
}

TEST(TrapTest, ShouldSetTheAttack)
{
	int expectedAttack = 45;

	trap->setAttack(45);

	int actualAttack = trap->getAttack();

	CHECK_EQUAL(expectedAttack, actualAttack);
}

TEST(TrapTest, ShouldSetAttackEqualToMaximum)
{
	int expectedAttack = 100;

	trap->setAttack(200);

	int actualAttack = trap->getAttack();

	CHECK_EQUAL(expectedAttack, actualAttack);
}

TEST(TrapTest, ShouldSetAttackEqualToMinimum)
{
	int expectedAttack = 0;

	trap->setAttack(-200);

	int actualAttack = trap->getAttack();

	CHECK_EQUAL(expectedAttack, actualAttack);
}

TEST(TrapTest, ShouldInitializeATrapWithPositionAndAttackAmmount)
{
	Trap *testTrap = new Trap(3, 7, 60);

	int expectedAttack = 60;
	int expectedDefense = 100;
	CellColor_e expectedColor = Black;

	int actualAttack = testTrap->getAttack();
	int actualDefense = testTrap->getDefense();
	CellColor_e actualColor = testTrap->getColor();

	CHECK_EQUAL(expectedAttack, actualAttack);
	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedColor, actualColor);

	delete testTrap;
}
