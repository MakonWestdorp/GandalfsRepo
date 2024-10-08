#include "Forest.h"
#include "Location.h"
#include "Town.h"
#include "Arena.h"
#include "Entity.h"
#include "Game.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread> 
using namespace chrono;
using namespace this_thread;

Forest::Forest() : Location()
{
    enemies = nullptr; 
    treasure = false; 
}

Forest::Forest(string name, string description, string asciiDescription) : Location(name,description,asciiDescription)
{
    treasure = false; 
    enemies = new Entity*[5];
    for (int i = 0; i < 5; i++) {
        enemies[i] = Entity();
    }
}

void Forest::travelToLocation(Game &game, Location *location)
{
    int cashOnHand = 0; // Temporary - Needed for function call
    if (location->getName() == game.viewLocations()[0]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,cashOnHand);
    }
}

void Forest::showLocation(Game &game, int &cashOnHand)
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,cashOnHand);
    cout << "1. Travel to Town" << endl << "2. Explore" << endl << "3. Search for treasure" 
         << endl << "4. Fight Enemy" << endl << divider << endl;
    cin >> userDecision; 
    cout << divider << endl;

    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[0]);
            break;
        case 2:
            sleep_for(seconds(1));
            explore();
            break;
        case 3: 
            sleep_for(seconds(1));

            break;
        case 4:
            sleep_for(seconds(1));

            break;
        default:
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }
}

void Forest::callForBattle(Entity *player, Entity *enemy)
{

}

void Forest::explore()
{   
    


    for (int i = 0; i < 5; i++) {
        enemies[i] = Entity();
    }
    cout << "New Enemies have appeared!" << endl; 
}
