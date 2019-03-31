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
	void initializeShape();

public:
	Continent(int size, string name);
	Continent(int, string, int, int, int, int);
	Cell*** getShape();
	int getSize();
	string getName();
	void setName(string);
	void tick();
	virtual ~Continent();
};

#endif /* CONTINENT_H_ */
