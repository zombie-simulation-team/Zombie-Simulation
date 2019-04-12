//
// Am I god if I have created the World Class? - god
//

#include "World.h"

//If no user configuration is set call the default constructor

//World::World()
//{
////	srand( (unsigned)time( NULL ) );
//
//	numOfContinents = rand() % 7 + 1;
//	dayElapsed = 0;
//
//	RandomContinentOrder();
//	continents = new Continent*[numOfContinents];
//	for(int i = 0; i < numOfContinents; i++){
//		continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
//	}
//}

//World::World(int numOfContinents){
//	srand( (unsigned)time( NULL ) );
//
//	this->numOfContinents = numOfContinents;
//	dayElapsed = 0;
//	RandomContinentOrder();
//
//	continents = new Continent*[numOfContinents];
//	for(int i = 0; i < numOfContinents; i++){
//		continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
//	}
//}

//World::World(Continents_e startingContinent){
//	srand( (unsigned)time( NULL ) );
//	numOfContinents = rand() % 7 + 1;
//	dayElapsed = 0;
//	RandomContinentOrder();
//	continents = new Continent*[numOfContinents];
//	for(int i = 0; i < numOfContinents; i++){
//		if(i == 0){
//			continents[i] = new Continent(10, startingContinent, rand()%5, rand()%5, rand()%5,rand()%5);
//		}else if(allContinentArr[i] == startingContinent){
//			continents[i] = new Continent(10, allContinentArr[i+1], rand()%5, rand()%5, rand()%5,rand()%5);
//		}else{
//			continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
//		}
//	}
//}

World::World(
		int numOfContinents,
		Continents_e startingContinent,
		I_Random *randomInterface)
	: Environment(0, 0, 0, 0)
{
	this->numOfContinents = numOfContinents;
	dayElapsed = 0;
	//RandomContinentOrder();
	continentCount = numOfContinents;

	continents = new Continent*[numOfContinents];

	for(int i = 0; i < numOfContinents; i++){
		continents[i] = new Continent(
				DefaultContinentSize,
				startingContinent,
				this->GetHumanCount(),
				this->GetZombieCount(),
				this->GetTrapCount(),
				this->GetResourceCount(),
				randomInterface);
	}
}

World::~World()
{
	for(int i = 0; i < numOfContinents; i++) {
		delete continents[i];
	}
	delete[] continents;
}

int World::GetDays()
{
	return dayElapsed;
}

void World::SetDays(){
    dayElapsed++;
}

void World::Draw(){
    //TODO: implement Draw
}

void World::Tick(){
    //TODO:implement Tick
}

//Returns the 7 Continent in random order
//void World::RandomContinentOrder()
//{
//	allContinentArr = {
//		Africa,
//		Antartica,
//		Asia,
//		Australia,
//		Europe,
//		NorthAmerica,
//		SouthAmerica
//	};
//
//	for (int i = 0; i < 100; i++) {
//		int randElm1 = rand()%7;
//		int randElm2 = rand()%7;
//
//		Continents_e temp = allContinentArr[randElm1];
//
//		allContinentArr[randElm1] = allContinentArr[randElm2];
//		allContinentArr[randElm2] = temp;
//	}
//}

