#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Arena : public Location {
    private:
    public:
        Arena();
        Arena(string name, string description, string asciiDescription);
};

#endif