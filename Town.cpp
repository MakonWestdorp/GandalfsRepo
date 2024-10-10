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

void Town::travelToLocation(Game &game, Location *location, Player *player, int numBossesDefeated)
{   
    if (location->getName() == game.viewLocations()[1]->getName() || 
        location->getName() == game.viewLocations()[2]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,player,numBossesDefeated);
    }
}

void Town::enterShop(Shop &shopName, Player *player)
{   
    while (shopName.showShopInterface(player) == true) {}
}

void Town::showLocation(Game &game, Player *player, int numBossesDefeated)
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,player,numBossesDefeated);
    cout << "1. Travel to Weapons Shop" << endl << "2. Travel to Magic Shop" << endl 
         << "3. Travel to Armour Shop" << endl << "4. Travel to General Shop" << endl
         << "5. Travel to Forest" << endl << "6. Travel to Arena" << endl << "7. Save Game (N/A)" 
         << endl << "8. Save and Leave Game" << endl << divider << endl;
    cin >> userDecision; 
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000, '\n');
      userDecision = 9;
    }
    cout << divider << endl; 
    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[0],player);
            break;
        case 2:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[1],player);
            break;
        case 3:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[2],player);
            break;
        case 4:
            sleep_for(seconds(1));
            enterShop(game.viewShops()[3],player);
            break;
        case 5:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[1],player,numBossesDefeated);
            break;
        case 6:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[2],player,numBossesDefeated);
            break;
        case 7:
            sleep_for(seconds(1));
            cout << "N/A" << endl << divider << endl;
            break;
        case 8: 
            sleep_for(seconds(1));
            game.exitGame();
            break;
        default: 
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }

}
