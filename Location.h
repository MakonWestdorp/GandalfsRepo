#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string> 
using namespace std; 

class Location : public Game {
    private:
        // Variables describing a location
        string name; 
        string description;
        string asciiDescription; 
    public:
        Location(); // Default constructor 
        Location(string name, string description, string asciiDescription); // Constructor 
        void showLocation(); // Displays the locations details 
        void travelToLocation(string destination); // Changes the location 
};

#endif 