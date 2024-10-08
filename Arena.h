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
        void travelToLocation(Game &game, Location *location, Entity *player, Enemy *enemy);
        void showLocation(Game &game, int &cashOnHand, Entity *player, Enemy *enemy, int numBossesDefeated);
};

#endif