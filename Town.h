#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <string>
#include "Location.h"

class Game;
class Shop; 
class Entity;
class Entity;

class Town : public Location {
    public: 
    Town();
    Town(string name, string description, string asciiDescription);
    void travelToLocation(Game &game, Location *location, Entity *player, Enemy *enemy);
    void enterShop(Shop &shopName, int &cashOnHand);
    void showLocation(Game &game, int &cashOnHand, Entity *player, Enemy *enemy, int numBossesDefeated);


};

#endif