/*
 * FakeRandomGenerator.h
 *
 *  Created on: Apr 5, 2019
 *      Author: javiervega
 */

#ifndef RANDOMGENERATOR_MOCK_H_
#define RANDOMGENERATOR_MOCK_H_

#include "../Random/I_Random.h"
//#include "../../../Testing/CppUTest/src/CppUTestExt/MockSupport.h"

class RandomGenerator_Mock: public I_Random
{
public:
	RandomGenerator_Mock();
	virtual ~RandomGenerator_Mock();
	int GenerateRandom(int start, int end);
};

#endif /* RANDOMGENERATOR_MOCK_H_ */
