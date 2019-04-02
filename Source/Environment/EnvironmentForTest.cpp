/*
 * EnvironmentForTest.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#include "EnvironmentForTest.h"
#include <stdio.h>

EnvironmentForTest::EnvironmentForTest(
		int hCount,			//human count
		int zCount,			//zombie count
		int tCount,			//trap count
		int rCount)			//resource count
	: Environment(hCount, zCount, tCount, rCount)
{
}

EnvironmentForTest::~EnvironmentForTest(){}

void EnvironmentForTest::Tick()
{
	//do-nothing
}
