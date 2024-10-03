#include "Location.h"
#include "Game.h"

Location::Location()
{
    this->name = "No name";
    this->description = "No description";
    this->asciiDescription = "No ascii description";
}

Location::Location(string name, string description, string asciiDescription)
{
    this->name = name;
    this->description = description; 
    this->asciiDescription = asciiDescription;   
}

void Location::showLocation()
{   
    // Divider to seperate elements of the visual
    string divider = "+------------------------------------------------------------------+"; 

    // Clears terminal
    cout << endl << endl << endl << endl << endl << endl; 

    // Temporary cout for visuals
    cout << divider << endl << this->name << endl << divider << 
    endl << this->description << endl << divider << endl; 
    // Ascii description will be added later, either in place or along with description
    
}

void Location::travelToLocation(Game& game, Location destination)
{
    game.travel(destination);
}

string Location::getName()
{
    return this->name;
}

