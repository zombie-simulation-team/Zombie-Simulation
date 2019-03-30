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

using namespace std;

class Continent: public Environment
{
private:
	int size;
	Cell ***shape;
	string name;
	void initializeShape(int);

public:
	Continent();
	Continent(int size, string name);
	Cell*** getShape();
	int getSize();
	string getName();
	void tick();
	virtual ~Continent();
};

#endif /* CONTINENT_H_ */
