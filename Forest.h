#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>
#include "Location.h"

class Forest : public Location {
    private:
    public:
        Forest();
        Forest(string name, string description, string asciiDescription);
}; 

#endif