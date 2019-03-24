/*
 * Resources.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: javiervega
 */

#include "Resource.h"

Resource::Resource()
{
	food = 0;

}

Resource::~Resource()
{
}

int Resource::getFood()
{
	return food;
}

void Resource::setFood(int amount)
{
	if(amount >= minFood && amount <= maxFood)
	{
		food = amount;
	}
	else if(amount > maxFood)
	{
		food = maxFood;
	}
	else if(amount < minFood)
	{
		food = minFood;
	}
}

void Resource::tick()
{
	//do nothing
}
