#include "Arena.h"
#include "Location.h"
#include "Town.h"
#include "Forest.h"
#include "Game.h"
#include "Player.h"


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

void Arena::travelToLocation(Game &game, Location *location, Player *player, int numBossesDefeated)
{
    if (location->getName() == game.viewLocations()[0]->getName()) {
        game.travel(location);
        game.viewCurrentLocation()->showLocation(game,player,numBossesDefeated);
    }
}

void Arena::showLocation(Game &game, Player *player, int numBossesDefeated)
{   
    // Generate enemy
    Enemy *Opponent = new Enemy(numBossesDefeated);

    // Show Location
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,player,numBossesDefeated);
    cout << "1. Travel to Town" << endl << "2. View Player Stats " << endl << "3. Fight enemy | Challenge Rating: " << Opponent->getChallengeRating() << endl << divider << endl;
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
            travelToLocation(game,game.viewLocations()[0],player,numBossesDefeated);
            break;
        case 2: 
            sleep_for(seconds(1));
            viewPlayerStats(game,player,numBossesDefeated);
            break; 
        case 3:
            sleep_for(seconds(1));
            callForBattle(game,player,Opponent,numBossesDefeated);
            break;
        default:
            sleep_for(seconds(1));
            cout << "You seem lost. Perhaps you should stay where you are" << endl << divider << endl;
            break;
    }
}

void Arena::viewPlayerStats(Game &game, Player *player, int numBossesDefeated) 
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,player,numBossesDefeated);
    cout << "Health Points (HP) = " << player->getHP() << endl << "Strength (STR) = " << player->getSTR() 
         << endl << "Defence (DEF) = " << player->getDEF() << endl << "Magic (MAG) = " << player->getMAG() 
         << endl << divider << endl << "1. Return to Arena" << endl << "2. Travel to Town" << endl << divider << endl;
    cin >> userDecision; 
    cout << divider << endl;
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000, '\n');
      userDecision = 3;
    }
    
    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[2],player,numBossesDefeated);
            break;
        case 2  :
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[0],player,numBossesDefeated);
            break;
        default:
            sleep_for(seconds(1));
            cout << "You seem confused. Perhaps you should return to the Arena" << endl << divider << endl;
            travelToLocation(game,game.viewLocations()[2],player,numBossesDefeated);
            break;
    }
}

void Arena::callForBattle(Game &game, Player *player, Enemy *enemy, int numBossesDefeated) 
{
    int currentRound = 0;
    bool keepFighting = true;
  while (player->GetIsAlive() == true && enemy->GetIsAlive() == true && keepFighting == true) {
        Location::showLocation(game, player, numBossesDefeated);
        player->TakeTurn(enemy,currentRound,keepFighting);
        enemy->TakeTurn(player,currentRound);
        currentRound++;
  }

  if (player->GetIsAlive() == false) {
    game.endGame();
  }
}

