#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Game; 

class Forest : public Location {
    private:
    public:
        Forest();
        Forest(string name, string description, string asciiDescription);
        void travelToLocation(Game &game, Location *location);
        void showLocation(Game &game,int &cashOnHand);
}; 

#endif