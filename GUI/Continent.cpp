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
		I_Random *randomGenerator,
		int randomizationLevel)
	: Environment(
			humanCount,
			zombieCount,
			trapCount,
			resourceCount)
{
	this->size = size;
	this->name = name;
	this->randomGenerator = randomGenerator;

	if(randomizationLevel < 0)
	{
		this->randomizationLevel = 0;
	}
	else if(randomizationLevel > 3)
	{
		this->randomizationLevel = 3;
	}
	else
	{
		this->randomizationLevel = randomizationLevel;
	}

	positions = new CellPosition_t[size * size];

	InitializeShape(
			humanCount,
			zombieCount,
			trapCount,
			resourceCount);

	if(randomizationLevel > 0)
	{
		ShuffleCellTickOrder();
	}
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

	delete []positions;
}

void Continent::Tick()
{
	int count = size * size;

	for(int i = 0; i < count; i++)
	{
		int x = positions[i].x;
		int y = positions[i].y;

		Cell *current = shape[y][x];
		current->Tick();
		CheckMove(current);
	}

	for(int i = 0; i < count; i++)
	{
		int x = positions[i].x;
		int y = positions[i].y;

		Cell *current = shape[y][x];

		if(current->IsHuman() || current->IsZombie())
		{
			Actor *actor = dynamic_cast<Actor*>(current);
			actor->SetMove(false);
		}
	}
}

void Continent::InitializeShape(
		int humanCount,
		int zombieCount,
		int trapCount,
		int resourceCount)
{
	shape = new Cell**[size];

	int index = 0;
	for(int y = 0; y < size; y++) {
		shape[y] = new Cell*[size];

		for(int x = 0; x < size; x++) {
			shape[y][x] = new EmptyCell(y, x, true);

			positions[index].x = x;
			positions[index].y = y;
			index++;
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

	if(current->HasMoved())
	{
		return;
	}

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
				delete current;
				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);

				this->SetZombieCount(this->GetZombieCount() - 1);
			}
			else if(next->IsZombie())
			{
				current->ResetNextPosition();

				zombie->Move();
				CheckMove(zombie);
				current->SetMove(true);
			}
			else if(next->IsHuman())
			{
				delete next;
				shape[nextY][nextX] = new Zombie(nextX, nextY, randomGenerator);

				current->ResetNextPosition();

				this->SetHumanCount(this->GetHumanCount() - 1);
				this->SetZombieCount(this->GetZombieCount() + 1);
				current->SetMove(true);
			}
			else if(next->IsTrap())
			{
				delete current;

				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);

				this->SetZombieCount(this->GetZombieCount() - 1);
			}
			else if(next->IsResource())
			{
				Resource *resource = dynamic_cast<Resource*>(next);

				if(resource->GetDefense() > 0)
				{
					resource->SetDefense(resource->GetDefense() - 50);
					current->ResetNextPosition();
					current->ResetDirections();
				}
				else
				{
					delete next;
					next = NULL;

					shape[nextY][nextX] = current;
					current->SetPosition(nextX, nextY);
					current->ResetNextPosition();

					next = new EmptyCell(currentX, currentY, true);
					shape[currentY][currentX] = next;

					this->SetResourceCount(this->GetResourceCount() - 1);
				}
				current->SetMove(true);
			}
			else if(next->IsEmpty())
			{
				delete next;
				next = NULL;

				shape[nextY][nextX] = current;
				current->SetPosition(nextX, nextY);
				current->ResetNextPosition();

				next = new EmptyCell(currentX, currentY, true);
				shape[currentY][currentX] = next;

				current->SetMove(true);
			}
		}
		else if(current->IsHuman())
		{
			Human *human = dynamic_cast<Human*>(current);

			if(human->GetHealth() == 0)
			{
				delete shape[currentY][currentX];
				shape[currentY][currentX] = new EmptyCell(currentX, currentY, true);

				this->SetHumanCount(this->GetHumanCount() - 1);
			}
			else if(next->IsHuman())
			{
				current->ResetNextPosition();
				current->Move();
				CheckMove(current);

				current->SetMove(true);
			}
			else if(next->IsZombie())
			{
				delete next;

				shape[nextY][nextX] = current;
				current->SetPosition(nextX, nextY);
				current->ResetNextPosition();

				next = new EmptyCell(currentX, currentY, true);
				shape[currentY][currentX] = next;

				this->SetZombieCount(this->GetZombieCount() - 1);

				current->SetMove(true);
			}
			else if(next->IsResource())
			{
				Resource *resource = dynamic_cast<Resource*>(next);

				int food = resource->GetFood();

				if(food > 0)
				{
					int foodNeeded = MaxHealth - human->GetHealth();

					if(food >= foodNeeded)
					{
						resource->SetFood(food - foodNeeded);
					}
					else
					{
						foodNeeded = resource->GetFood();
						resource->SetFood(0);
					}
					human->ChangeHealth(foodNeeded);
				}
				else
				{
					delete next;

					shape[nextY][nextX] = current;
					current->SetPosition(nextX, nextY);

					next = new EmptyCell(currentX, currentY, true);
					shape[currentY][currentX] = next;
					current->ResetNextPosition();
				}
				current->SetMove(true);
			}
			else if(next->IsEmpty())
			{
				shape[nextY][nextX] = current;
				current->SetPosition(nextX, nextY);
				current->ResetNextPosition();

				next->SetPosition(currentX, currentY);
				shape[currentY][currentX] = next;

				current->SetMove(true);
			}
			else if(next->IsTrap())
			{
				current->ResetNextPosition();

				human->Move();
				CheckMove(current);

				current->SetMove(true);
			}
			current->ResetDirections();
		}
	}
	else if(nextX == -1 && nextY == -1)
	{
		current->SetMove(true);
		current->ResetDirections();
		return;
	}
	else
	{
		if(current->IsHuman())
		{
			Human *human = dynamic_cast<Human*>(current);

			human->Move();
			CheckMove(human);
		}
		else if(current->IsZombie())
		{
			Zombie *zombie = dynamic_cast<Zombie*>(current);

			zombie->Move();
			CheckMove(zombie);
		}

		current->ResetNextPosition();
	}
}

void Continent::InitializeZombies(int zombieCount)
{
	int count = 0;

	while(zombieCount > 0)
	{
		int x = 0;
		int y = 0;
		if(count < 10)
		{
			do
			{
				x = randomGenerator->GenerateRandom(0, size - 1);
				y = randomGenerator->GenerateRandom(0, size - 1);

			} while(!shape[y][x]->IsEmpty());

			count++;
		}
		else
		{
			for(int i = x; i < (size * size); i++)
			{
				CellPosition_t current = positions[i];

				if(shape[current.y][current.x]->IsEmpty())
				{
					x = current.x;
					y = current.y;
					break;
				}
			}
		}

		delete shape[y][x];

		shape[y][x] = new Zombie(x, y,randomGenerator);

		zombieCount--;
	}
}

void Continent::InitializeTraps(int trapCount)
{
	int count = 0;

	while(trapCount > 0)
	{
		int x = 0;
		int y = 0;

		if(count < 10)
		{
			do
			{
				x = randomGenerator->GenerateRandom(0, size - 1);
				y = randomGenerator->GenerateRandom(0, size - 1);

			} while(!shape[y][x]->IsEmpty());

			count++;
		}
		else
		{
			for(int i = x; i < (size * size); i++)
			{
				CellPosition_t current = positions[i];

				if(shape[current.y][current.x]->IsEmpty())
				{
					x = current.x;
					y = current.y;
					break;
				}
			}
		}

		delete shape[y][x];

		shape[y][x] = new Trap(x, y);

		trapCount--;
	}
}

void Continent::InitializeResources(int resourceCount)
{
	int count = 0;
	while(resourceCount > 0)
	{
		int x = 0;
		int y = 0;

		if(count < 10)
		{
			do
			{
				x = randomGenerator->GenerateRandom(0, size - 1);
				y = randomGenerator->GenerateRandom(0, size - 1);

			} while(!shape[y][x]->IsEmpty());

			count++;
		}
		else
		{
			for(int i = x; i < (size * size); i++)
			{
				CellPosition_t current = positions[i];

				if(shape[current.y][current.x]->IsEmpty())
				{
					x = current.x;
					y = current.y;
					break;
				}
			}
		}

		delete shape[y][x];

		shape[y][x] = new Resource(x, y);

		resourceCount--;
	}
}

void Continent::InitializeHumans(int humanCount)
{
	int count = 0;

	while(humanCount > 0)
	{
		int x = 0;
		int y = 0;

		if(count < 10)
		{
			do
			{
				x = randomGenerator->GenerateRandom(0, size - 1);
				y = randomGenerator->GenerateRandom(0, size - 1);

			} while(!shape[y][x]->IsEmpty());

			count++;
		}
		else
		{
			for(int i = x; i < (size * size); i++)
			{
				CellPosition_t current = positions[i];

				if(shape[current.y][current.x]->IsEmpty())
				{
					x = current.x;
					y = current.y;
					break;
				}
			}
		}

		delete shape[y][x];
		shape[y][x] = new Human(x, y, randomGenerator);

		humanCount--;
	}
}

bool Continent::Finished()
{
	if(ZombiesWon())
	{
		return true;
	}
	else if(HumansWon())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Continent::ShuffleCellTickOrder()
{
	int fullSize = size * size;

	for(int r = 0; r < randomizationLevel; r++)
	{
		for (int i = 0; i < fullSize; i++)
		{
			int posOne = randomGenerator->GenerateRandom(0, fullSize - 1);
			int posTwo = randomGenerator->GenerateRandom(0, fullSize - 1);

			CellPosition_t temp = positions[posOne];
			positions[posOne] = positions[posTwo];
			positions[posTwo] = temp;
		}
	}
}

bool Continent::HumansWon()
{
	return this->GetZombieCount() == 0;
}

bool Continent::ZombiesWon()
{
	return this->GetHumanCount() == 0;
}
