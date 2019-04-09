/*!
* @file
* @brief Test for Human class.
*/
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Human.h"
#include "Resource.h"
#include "RandomGenerator_Mock.h"

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
	I_Random *randInterface;
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();
		randInterface = (I_Random *)randomGeneratorMock;

		human = new Human(X,Y, randInterface);
	}

	void teardown()
	{
		delete human;
		delete randomGeneratorMock;
	}
};

TEST(HumanTest, ShouldInitializeAHuman)
{
	int expectedDefense = DefaultDefense;
	int expectedHealth = DefaultHealth;
	CellColor_e expectedColor = Blue;
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
	Human *testHuman = new Human(8, 7, SomeHealthValue, SomeDefenseValue, randInterface);

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

  Human *testHuman = new Human(5,6, SomeHealthValue, SomeDefenseValue, randInterface);

  int expectedHealthChange = testHuman->GetHealth() + 20;
  testHuman->Eat(resource);
  int actualHealthChange = testHuman->GetHealth();

  CHECK_EQUAL(expectedHealthChange, actualHealthChange);

  delete testHuman;
  delete resource;

}
