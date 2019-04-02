/*
 * Continent.h
 *
 *  Created on: Mar 29, 2019
 *      Author: javiervega
 */

#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <iostream>
#include <string>
#include "Environment.h"
#include "Cell.h"
#include "EmptyCell.h"

class Continent: public Environment
{
private:
	int size;
	Cell ***shape;
	Continents_e name;
	void initializeShape();

public:
	Continent(
			int size,
			Continents_e name,
			int humanCount,
			int zombieCount,
			int trapCount,
			int resourceCount);
	Cell*** GetShape();
	int GetSize();
	std::string GetName();
	void SetName(Continents_e name);
	void Tick();
	void CheckMove(Cell *cell);
	virtual ~Continent();
};

#endif /* CONTINENT_H_ */
