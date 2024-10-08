#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Game; 
class Entity;

class Forest : public Location {
    private:
        Entity *enemies;
        bool treasure; 
    public:
        Forest();
        Forest(string name, string description, string asciiDescription);
        void travelToLocation(Game &game, Location *location);
        void showLocation(Game &game,int &cashOnHand,Entity *player, Entity *enemy, int &numBossesDefeated);
        void callForBattle(Entity *player, Entity *enemy);
        void explore();
        void openTreasure(Entity *player, int &numBossesDefeated);
        void viewEnemies(Game &game, int &cashOnHand);
}; 

#endif