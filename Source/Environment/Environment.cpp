/*
 * Environment.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: Javier Vega
 */

#include "Environment.h"

Environment::Environment(
		int humanCount,
		int zombieCount,
		int trapCount,
		int resourceCount)
{
	this->humanCount = humanCount;
	this->zombieCount = zombieCount;
	this->trapCount = trapCount;
	this->resourceCount = resourceCount;
}

Environment::~Environment() {}

void Environment::setHumanCount(int count)
{
	humanCount = count;
}

void Environment::setZombieCount(int count)
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

int Environment::getZombieCount()
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
