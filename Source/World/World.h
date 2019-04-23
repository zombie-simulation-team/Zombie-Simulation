//
// Am I god if I have created the World Class? - god
//

#ifndef WORLD_H
#define WORLD_H

#include "Continent.h"
#include "Environment.h"
#include "RandomGenerator.h"

using namespace std; 

class World : public Environment
{
private:
	int numOfContinents;
	Continent ** continents;
	int dayElapsed;
	int continentCount;
	//Continents_e allContinentArr [7];
	void RandomContinentOrder();
	static const int DefaultContinentSize = 20;

public:
//	World();
	World(int numOfContinents);
	World(Continents_e startingContinent);
	World(int numOfContinents, I_Random *randomInterface);
	int GetDays();
	void SetDays();
	void Draw();
	void Tick();
	virtual ~World();
};

#endif // WORLD_H
