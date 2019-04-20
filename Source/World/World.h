//
// Am I god if I have created the World Class? - god
//

#ifndef ZOMBIE_SIMULATION_WORLD_H
#define ZOMBIE_SIMULATION_WORLD_H

#include "Continent.h"
#include "Environment.h"
#include<string>
#include <stdlib.h>  

using namespace std; 

enum Map_e {
} Map_e;

class World: public Environment {
private:
    int numOfContinents;
    Continent ** continents;
    int dayElapsed;
    int continentCount;
    Continents_e allContinentArr [7];
    void RandomContinentOrder();

public:
    World();
    World(int numOfContinents);
    World(Continents_e startingContinent);
    World(int numOfContinents,Continents_e startingContinent);
    int GetDays();
    void SetDays();
    void Draw();
    void tick();
    virtual ~World();
};


#endif //ZOMBIE_SIMULATION_WORLD_H
