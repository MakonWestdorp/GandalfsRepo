#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Game;

class Arena : public Location {
    private:
    public:
        Arena();
        Arena(string name, string description, string asciiDescription);
        void travelToLocation(Game &game, Location *location, Player *player, Enemy *enemy, int numBossesDefeated);
        void showLocation(Game &game, Player *player, Enemy *enemy, int numBossesDefeated);
        void viewPlayerStats(Game &game, Player *player, Enemy *enemy, int numBossesDefeated);
        void callForBattle(Player *player, Enemy *enemy);
};

#endif