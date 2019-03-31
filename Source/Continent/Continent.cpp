/*
 * Continent.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: javiervega
 */

#include "Continent.h"

Continent::Continent(int size, string name)
{
	this->size = size;
	this->name = name;
	initializeShape();
}

Continent::Continent(
		int size,
		string name,
		int hCount,			//human count
		int zCount,			//zombie count
		int tCount,			//trap count
		int rCount) 		//resource count
	: Environment(hCount, zCount, tCount, rCount)
{
	this->size = size;
	this->name = name;
	initializeShape();
}

Continent::~Continent()
{
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			delete shape[i][j];
		}
		delete[] shape[i];
	}
	delete[] shape;
}

void Continent::tick()
{

}

void Continent::initializeShape()
{
	shape = new Cell**[size];

	for(int i = 0; i < size; i++) {
		shape[i] = new Cell*[size];

		for(int j = 0; j < size; j++) {
			shape[i][j] = new EmptyCell(i, j, true);
		}
	}
}

int Continent::getSize()
{
	return size;
}

string Continent::getName()
{
	return name;
}

Cell*** Continent::getShape()
{
	return shape;
}

void Continent::setName(string name)
{
	this->name = name;
}

