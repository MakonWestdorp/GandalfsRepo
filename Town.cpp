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
    // Allows user to travel to forest or arena
    if (location->getName() == game.viewLocations()[1]->getName() || 
        location->getName() == game.viewLocations()[2]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,player,numBossesDefeated);
    }
}

void Town::enterShop(Shop &shopName, Player *player, Game &game, int type)
{   
    /*
        Enters shop loop
        Until player chooses to exit the shop the game will
        display the shop interface, showing the items the 
        user can buy. 
        When the user exits the game will return to the show town loop
    */
    while (shopName.showShopInterface(player,game,type) == true) {}
}

void Town::showLocation(Game &game, Player *player, int numBossesDefeated)
{   
    // Variables needed to display town
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;

    Location::showLocation(game,player,numBossesDefeated); // Show town info
    // Show options
    cout << "1. Travel to Attack Item Shop" << endl << "2. Travel to Buff Item Shop" << endl
         << "3. Travel to Forest" << endl << "4. Travel to Arena" << endl << "5. Save Game" 
         << endl << "6. Leave Game" << endl << divider << endl;
    cin >> userDecision; 
    userDecision = game.cinChecker(1,6,userDecision);
    cout << divider << endl; 

    string fileName = "";

    switch (userDecision) { // Process options
        case 1: // Enter attack shop
            sleep_for(seconds(1));
            enterShop(game.viewShops()[0],player,game,1);
            break;
        case 2: // Enter buff shop
            sleep_for(seconds(1));
            enterShop(game.viewShops()[1],player,game,2);
            break;
        case 3: // Travel to forest
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[1],player,numBossesDefeated);
            break;
        case 4: // Travel to Arena
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[2],player,numBossesDefeated);
            break;
        case 5: // Save Game
            sleep_for(seconds(1));
            cout << "Enter the name for your save file (without .txt): ";
            cin >> fileName; 
            cout << (game.saveGame(player,numBossesDefeated,fileName) ? "Game Saved" : "Game not Saved") 
                 << endl << divider << endl;
            sleep_for(seconds(1));
            break;
        case 6: // Leave game
            game.exitGame();
            break;
        default: // If cin doesnt match keep player in the town for this loop
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }

}
