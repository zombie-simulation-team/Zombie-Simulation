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
	void SetZombieCount(int zombieCount);
	void SetHumanCount(int humanCount);
	void SetTrapCount(int trapCount);
	void SetResourceCount(int resourceCount);
	int GetZombieCount();
	int GetHumanCount();
	int GetTrapCount();
	int GetResourceCount();
	virtual void Tick() = 0;
};

#endif /* ENVIRONMENT_H_ */
