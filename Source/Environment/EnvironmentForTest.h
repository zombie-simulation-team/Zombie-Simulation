/*
 * EnvironmentForTest.h
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#ifndef ENVIRONMENT_ENVIRONMENTFORTEST_H_
#define ENVIRONMENT_ENVIRONMENTFORTEST_H_

#include "Environment.h"

class EnvironmentForTest: public Environment
{
	public:
		EnvironmentForTest(int, int, int, int);
		virtual ~EnvironmentForTest();
		void tick();
};

#endif /* ENVIRONMENT_ENVIRONMENTFORTEST_H_ */
