/*
 * FakeRandomGenerator.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: javiervega
 */

#include "RandomGenerator_Mock.h"

RandomGenerator_Mock::RandomGenerator_Mock()
{
	randomValue = 0;
}

RandomGenerator_Mock::~RandomGenerator_Mock()
{
}

int RandomGenerator_Mock::GenerateRandom(int start, int end)
{
	return mock().actualCall("GenerateRandom")
			.onObject(this)
			.withParameter("start", start)
			.withParameter("end", end)
			.returnValue().getIntValue();
}
