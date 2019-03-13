/*
 * Environment.h
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#ifndef SOURCE_ENVIRONMENT_ENVIRONMENT_H_
#define SOURCE_ENVIRONMENT_ENVIRONMENT_H_

class Environment
{
private:
	int humanCount;
	int zombieCount;
	int trapCount;
	int resourceCount;

public:
	Environment();
	virtual ~Environment();
	void setZombiCount(int);
	void setHumanCount(int);
	void setTrapCount(int);
	void setResourceCount(int);
	int getZombiCount();
	int getHumanCount();
	int getTrapCount();
	int getResourceCount();
	virtual void tick() = 0;
};

#endif /* SOURCE_ENVIRONMENT_ENVIRONMENT_H_ */
