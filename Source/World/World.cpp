//
// Am I god if I have created the World Class? - god
//

#include "World.h"

//If no user configuration is set call the default constructor


World::World()
{
    srand( (unsigned)time( NULL ) );
    numOfContinents = rand() % 7 + 1;
    elapsedDays = 0;
    RandomContinentOrder();
    continents = new Continents*[numOfContinents];
    for(int i = 0; i < numOfContinents; i++){
        continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
    }
}

World::World(int numOfContinents){
    srand( (unsigned)time( NULL ) );
    this->numOfContinents = numOfContinents;
    elapsedDays = 0;
    RandomContinentOrder();
    continents = new Continents*[numOfContinents];
    for(int i = 0; i < numOfContinents; i++){
        continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
    }
}

World::World(Continents_e startingContinent){
    srand( (unsigned)time( NULL ) );
    numOfContinents = rand() % 7 + 1;
    elapsedDays = 0;
    RandomContinentOrder();
    continents = new Continents*[numOfContinents];
    for(int i = 0; i < numOfContinents; i++){
        if(i == 0){
            continents[i] = new Continent(10, startingContinent, rand()%5, rand()%5, rand()%5,rand()%5);
        }else if(allContinentsArr[i] == startingContinent){
            continents[i] = new Continent(10, allContinentArr[i+1], rand()%5, rand()%5, rand()%5,rand()%5);
        }else{
            continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
        }
    }
}
World::World(int numOfContinents, Continents_e startingContinent){
    srand( (unsigned)time( NULL ) );
    this->numOfContinents = numOfContinents;
    elapsedDays = 0;
    RandomContinentOrder();
    continents = new Continents*[numOfContinents];
    for(int i = 0; i < numOfContinents; i++){
        if(i == 0){
            continents[i] = new Continent(10, startingContinent, rand()%5, rand()%5, rand()%5,rand()%5);
        }else if(allContinentsArr[i] == startingContinent){
            continents[i] = new Continent(10, allContinentArr[i+1], rand()%5, rand()%5, rand()%5,rand()%5);
        }else{
            continents[i] = new Continent(10, allContinentArr[i], rand()%5, rand()%5, rand()%5,rand()%5);
        }
    }
}

World::GetDays(){
    return elapsedDays;
}

World::SetDays(){
    elapsedDays++;
}

World::Draw(){
    //TODO: implement Draw
}

World::Tick(){
    //TODO:implement Tick
}

//Returns the 7 continents in random order
World::RandomContinentOrder(){

   allContinentArr = { 
        Africa,
        Antartica,
        Asia,
        Australia,
        Europe,
        NorthAmerica,
        SouthAmerica 
    };
   
   for (int i = 0; i < 100; i++) {
    int randElm1 = rand()%7;
    int randElm2 = rand()%7;
    Continents_e temp = allContinentArr[randElm];
    allContinentArr[randElm] = allContinentArr[randElm2];
    allContinentArr[randElm2] = temp;
   }
}

Continent::~Continent()
{
	for(int i = 0; i < numOfContinents; i++) {
		delete[] continents[i];
	}
	delete[] continents;
}