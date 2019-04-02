/*
 * Continent.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: javiervega
 */

#include "Continent.h"

Continent::Continent(
		int size,
		Continents_e name,
		int humanCount,
		int zombieCount,
		int trapCount,
		int resourceCount)
	: Environment(
			humanCount,
			zombieCount,
			trapCount,
			resourceCount)
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

std::string Continent::getName()
{
	switch(name)
	{
		case Africa:
			return "Africa";
		case Antartica:
			return "Antartica";
		case Asia:
			return "Asia";
		case Australia:
			return "Australia";
		case Europe:
			return "Europe";
		case NorthAmerica:
			return "North America";
		case SouthAmerica:
			return "South America";
	}
	return "";
}

Cell*** Continent::getShape()
{
	return shape;
}

void Continent::setName(Continents_e name)
{
	this->name = name;
}

void Continent::CheckMove(Cell *cell)
{
	if((cell->getNextX() >= 0 && cell->getNextX() < size) &&
			(cell->getNextY() >= 0 && cell->getNextY() < size))
	{
		Cell *targetCell = shape[cell->getNextX()][cell->getNextY()];

		if(targetCell->getColor() == Transparent)
		{
			int x = cell->getX();
			int y = cell->getY();

			cell->setX(cell->getNextX());
			cell->setY(cell->getNextY());

			shape[cell->getNextX()][cell->getNextY()] = cell;
			cell->setNextX(-1);
			cell->setNextY(-1);

			targetCell->setX(x);
			targetCell->setY(y);
			shape[x][y] = targetCell;
		}
	}
	else
	{
		cell->setNextX(-1);
		cell->setNextY(-1);
	}
}

