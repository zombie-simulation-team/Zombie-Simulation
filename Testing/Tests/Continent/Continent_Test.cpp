/*!
 * @file
 * @brief Test for Continent class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Continent.h"
#include "RandomGenerator_Mock.h"

#define Times
#define AndReturn
#define And

enum
{
	ValueToMoveDown = MoveDown,
	ValueToMoveLeft = MoveLeft,
	ValueToMoveRight = MoveRight,
	ValueToMoveUp = MoveUp,
	ContinentSize = 10,
	HumanCount = 1,
	ZombieCount = 1,
	TrapCount = 1,
	ResourceCount = 1,
	SomeX = 7,
	SomeY = 3,
	AnotherX = 9,
	AnotherY = 3,
	SomeZombieX = 2,
	SomeZombieY = 7,
	SomeTrapX = 8,
	SomeTrapY = 1,
	RandomizationLevelZero = 0,
	RandomizationLevelOne = 1,
	RandomizationLevelTwo = 2
};

TEST_GROUP(ContinentTest)
{
	Continent *continent;
	RandomGenerator_Mock *randomGeneratorMock;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();

		mock().disable();
		continent = new Continent(
				ContinentSize,
				NorthAmerica,
				0,
				0,
				0,
				0,
				randomGeneratorMock,
				RandomizationLevelZero);
		mock().enable();
	}

	void teardown()
	{
		delete continent;
		delete randomGeneratorMock;
		mock().clear();
	}

	void CheckShape(Cell ***actualShape)
	{
		bool expectedIsValid = true;
		int expectedX;
		int expectedY;

		for(int row = 0; row < ContinentSize; row++) {
			for(int col = 0; col < ContinentSize; col++) {
				EmptyCell *emptyCell = dynamic_cast<EmptyCell*>(actualShape[row][col]);

				expectedX = row;
				expectedY = col;

				int actualX = emptyCell->GetX();
				int actualY = emptyCell->GetY();
				bool actualIsValid = emptyCell->IsValid();

				CHECK_EQUAL(expectedX, actualX);
				CHECK_EQUAL(expectedY, actualY);
				CHECK_EQUAL(expectedIsValid, actualIsValid);
			}
		}
	}

	void ExpectZombieToBeInitializedWithPosition(int x, int y)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(x);

		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(y);
	}

	void ExpectTrapToBeInitializedWithPosition(int x, int y)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(x);

		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(y);
	}

	void ExpectResourceToBeInitializedWithPosition(int x, int y)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(x);

		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(y);
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

	void ExpectHumanToBeInitializedWithPosition(int x, int y)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(x);

		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", ContinentSize - 1)
					.andReturnValue(y);
	}

	void RandomGeneratorShouldBeCallToShuffleAndReturn(int val)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", 3)
					.andReturnValue(val);
	}

	void SwapCellsAt(int c1, int c2)
	{
		RandomGeneratorShouldBeCallToShuffleAndReturn(c1);
		RandomGeneratorShouldBeCallToShuffleAndReturn(c2);
	}

	void ExpectHumanToBeInitializedInLargerContinentWithPosition(int x, int y)
	{
		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", 119)
					.andReturnValue(x);

		mock().expectOneCall("GenerateRandom")
					.onObject(randomGeneratorMock)
					.withParameter("start", 0)
					.withParameter("end", 119)
					.andReturnValue(y);
	}
};

TEST(ContinentTest, ShouldInitializeAContinentWithEmptyCells)
{
	int expectedSize = ContinentSize;
	std::string expectedName = "North America";

	int actualSize = continent->GetSize();
	std::string actualName = continent->GetName();

	Cell ***actualShape = continent->GetShape();

	CHECK_EQUAL(expectedSize, actualSize);
	CHECK_EQUAL(expectedName, actualName);
	CheckShape(actualShape);
}

TEST(ContinentTest, ShouldSetContinentNameToEurope)
{
	continent->SetName(Europe);

	std::string expectedName = "Europe";
	std::string actualName = continent->GetName();

	CHECK_EQUAL(expectedName, actualName);
}

TEST(ContinentTest, ShouldInitializeAContinentWithAZombie)
{
	ExpectZombieToBeInitializedWithPosition(3, 3);

	int expectedX = 3;
	int expectedY = 3;

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			0,
			0,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	int actualX = shape[3][3]->GetX();
	int actualY = shape[3][3]->GetY();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);

	delete cont;
}

TEST(ContinentTest, ShouldInitializeAContinentWithOneZombieAndOneTrap)
{
	ExpectZombieToBeInitializedWithPosition(SomeZombieX, SomeZombieY);
	ExpectTrapToBeInitializedWithPosition(SomeTrapX, SomeTrapY);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			TrapCount,
			0,
			randomGeneratorMock);

	Cell ***actualShape = cont->GetShape();

	bool isZombie = true;
	bool actualType = actualShape[SomeZombieY][SomeZombieX]->IsZombie();
	CHECK_EQUAL(isZombie, actualType);

	bool isTrap = true;
	actualType = actualShape[SomeTrapY][SomeTrapX]->IsTrap();
	CHECK_EQUAL(isTrap, actualType);

	delete cont;
}

TEST(ContinentTest, ShouldAttemptToMoveZombieToAnInvalidPosition)
{
	ExpectZombieToBeInitializedWithPosition(AnotherX, AnotherY);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			0,
			0,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Cell *zombie = shape[AnotherY][AnotherX];
	zombie->Tick();
	cont->CheckMove(zombie);

	bool isZombie = true;
	int expectedX = AnotherX;
	int expectedY = AnotherY + 1;

	bool actualType = shape[AnotherY + 1][AnotherX]->IsZombie();
	int actualX = shape[AnotherY + 1][AnotherX]->GetX();
	int actualY = shape[AnotherY + 1][AnotherX]->GetY();

	CHECK_EQUAL(isZombie, actualType);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);

	delete cont;
}

TEST(ContinentTest, ShouldDestroyZombieWhenMovesIntoATrap)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectTrapToBeInitializedWithPosition(5, 5);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			TrapCount,
			0,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Cell *zombie = shape[5][4];
	zombie->Tick();
	cont->CheckMove(zombie);

	bool expected = true;
	bool actual = shape[5][4]->IsEmpty();
	CHECK_EQUAL(expected, actual);

	actual = shape[5][5]->IsTrap();
	CHECK_EQUAL(expected, actual);

	int expectedZombieCount = 0;
	int actualZombieCount = cont->GetZombieCount();
	CHECK_EQUAL(expectedZombieCount, actualZombieCount);

	delete cont;
}

TEST(ContinentTest, ShouldNotInitializeTrapAtPositionOfAZombie)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectTrapToBeInitializedWithPosition(4, 5);
	ExpectTrapToBeInitializedWithPosition(5, 7);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			TrapCount,
			0,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	bool expected = true;
	bool actual = shape[5][4]->IsZombie();
	CHECK_EQUAL(expected, actual);

	actual= shape[7][5]->IsTrap();
	CHECK_EQUAL(expected, actual);

	delete cont;
}

TEST(ContinentTest, ShouldInitializeOneTrapOneZombieOneResourceAndOneHuman)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectTrapToBeInitializedWithPosition(3, 5);
	ExpectResourceToBeInitializedWithPosition(5, 7);
	ExpectHumanToBeInitializedWithPosition(7, 9);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			HumanCount,
			ZombieCount,
			TrapCount,
			ResourceCount,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	bool expected = true;
	bool actual = shape[5][4]->IsZombie();

	int expectedZombieCount = 1;
	int actualZombieCount = cont->GetZombieCount();

	CHECK_EQUAL(expected, actual);
	CHECK_EQUAL(expectedZombieCount, actualZombieCount);

	actual= shape[5][3]->IsTrap();

	int expectedTrapCount = 1;
	int actualTrapCount = cont->GetTrapCount();

	CHECK_EQUAL(expected, actual);
	CHECK_EQUAL(expectedTrapCount, actualTrapCount);

	actual = shape[7][5]->IsResource();

	int expectedResourceCount = 1;
	int actualResourceCount = cont->GetResourceCount();

	CHECK_EQUAL(expected, actual);
	CHECK_EQUAL(expectedResourceCount, actualResourceCount);

	actual = shape[9][7]->IsHuman();

	int expectedHumanCount = 1;
	int actualHumanCount = cont->GetHumanCount();

	CHECK_EQUAL(expected, actual);
	CHECK_EQUAL(expectedHumanCount, actualHumanCount);

	delete cont;
}

TEST(ContinentTest, ShouldDecrementResourceDefenceWhenZombieMovesToItsPlace)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectResourceToBeInitializedWithPosition(4, 6);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			0,
			ResourceCount,
			randomGeneratorMock);

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveDown);

	Cell ***shape = cont->GetShape();

	Cell *zombie  = shape[5][4];
	zombie->Tick();
	cont->CheckMove(zombie);

	bool expected = true;
	bool actual = shape[6][4]->IsResource();
	CHECK_EQUAL(expected, actual);

	actual = shape[5][4]->IsZombie();
	CHECK_EQUAL(expected, actual);

	int expectedResourceCount = 1;
	int actualResourceCount = cont->GetResourceCount();
	CHECK_EQUAL(expectedResourceCount, actualResourceCount);

	Resource *resource = dynamic_cast<Resource*>(shape[6][4]);

	int expectedResourceDefense = 50;
	int actualResourceDefense = resource->GetDefense();
	CHECK_EQUAL(expectedResourceDefense, actualResourceDefense);

	delete cont;
}

TEST(ContinentTest, ShouldDestroyResourceWhenZombieMovesToItsTwoTimes)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectResourceToBeInitializedWithPosition(4, 6);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			0,
			ResourceCount,
			randomGeneratorMock);

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveDown);
	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveDown);
	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveDown);

	Cell ***shape = cont->GetShape();

	Actor *zombie  = dynamic_cast<Actor*>(shape[5][4]);
	zombie->Tick();
	cont->CheckMove(zombie);
	zombie->SetMove(false);

	zombie->Tick();
	cont->CheckMove(zombie);
	zombie->SetMove(false);

	zombie->Tick();
	cont->CheckMove(zombie);
	zombie->SetMove(false);

	bool expected = true;
	bool actual = shape[6][4]->IsZombie();
	CHECK_EQUAL(expected, actual);

	actual = shape[5][4]->IsEmpty();
	CHECK_EQUAL(expected, actual);

	int expectedResourceCount = 0;
	int actualResourceCount = cont->GetResourceCount();
	CHECK_EQUAL(expectedResourceCount, actualResourceCount);

	delete cont;
}

TEST(ContinentTest, ShouldConvertHuamnToZombieWhenZombieMovesUpToItsPlace)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectHumanToBeInitializedWithPosition(4, 4);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			HumanCount,
			ZombieCount,
			0,
			0,
			randomGeneratorMock);

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveUp);

	Cell ***shape = cont->GetShape();

	Cell *zombie = shape[5][4];
	zombie->Tick();
	cont->CheckMove(zombie);

	bool expected = true;
	bool actual = shape[5][4]->IsZombie();
	CHECK_EQUAL(expected, actual);

	actual = shape[4][4]->IsZombie();
	CHECK_EQUAL(expected, actual);

	int expectedZombieCount = 2;
	int actualZombieCount = cont->GetZombieCount();
	CHECK_EQUAL(expectedZombieCount, actualZombieCount);

	int expectedHumanCount = 0;
	int actualHumanCount = cont->GetHumanCount();
	CHECK_EQUAL(expectedHumanCount, actualHumanCount);

	delete cont;
}

TEST(ContinentTest, ShouldDestroyAZombieWhenAHumanMovesToItsPlace)
{
	ExpectZombieToBeInitializedWithPosition(4, 5);
	ExpectHumanToBeInitializedWithPosition(4, 4);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			HumanCount,
			ZombieCount,
			0,
			0,
			randomGeneratorMock);

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveDown);

	Cell ***shape = cont->GetShape();

	Cell *human = shape[4][4];
	human->Tick();
	cont->CheckMove(human);

	bool expected = true;
	bool actual = shape[5][4]->IsHuman();
	CHECK_EQUAL(expected, actual);

	actual = shape[4][4]->IsEmpty();
	CHECK_EQUAL(expected, actual);

	int expectedZombieCount = 0;
	int actualZombieCount = cont->GetZombieCount();
	CHECK_EQUAL(expectedZombieCount, actualZombieCount);

	delete cont;
}

TEST(ContinentTest, ShouldDestroyAHumanWhenItsHealthDropsDownToZero)
{
	ExpectHumanToBeInitializedInLargerContinentWithPosition(0, 0);

	Continent *cont = new Continent(
			120,
			NorthAmerica,
			HumanCount,
			0,
			0,
			0,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalled(100 Times, AndReturn ValueToMoveDown);

	for(int i = 0; i < 100; i++)
	{
		Human *human = dynamic_cast<Human*>(shape[i][0]);
		human->Tick();
		cont->CheckMove(human);
		human->SetMove(false);
	}

	Cell *cell = shape[100][0];

	bool expected = false;
	bool actual = cell->IsHuman();
	CHECK_EQUAL(expected, actual);

	int expectedHumanCount = 0;
	int actualHumanCount = cont->GetHumanCount();
	CHECK_EQUAL(expectedHumanCount, actualHumanCount);

	delete cont;
}

TEST(ContinentTest, HumanShouldGetAmountOfNeededFoodFromResource)
{
	ExpectResourceToBeInitializedWithPosition(0, 4);
	ExpectHumanToBeInitializedWithPosition(0, 0);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			HumanCount,
			0,
			0,
			ResourceCount,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalled(4 Times, AndReturn ValueToMoveDown);

	for(int i = 0; i < 4; i++)
	{
		Human *human = dynamic_cast<Human*>(shape[i][0]);
		human->Tick();
		cont->CheckMove(human);
		human->SetMove(false);
	}

	Cell *cell = shape[4][0];

	bool expected = true;
	bool actual = cell->IsResource();
	CHECK_EQUAL(expected, actual);

	expected = true;
	actual = shape[3][0]->IsHuman();
	CHECK_EQUAL(expected, actual);

	Human *human = dynamic_cast<Human*>(shape[3][0]);

	int expectedHumanHealth = 100;
	int actualHumanHealth = human->GetHealth();
	CHECK_EQUAL(expectedHumanHealth, actualHumanHealth);

	Resource *resource = dynamic_cast<Resource*>(shape[4][0]);
	int expectedFood = 96;
	int actualFood = resource->GetFood();
	CHECK_EQUAL(expectedFood, actualFood);

	delete cont;
}

TEST(ContinentTest, HumanShouldNotMoveToATrap)
{
	ExpectTrapToBeInitializedWithPosition(3, 1);
	ExpectHumanToBeInitializedWithPosition(2, 1);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			HumanCount,
			0,
			TrapCount,
			0,
			randomGeneratorMock);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Human *human = dynamic_cast<Human*>(shape[1][2]);
	human->Tick();
	cont->CheckMove(human);
	human->SetMove(false);

	bool expected = true;
	bool actual = shape[2][3]->IsHuman();
	CHECK_EQUAL(expected, actual);

	delete cont;
}

TEST(ContinentTest, ShouldShuffleThePositionForCellToBeTickedAtInitialization)
{
	SwapCellsAt(1, And 3);
	SwapCellsAt(2, And 0);
	SwapCellsAt(2, And 1);
	SwapCellsAt(2, And 3);

	Continent *cont = new Continent(
			2,
			NorthAmerica,
			0,
			0,
			0,
			0,
			randomGeneratorMock,
			RandomizationLevelOne);

	delete cont;
}

TEST(ContinentTest, ShouldShuffleThePositionForCellToBeTickedTwiceAtInitialization)
{
	SwapCellsAt(1, And 3);
	SwapCellsAt(2, And 0);
	SwapCellsAt(2, And 1);
	SwapCellsAt(2, And 3);
	SwapCellsAt(0, And 1);
	SwapCellsAt(1, And 3);
	SwapCellsAt(2, And 0);
	SwapCellsAt(2, And 1);

	Continent *cont = new Continent(
			2,
			NorthAmerica,
			0,
			0,
			0,
			0,
			randomGeneratorMock,
			RandomizationLevelTwo);

	delete cont;
}

TEST(ContinentTest, HumanShouldNotMoveWhenSuroundedByOtherHumansInACorner)
{
	ExpectHumanToBeInitializedWithPosition(0, 0);
	ExpectHumanToBeInitializedWithPosition(1, 0);
	ExpectHumanToBeInitializedWithPosition(0, 1);
	ExpectHumanToBeInitializedWithPosition(1, 1);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			4,
			0,
			0,
			0,
			randomGeneratorMock,
			RandomizationLevelZero);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Human *human = dynamic_cast<Human*>(shape[0][0]);
	human->Tick();
	cont->CheckMove(human);
	human->SetMove(false);

	bool expected = true;
	bool actual = shape[0][0]->IsHuman();
	CHECK_EQUAL(expected, actual);

	delete cont;
}

TEST(ContinentTest, HumanShouldNotMoveWhenSuroundedByOtherHumans)
{
	ExpectHumanToBeInitializedWithPosition(0, 0);
	ExpectHumanToBeInitializedWithPosition(0, 1);
	ExpectHumanToBeInitializedWithPosition(1, 0);
	ExpectHumanToBeInitializedWithPosition(1, 1);
	ExpectHumanToBeInitializedWithPosition(2, 0);
	ExpectHumanToBeInitializedWithPosition(2, 1);
	ExpectHumanToBeInitializedWithPosition(2, 2);
	ExpectHumanToBeInitializedWithPosition(1, 2);
	ExpectHumanToBeInitializedWithPosition(0, 2);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			9,
			0,
			0,
			0,
			randomGeneratorMock,
			RandomizationLevelZero);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Human *human = dynamic_cast<Human*>(shape[1][1]);
	human->Tick();
	cont->CheckMove(human);
	human->SetMove(false);

	bool expected = true;
	bool actual = shape[1][1]->IsHuman();
	CHECK_EQUAL(expected, actual);

	delete cont;
}

TEST(ContinentTest, ZombieShouldNotMoveWhenSuroundedByOtherZombiesInACorner)
{
	ExpectZombieToBeInitializedWithPosition(0, 0);
	ExpectZombieToBeInitializedWithPosition(1, 0);
	ExpectZombieToBeInitializedWithPosition(0, 1);
	ExpectZombieToBeInitializedWithPosition(1, 1);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			4,
			0,
			0,
			randomGeneratorMock,
			RandomizationLevelZero);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Zombie *zombie = dynamic_cast<Zombie*>(shape[0][0]);
	zombie->Tick();
	cont->CheckMove(zombie);
	zombie->SetMove(false);

	bool expected = true;
	bool actual = shape[0][0]->IsZombie();
	CHECK_EQUAL(expected, actual);

	delete cont;
}

TEST(ContinentTest, ZombieShouldNotMoveWhenSuroundedByOtherZombies)
{
	ExpectZombieToBeInitializedWithPosition(0, 0);
	ExpectZombieToBeInitializedWithPosition(0, 1);
	ExpectZombieToBeInitializedWithPosition(1, 0);
	ExpectZombieToBeInitializedWithPosition(1, 1);
	ExpectZombieToBeInitializedWithPosition(2, 0);
	ExpectZombieToBeInitializedWithPosition(2, 1);
	ExpectZombieToBeInitializedWithPosition(2, 2);
	ExpectZombieToBeInitializedWithPosition(1, 2);
	ExpectZombieToBeInitializedWithPosition(0, 2);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			9,
			0,
			0,
			randomGeneratorMock,
			RandomizationLevelZero);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	Zombie *zombie = dynamic_cast<Zombie*>(shape[1][1]);
	zombie->Tick();
	cont->CheckMove(zombie);
	zombie->SetMove(false);

	bool expected = true;
	bool actual = shape[1][1]->IsZombie();
	CHECK_EQUAL(expected, actual);

	delete cont;
}
