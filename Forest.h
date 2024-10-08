#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Game; 
class Enemy;

class Forest : public Location {
    private:
        Enemy *enemies;
        bool treasure; 
    public:
        Forest();
        Forest(string name, string description, string asciiDescription, int numBossesDefeated);
        void travelToLocation(Game &game, Location *location);
        void showLocation(Game &game,int &cashOnHand,Entity *player, Enemy *enemy, int numBossesDefeated);
        void callForBattle(Entity *player, Enemy *enemy);
        void explore(int numBossesDefeated);
        void openTreasure(Entity *player, int numBossesDefeated);
        void viewEnemies(Game &game, int &cashOnHand);
}; 

#endif