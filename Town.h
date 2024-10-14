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
    void travelToLocation(Game &game, Location *location, Player *player,int numBossesDefeated);
    void enterShop(Shop &shopName, Player *player, Game &game);
    void showLocation(Game &game, Player *player, int numBossesDefeated);


};

#endif