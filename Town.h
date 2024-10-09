#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <string>
#include "Location.h"

class Game;
class Shop; 
class Entity;
class Enemy;
class Player;

class Town : public Location {
    public: 
    Town();
    Town(string name, string description, string asciiDescription);
    void travelToLocation(Game &game, Location *location, Player *player, Enemy *enemy,int numBossesDefeated);
    void enterShop(Shop &shopName, Player *player);
    void showLocation(Game &game, Player *player, Enemy *enemy, int numBossesDefeated);


};

#endif