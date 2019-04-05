/*
 * FakeRandomGenerator.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: javiervega
 */

#include "FakeRandomGenerator.h"

FakeRandomGenerator::FakeRandomGenerator()
{
	randomValue = 0;
}

FakeRandomGenerator::~FakeRandomGenerator()
{
}

int FakeRandomGenerator::GenerateRandom(int start, int end)
{
	return randomValue;
}

void FakeRandomGenerator::SetRandomNumber(int value)
{
	randomValue = value;
}
