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
		int resourceCount,
		I_Random *randomGenerator)
	: Environment(
			humanCount,
			zombieCount,
			trapCount,
			resourceCount)
{
	this->size = size;
	this->name = name;
	this->randomGenerator = randomGenerator;

	InitializeShape(
			humanCount,
			zombieCount,
			trapCount,
			resourceCount);
}

Continent::~Continent()
{
	for(int y = 0; y < size; y++) {
		for(int x = 0; x < size; x++) {
			delete shape[y][x];
		}
		delete[] shape[y];
	}
	delete[] shape;
}

void Continent::Tick()
{
	Cell **list = new Cell*[size*size];

	int count = 0;
	for(int y = 0; y < size; y++) {
		for(int x = 0; x < size; x++) {
			Cell *current = shape[y][x];

			list[count] = current;
			count++;
		}
	}

	for(int i = 0; i < count; i++)
	{
		Cell *current = list[i];
		current->Tick();

		CheckMove(current);
	}
	delete[] list;
}

void Continent::InitializeShape(
		int humanCount,
		int zombieCount,
		int trapCount,
		int resourceCount)
{
	shape = new Cell**[size];

	for(int y = 0; y < size; y++) {
		shape[y] = new Cell*[size];

		for(int x = 0; x < size; x++) {
			shape[y][x] = new EmptyCell(y, x, true);
		}
	}

	InitializeZombies(zombieCount);
	InitializeTraps(trapCount);
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
		Cell *targetCell = shape[cell->GetNextY()][cell->GetNextX()];

		bool isNextPositionEmpty = targetCell->GetColor() == Transparent;

		if(isNextPositionEmpty)
		{
			int x = cell->GetX();
			int y = cell->GetY();

			cell->SetX(cell->GetNextX());
			cell->SetY(cell->GetNextY());

			shape[cell->GetNextY()][cell->GetNextX()] = cell;
			cell->SetNextX(-1);
			cell->SetNextY(-1);

			targetCell->SetX(x);
			targetCell->SetY(y);
			shape[y][x] = targetCell;
		}
	}
	else
	{
		cell->SetNextX(-1);
		cell->SetNextY(-1);
	}
}

void Continent::InitializeZombies(int zombieCount)
{
	while(zombieCount > 0)
	{
		int x = randomGenerator->GenerateRandom(0, size - 1);
		int y = randomGenerator->GenerateRandom(0, size - 1);

		delete shape[y][x];

		shape[y][x] = new Zombie(x, y,randomGenerator);

		zombieCount--;
	}
}

void Continent::InitializeTraps(int trapCount)
{
	while(trapCount > 0)
	{
		int x = randomGenerator->GenerateRandom(0, size - 1);
		int y = randomGenerator->GenerateRandom(0, size - 1);

		delete shape[y][x];

		shape[y][x] = new Trap(x, y);

		trapCount--;
	}
}

