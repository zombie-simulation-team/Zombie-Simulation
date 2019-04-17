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
//			s.push(current);
			count++;
		}
	}

//	while(!s.empty())
//	{
//		Cell *current = s.top();
//		current->Tick();
//		CheckMove(current);
//		s.pop();
//	}

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
	InitializeResources(resourceCount);
	InitializeHumans(humanCount);
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
		default:
			break;
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
	if(!cell->IsZombie() && !cell->IsHuman())
	{
		return;
	}

	Actor *current = dynamic_cast<Actor*>(cell);

	int nextX = current->GetNextX();
	int nextY = current->GetNextY();

	if((nextX >= 0 && nextX < size) && (nextY >= 0 && nextY < size))
	{
		int currentX = current->GetX();
		int currentY = current->GetY();

		Cell *next = shape[nextY][nextX];

		if(current->IsZombie())
		{
			Zombie *zombie = dynamic_cast<Zombie*>(current);

			if(zombie->GetHealth() == 0)
			{
				delete shape[currentY][currentX];
				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);

				this->SetZombieCount(this->GetZombieCount() - 1);
			}
			else if(next->IsZombie())
			{
				current->ResetNextPosition();

				current->Move();
				CheckMove(current);
			}
			else if(next->IsHuman())
			{
				delete shape[nextY][nextX];
				shape[nextY][nextX] = new Zombie(nextX, nextY, randomGenerator);

				current->ResetNextPosition();

				this->SetHumanCount(this->GetHumanCount() - 1);
				this->SetZombieCount(this->GetZombieCount() + 1);
			}
			else if(next->IsTrap())
			{
				delete shape[currentY][currentX];

				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);

				this->SetZombieCount(this->GetZombieCount() - 1);
			}
			else if(next->IsResource())
			{
				delete shape[nextY][nextX];

				shape[nextY][nextX] = current;
				current->SetPosition(nextX, nextY);
				current->ResetNextPosition();

				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);

				this->SetResourceCount(this->GetResourceCount() - 1);
			}
			else if(next->IsEmpty())
			{
				shape[nextY][nextX] = current;
				current->SetPosition(nextX, nextY);
				current->ResetNextPosition();

				next->SetPosition(currentX, currentY);
				shape[currentY][currentX] = next;
			}
		}
//		else if(current->IsHuman())
//		{
//			Human *human = dynamic_cast<Human*>(current);
//
//			if(human->GetHealth() == 0)
//			{
//				delete shape[currentY][currentX];
//				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);
//
//				this->SetHumanCount(this->GetHumanCount() - 1);
//			}
//			else if(next->IsHuman())
//			{
//				current->ResetNextPosition();
//				current->Move();
//				CheckMove(current);
//			}
//			else if(next->IsZombie())
//			{
//				delete shape[nextY][nextX];
//
//				shape[nextY][nextX] = current;
//				current->SetPosition(nextX, nextY);
//
//				current->ResetNextPosition();
//
//				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);
//
//				this->SetZombieCount(this->GetZombieCount() - 1);
//			}
//			else if(next->IsResource())
//			{
//				Resource *resource = dynamic_cast<Resource*>(next);
//
//				int food = resource->GetFood();
//				human->ChangeHealth(food);
//
//				delete shape[nextY][nextX];
//
//				shape[nextY][nextX] = current;
//				current->SetPosition(nextX, nextY);
//				current->ResetNextPosition();
//
//				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);
//			}
//			else if(next->IsEmpty())
//			{
//				shape[nextY][nextX] = current;
//				current->SetPosition(nextX, nextY);
//				current->ResetNextPosition();
//
//				next->SetPosition(currentX, currentY);
//				shape[currentY][currentX] = next;
//			}
//			else if(next->IsTrap())
//			{
//				current->ResetNextPosition();
//
//				human->Move();
//				CheckMove(current);
//			}
//		}
	}
	else
	{
		if(current->IsHuman())
		{
			Human *human = dynamic_cast<Human*>(current);

			human->Move();
			CheckMove(current);
		}
		else if(current->IsZombie())
		{
			Zombie *zombie = dynamic_cast<Zombie*>(current);

			zombie->Move();
			CheckMove(current);
		}

		current->ResetNextPosition();
	}
}

void Continent::InitializeZombies(int zombieCount)
{
	while(zombieCount > 0)
	{
		int x = 0;
		int y = 0;

		do
		{
			x = randomGenerator->GenerateRandom(0, size - 1);
			y = randomGenerator->GenerateRandom(0, size - 1);
		} while(!shape[y][x]->IsEmpty());

		delete shape[y][x];

		shape[y][x] = new Zombie(x, y,randomGenerator);

		zombieCount--;
	}
}

void Continent::InitializeTraps(int trapCount)
{
	while(trapCount > 0)
	{
		int x = 0;
		int y = 0;

		do
		{
			x = randomGenerator->GenerateRandom(0, size - 1);
			y = randomGenerator->GenerateRandom(0, size - 1);
		} while(!shape[y][x]->IsEmpty());

		delete shape[y][x];

		shape[y][x] = new Trap(x, y);

		trapCount--;
	}
}

void Continent::InitializeResources(int resourceCount)
{
	while(resourceCount > 0)
	{
		int x = 0;
		int y = 0;

		do
		{
			x = randomGenerator->GenerateRandom(0, size - 1);
			y = randomGenerator->GenerateRandom(0, size - 1);
		} while(!shape[y][x]->IsEmpty());

		delete shape[y][x];

		shape[y][x] = new Resource(x, y);

		resourceCount--;
	}
}

void Continent::InitializeHumans(int humanCount)
{
	while(humanCount > 0)
	{
		int x = 0;
		int y = 0;

		do
		{
			x = randomGenerator->GenerateRandom(0, size - 1);
			y = randomGenerator->GenerateRandom(0, size - 1);
		} while(!shape[y][x]->IsEmpty());

		delete shape[y][x];

		shape[y][x] = new Human(x, y, randomGenerator);

		humanCount--;
	}
}

bool Continent::Finished()
{
	if(this->GetZombieCount() == 0)
	{
		return true;
	}
//	else if(this->GetHumanCount() == 0)
//	{
//		return true;
//	}
	else
	{
		return false;
	}
}

