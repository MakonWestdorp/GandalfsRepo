#include "Town.h"
#include "Location.h"
#include "Game.h"
#include "Shop.h"
#include "Forest.h"
#include "Arena.h"
#include "Entity.h"
#include "Enemy.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread> 
using namespace chrono;
using namespace this_thread;

Town::Town() : Location()
{
}

Town::Town(string name, string description, string asciiDescription) : Location(name, description, asciiDescription)
{
}

void Town::travelToLocation(Game &game, Location *location, Entity *player, Enemy *enemy)
{   
    int cashOnHand = 0; // Temporary - Needed for function call
    if (location->getName() == game.viewLocations()[1]->getName() || 
        location->getName() == game.viewLocations()[2]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,cashOnHand,player,enemy,1);
    }
}

void Town::enterShop(Shop &shopName, int &cashOnHand)
{   
    while (shopName.showShopInterface(cashOnHand) == true) {}
}

void Town::showLocation(Game &game, int &cashOnHand, Entity *player, Enemy *enemy, int numBossesDefeated)
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,cashOnHand,player,enemy,1);
    cout << "1. Travel to Weapons Shop" << endl << "2. Travel to Magic Shop" << endl 
         << "3. Travel to Armour Shop" << endl << "4. Travel to General Shop" << endl
         << "5. Travel to Forest" << endl << "6. Travel to Arena" << endl << "7. Save Game (N/A)" 
         << endl << "8. Save and Leave Game" << endl << divider << endl;
    cin >> userDecision; 
    cout << divider << endl; 
    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[0],cashOnHand);
            break;
        case 2:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[1],cashOnHand);
            break;
        case 3:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[2],cashOnHand);
            break;
        case 4:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[3],cashOnHand);
            break;
        case 5:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[1],player,enemy);
            break;
        case 6:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[2],player,enemy);
            break;
        case 7:
            sleep_for(seconds(1));
            cout << "N/A" << endl << divider << endl;
            break;
        case 8: 
            sleep_for(seconds(1));
            game.endGame();
            break;
        default: 
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }

}
