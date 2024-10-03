#include "Arena.h"
#include "Location.h"
#include "Town.h"
#include "Forest.h"
#include "Game.h"


// Include libraries for pause and namepsaces
#include <chrono>
#include <thread> 
using namespace chrono;
using namespace this_thread;

Arena::Arena() : Location()
{
}

Arena::Arena(string name, string description, string asciiDescription) : Location(name,description,asciiDescription)
{
}

void Arena::travelToLocation(Game &game, Location *location)
{
    int cashOnHand = 0; // Temporary - Needed for function call
    if (location->getName() == game.viewLocations()[0]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,cashOnHand);
    }
}

void Arena::showLocation(Game &game, int &cashOnHand)
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,cashOnHand);
    cout << "1. Travel to Town" << endl << divider << endl;
    cin >> userDecision; 
    cout << divider << endl;
    
    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[0]);
            break;
        default:
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }
}
