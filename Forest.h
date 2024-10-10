#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Game; 
class Entity;
class Enemy;
class Player;

class Forest : public Location {
    private:
        Enemy **enemies;
        bool treasure; 
    public:
        Forest();
        Forest(string name, string description, string asciiDescription, int numBossesDefeated);
        void travelToLocation(Game &game, Location *location,Player *player, int numBossesDefeated);
        void showLocation(Game &game,Player *player, int numBossesDefeated);
        void callForBattle(Game &game, Player *player, Enemy *enemy, int numBossesDefeated);
        void explore(int numBossesDefeated);
        void openTreasure(Player *player, int numBossesDefeated);
        void viewEnemies(Game &game, Player *player, int numBossesDefeated);
}; 

#endif