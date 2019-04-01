/*
 * Environment.h
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

typedef enum Continents_e
{
	Africa,
	Antartica,
	Asia,
	Australia,
	Europe,
	NorthAmerica,
	SouthAmerica
} Continents_e;

class Environment
{
private:
	int humanCount;
	int zombieCount;
	int trapCount;
	int resourceCount;

public:
	Environment(
			int humanCount,
			int zombieCount,
			int trapCount,
			int resourceCount);
	virtual ~Environment();
	void setZombieCount(int zombieCount);
	void setHumanCount(int humanCount);
	void setTrapCount(int trapCount);
	void setResourceCount(int resourceCount);
	int getZombieCount();
	int getHumanCount();
	int getTrapCount();
	int getResourceCount();
	virtual void tick() = 0;
};

#endif /* ENVIRONMENT_H_ */
