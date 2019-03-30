/*
 * Environment.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: Javier Vega
 */

#include "Environment.h"

Environment::Environment()
{
	humanCount = 0;
	zombieCount = 0;
	resourceCount = 0;
	trapCount = 0;
}

Environment::Environment(
		int hCount,			//human count
		int zCount,			//zombie count
		int tCount,			//trap count
		int rCount)			//resource count
{
	humanCount = hCount;
	zombieCount = zCount;
	resourceCount = rCount;
	trapCount = tCount;
}

Environment::~Environment() {}

void Environment::setHumanCount(int count)
{
	humanCount = count;
}

void Environment::setZombiCount(int count)
{
	zombieCount = count;
}

void Environment::setResourceCount(int count)
{
	resourceCount = count;
}

void Environment::setTrapCount(int count)
{
	trapCount = count;
}

int Environment::getHumanCount()
{
	return humanCount;
}

int Environment::getZombiCount()
{
	return zombieCount;
}

int Environment::getResourceCount()
{
	return resourceCount;
}

int Environment::getTrapCount()
{
	return trapCount;
}
