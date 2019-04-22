/*!
* @file
* @brief Test for Human class.
*/
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Human.h"
#include "Resource.h"
#include "RandomGenerator_Mock.h"

#define Times
#define AndReturn

enum
{
	SomeDefenseValue = 30,
	SomeHealthValue = 40,
	X = 3,
	Y = 3
};

TEST_GROUP(HumanTest)
{
	Human *human;
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();

		human = new Human(X,Y, randomGeneratorMock);
	}

	void teardown()
	{
		delete human;
		delete randomGeneratorMock;
	}

	void RandomGeneratorShouldBeCalledAndReturn(int val)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", MoveUp)
					.withParameter("end", MoveLeftUp)
					.andReturnValue(val);
	}

	void RandomGeneratorShouldBeCalled(int n, int val)
	{
		mock().expectNCalls(n, "GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", MoveUp)
					.withParameter("end", MoveLeftUp)
					.andReturnValue(val);
	}

	void ShouldTick(Human *human, int n)
	{
		for(int i = 0; i < n; i++)
		{
			human->Tick();
		}
	}
};

TEST(HumanTest, ShouldInitializeAHuman)
{
	int expectedDefense = DefaultDefense;
	int expectedHealth = DefaultHealth;
	CellColor_e expectedColor = Green;
	int expectedX = 3;
	int expectedY = 3;

	int actualDefense = human->GetDefense();
	int actualHealth = human->GetHealth();
	CellColor_e actualColor = human->GetColor();
	int actualX = human->GetX();
	int actualY = human->GetY();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);
	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);
}

TEST(HumanTest, ShouldInitializeAHumanWithGivenHealthAndDefense)
{
	Human *testHuman = new Human(8, 7, SomeHealthValue, SomeDefenseValue, randomGeneratorMock);

	int expectedDefense = SomeDefenseValue;
	int expectedHealth = SomeHealthValue;

	int actualDefense = testHuman->GetDefense();
	int actualHealth = testHuman->GetHealth();

	CHECK_EQUAL(expectedDefense, actualDefense);
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testHuman;
}

TEST(HumanTest, ShouldIncreaseHumanHealthBy20WhenFindingResourceCellToEat)
{
  Resource *resource = new Resource(4,4,20);

  Human *testHuman = new Human(5,6, SomeHealthValue, SomeDefenseValue, randomGeneratorMock);

  int expectedHealthChange = testHuman->GetHealth() + 20;
  testHuman->Eat(resource);
  int actualHealthChange = testHuman->GetHealth();

  CHECK_EQUAL(expectedHealthChange, actualHealthChange);

  delete testHuman;
  delete resource;

}

TEST(HumanTest, ShouldDecrementHealthByOneAfterOneTick)
{
	Human *testHuman = new Human(4, 3, randomGeneratorMock);

	RandomGeneratorShouldBeCalledAndReturn(MoveDown);

	testHuman->Tick();

	int expectedHealth = DefaultHealth - 1;
	int actualHealth = testHuman->GetHealth();

	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testHuman;
}

TEST(HumanTest, ShouldDecrementHealthToZeroAfter20Tick)
{
	Human *testHuman = new Human(4, 3, randomGeneratorMock);

	RandomGeneratorShouldBeCalled(100 Times, AndReturn MoveDown);

	ShouldTick(testHuman, 100 Times);

	int expectedHealth = 0;
	int actualHealth = testHuman->GetHealth();
	CHECK_EQUAL(expectedHealth, actualHealth);

	delete testHuman;
}
