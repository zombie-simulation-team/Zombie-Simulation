/*
 * Continent.h
 *
 *  Created on: Mar 29, 2019
 *      Author: javiervega
 */

#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <iostream>
#include "Environment.h"
#include "Cell.h"
#include "EmptyCell.h"
#include "I_Random.h"
#include "RandomGenerator.h"
#include "Zombie.h"
#include "Trap.h"
#include "Resource.h"
#include "Human.h"

class Continent: public Environment
{
private:
	int size;
	Cell ***shape;
	Continents_e name;
	I_Random *randomGenerator;
	CellPosition_t *positions;
	int randomizationLevel;
	void InitializeZombies(int zombieCount);
	void InitializeTraps(int trapCount);
	void InitializeResources(int resourceCount);
	void InitializeHumans(int humanCount);
	void InitializeShape(
			int humanCount,
			int zombieCount,
			int trapCount,
			int resourceCount);
	void ShuffleCellTickOrder();

public:
	Continent(
			int size,
			Continents_e name,
			int humanCount,
			int zombieCount,
			int trapCount,
			int resourceCount,
			I_Random *randomGenerator,
			int randomizationLevel = 0);
	Cell*** GetShape();
	int GetSize();
	std::string GetName();
	void SetName(Continents_e name);
	void Tick();
	void CheckMove(Cell *cell);
	virtual ~Continent();
	bool Finished();
	bool ZombiesWon();
	bool HumansWon();
};

#endif /* CONTINENT_H_ */
