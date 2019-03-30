/*
 * Continent.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: javiervega
 */

#include "Continent.h"
#include<stdio.h>

Continent::Continent()
{
	size = 10;
	initializeShape(size);
}

Continent::Continent(int size, string name)
{
	this->size = size;
	initializeShape(size);
	this->name = name;
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

void Continent::initializeShape(int size)
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

