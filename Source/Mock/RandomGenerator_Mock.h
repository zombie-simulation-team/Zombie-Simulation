/*
 * FakeRandomGenerator.h
 *
 *  Created on: Apr 5, 2019
 *      Author: javiervega
 */

#ifndef FAKERANDOMGENERATOR_H_
#define FAKERANDOMGENERATOR_H_

#include "I_Random.h"
#include "CppUTestExt/MockSupport.h"

class RandomGenerator_Mock: public I_Random
{
private:
	int randomValue;

public:
	RandomGenerator_Mock();
	virtual ~RandomGenerator_Mock();
	int GenerateRandom(int start, int end);
};

#endif /* FAKERANDOMGENERATOR_H_ */
