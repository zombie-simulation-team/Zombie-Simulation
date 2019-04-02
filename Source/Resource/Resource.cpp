/*
 * Resources.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: javiervega
 */

#include "Resource.h"

Resource::Resource(int x, int y)
	: Obstacle(x, y, color)
{
	food = defaultFood;
}

Resource::Resource(int x, int y, int food)
	: Obstacle(x, y, color)
{
	this->food = food;
}

Resource::~Resource()
{
}

int Resource::GetFood()
{
	return food;
}

void Resource::SetFood(int amount)
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

void Resource::Tick()
{
	//do nothing
}
