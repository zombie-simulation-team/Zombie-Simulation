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

	int actualAttack = trap->GetAttack();
	int actualDefense = trap->GetDefense();
	CellColor_e actualColor = trap->GetColor();

	CHECK_EQUAL(expectedAttack, actualAttack);
	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedColor, actualColor);
}

TEST(TrapTest, ShouldSetTheAttack)
{
	int expectedAttack = 45;

	trap->SetAttack(45);

	int actualAttack = trap->GetAttack();

	CHECK_EQUAL(expectedAttack, actualAttack);
}

TEST(TrapTest, ShouldSetAttackEqualToMaximum)
{
	int expectedAttack = 100;

	trap->SetAttack(200);

	int actualAttack = trap->GetAttack();

	CHECK_EQUAL(expectedAttack, actualAttack);
}

TEST(TrapTest, ShouldSetAttackEqualToMinimum)
{
	int expectedAttack = 0;

	trap->SetAttack(-200);

	int actualAttack = trap->GetAttack();

	CHECK_EQUAL(expectedAttack, actualAttack);
}

TEST(TrapTest, ShouldInitializeATrapWithPositionAndAttackAmmount)
{
	Trap *testTrap = new Trap(3, 7, 60);

	int expectedAttack = 60;
	int expectedDefense = 100;
	CellColor_e expectedColor = Black;

	int actualAttack = testTrap->GetAttack();
	int actualDefense = testTrap->GetDefense();
	CellColor_e actualColor = testTrap->GetColor();

	CHECK_EQUAL(expectedAttack, actualAttack);
	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedColor, actualColor);

	delete testTrap;
}
