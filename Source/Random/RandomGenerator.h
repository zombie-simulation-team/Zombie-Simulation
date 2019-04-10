/*
 * RandomGenerator.h
 *
 *  Created on: Apr 4, 2019
 *      Author: javiervega
 */

#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_

#include "I_Random.h"

class RandomGenerator: public I_Random
{
public:
	RandomGenerator();
	virtual ~RandomGenerator();
	int GenerateRandom(int start, int end);
};

#endif /* RANDOMGENERATOR_H_ */
