/*
 * RandomGenerator.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: javiervega
 */

#include "RandomGenerator.h"
#include <stdlib.h>
#include <time.h>

RandomGenerator::RandomGenerator()
{
	srand(time(NULL));
}

RandomGenerator::~RandomGenerator()
{
}

int RandomGenerator::GenerateRandom(int start, int end)
{
	return (rand() % end + start);
}
