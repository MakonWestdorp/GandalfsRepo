#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string> 
using namespace std; 

class Location {
    private:
        string name; 
        string description;
        string asciiDescription; 
    public:
        Location(); 
        Location(string name, string description, string asciiDescription); 
        void showLocation(); 
        void travelToLocation(string destination);
};

#endif 