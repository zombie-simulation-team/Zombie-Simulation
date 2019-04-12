/*!
 * @file
 * @brief Test for Continent class.
 */

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"
#include "Continent.h"
#include "RandomGenerator_Mock.h"

enum
{
	ValueToMoveDown = MoveDown,
	ValueToMoveLeft = MoveLeft,
	ValueToMoveRight = MoveRight,
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
};

TEST_GROUP(ContinentTest)
{
	Continent *continent;
	RandomGenerator_Mock *randomGeneratorMock;
	I_Random *randInterface;

	void setup()
	{
		randomGeneratorMock = new RandomGenerator_Mock();
		randInterface = (I_Random *)randomGeneratorMock;

		continent = new Continent(
				ContinentSize,
				NorthAmerica,
				0,
				0,
				0,
				0,
				randInterface);
	}

	void teardown()
	{
		delete continent;
		delete randomGeneratorMock;
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
					.withParameter("start", 1)
					.withParameter("end", 8)
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
			randInterface);

	Cell ***shape = cont->GetShape();

	int actualX = shape[3][3]->GetX();
	int actualY = shape[3][3]->GetY();

	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);

	delete cont;
}

TEST(ContinentTest, ShouldTickTheContinentAndAZombieMoveDownOneCell)
{
	ExpectZombieToBeInitializedWithPosition(SomeX, SomeY);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			0,
			0,
			randInterface);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveDown);

	cont->Tick();

	int expectedX = SomeX;
	int expectedY = SomeY + 1;
	int expectedColor = Red;

	int actualColor = shape[SomeY + 1][SomeX]->GetColor();
	int actualX = shape[SomeY + 1][SomeX]->GetX();
	int actualY = shape[SomeY + 1][SomeX]->GetY();

	CHECK_EQUAL(expectedColor, actualColor);
	CHECK_EQUAL(expectedX, actualX);
	CHECK_EQUAL(expectedY, actualY);

	delete cont;
}

TEST(ContinentTest, ShouldTickTheContinentAndAZombieMoveLeftOneCell)
{
	ExpectZombieToBeInitializedWithPosition(AnotherX, AnotherY);

	Continent *cont = new Continent(
			ContinentSize,
			NorthAmerica,
			0,
			ZombieCount,
			0,
			0,
			randInterface);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveLeft);

	cont->Tick();

	int expectedX = AnotherX - 1;
	int expectedY = AnotherY;
	int expectedColor = Red;

	int actualColor = shape[AnotherY][AnotherX - 1]->GetColor();
	int actualX = shape[AnotherY][AnotherX - 1]->GetX();
	int actualY = shape[AnotherY][AnotherX - 1]->GetY();

	CHECK_EQUAL(expectedColor, actualColor);
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
			randInterface);

	Cell ***actualShape = cont->GetShape();

	int zombieColor = Red;
	int actualColor = actualShape[SomeZombieY][SomeZombieX]->GetColor();
	CHECK_EQUAL(zombieColor, actualColor);

	int trapColor = Black;
	actualColor = actualShape[SomeTrapY][SomeTrapX]->GetColor();
	CHECK_EQUAL(trapColor, actualColor);

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
			randInterface);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);
	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveLeft);

	cont->Tick();

	int expectedX = AnotherX - 1;
	int expectedY = AnotherY;
	int expectedColor = Red;

	int actualColor = shape[AnotherY][AnotherX - 1]->GetColor();
	int actualX = shape[AnotherY][AnotherX - 1]->GetX();
	int actualY = shape[AnotherY][AnotherX - 1]->GetY();

	CHECK_EQUAL(expectedColor, actualColor);
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
			randInterface);

	Cell ***shape = cont->GetShape();

	RandomGeneratorShouldBeCalledAndReturn(ValueToMoveRight);

	cont->Tick();

	int expectedColor = Grey;
	int actualColor = shape[5][4]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

	expectedColor = Black;
	actualColor = shape[5][5]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

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
			randInterface);

	Cell ***shape = cont->GetShape();

	int expectedColor = Red;
	int actualColor = shape[5][4]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

	expectedColor = Black;
	actualColor = shape[7][5]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

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
			randInterface);

	Cell ***shape = cont->GetShape();

	int expectedColor = Red;
	int actualColor = shape[5][4]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

	expectedColor = Black;
	actualColor = shape[5][3]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

	expectedColor = White;
	actualColor = shape[7][5]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

	expectedColor = Green;
	actualColor = shape[9][7]->GetColor();
	CHECK_EQUAL(expectedColor, actualColor);

	delete cont;
}
