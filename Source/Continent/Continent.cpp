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

void Continent::Tick()
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

int Continent::GetSize()
{
	return size;
}

std::string Continent::GetName()
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

Cell*** Continent::GetShape()
{
	return shape;
}

void Continent::SetName(Continents_e name)
{
	this->name = name;
}

void Continent::CheckMove(Cell *cell)
{
	if((cell->GetNextX() >= 0 && cell->GetNextX() < size) &&
			(cell->GetNextY() >= 0 && cell->GetNextY() < size))
	{
		Cell *targetCell = shape[cell->GetNextX()][cell->GetNextY()];

		if(targetCell->GetColor() == Transparent)
		{
			int x = cell->GetX();
			int y = cell->GetY();

			cell->SetX(cell->GetNextX());
			cell->SetY(cell->GetNextY());

			shape[cell->GetNextX()][cell->GetNextY()] = cell;
			cell->SetNextX(-1);
			cell->SetNextY(-1);

			targetCell->SetX(x);
			targetCell->SetY(y);
			shape[x][y] = targetCell;
		}
	}
	else
	{
		cell->SetNextX(-1);
		cell->SetNextY(-1);
	}
}

