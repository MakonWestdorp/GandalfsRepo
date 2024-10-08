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

void Arena::travelToLocation(Game &game, Location *location, Entity *player, Enemy *enemy)
{
    int cashOnHand = 0; // Temporary - Needed for function call
    if (location->getName() == game.viewLocations()[0]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,cashOnHand,player,enemy,1);
    }
}

void Arena::showLocation(Game &game, int &cashOnHand, Entity *player, Enemy *enemy, int numBossesDefeated)
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,cashOnHand,player,enemy,1);
    cout << "1. Travel to Town" << endl << divider << endl;
    cin >> userDecision; 
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000, '\n');
      userDecision = 2;
    }
    cout << divider << endl;
    
    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[0],player,enemy);
            break;
        default:
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }
}
