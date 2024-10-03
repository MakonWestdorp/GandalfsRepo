#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <string>
#include "Location.h"

class Game;
class Shop;

class Town : public Location {
    public: 
    Town();
    Town(string name, string description, string asciiDescription);
    void travelToLocation(Game &game, Location *location);
    void enterShop(Shop &shopName, int &cashOnHand);
    void showLocation(Game &game,int &cashOnHand);


};

#endif