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
        void travelToLocation(Game &game, Location *location, Player *player, int numBossesDefeated);
        void showLocation(Game &game, Player *player, int numBossesDefeated);
        void viewPlayerStats(Game &game, Player *player, int numBossesDefeated);
        void callForBattle(Player *player);
};

#endif