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

void Environment::SetHumanCount(int count)
{
	humanCount = count;
}

void Environment::SetZombieCount(int count)
{
	zombieCount = count;
}

void Environment::SetResourceCount(int count)
{
	resourceCount = count;
}

void Environment::SetTrapCount(int count)
{
	trapCount = count;
}

int Environment::GetHumanCount()
{
	return humanCount;
}

int Environment::GetZombieCount()
{
	return zombieCount;
}

int Environment::GetResourceCount()
{
	return resourceCount;
}

int Environment::GetTrapCount()
{
	return trapCount;
}
