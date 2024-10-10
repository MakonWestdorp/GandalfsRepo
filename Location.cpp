#include "Location.h"
#include "Game.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

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

void Location::showLocation(Game &game, Player *player, int numBossesDefeated)
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

void Location::travelToLocation(Game& game, Location *destination,Player *player, int numBossesDefeated)
{   
    game.travel(destination);
    game.viewCurrentLocation()->showLocation(game,player,numBossesDefeated);
}

string Location::getName()
{
    return this->name;
}

