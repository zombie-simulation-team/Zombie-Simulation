/*
 * FakeRandomGenerator.h
 *
 *  Created on: Apr 5, 2019
 *      Author: javiervega
 */

#ifndef FAKERANDOMGENERATOR_H_
#define FAKERANDOMGENERATOR_H_

#include "I_Random.h"

class FakeRandomGenerator: public I_Random
{
private:
	int randomValue;

public:
	FakeRandomGenerator();
	virtual ~FakeRandomGenerator();
	int GenerateRandom(int start, int end);
	void SetRandomNumber(int value);
};

#endif /* FAKERANDOMGENERATOR_H_ */
