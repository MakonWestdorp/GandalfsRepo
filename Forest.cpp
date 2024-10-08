#include "Forest.h"

#include "Arena.h"
#include "Entity.h"
#include "Game.h"
#include "Location.h"
#include "Town.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread>
using namespace chrono;
using namespace this_thread;

// Include libraries for random number generator
#include <cstdlib>  // for the random part
#include <ctime>    // For time

Forest::Forest() : Location() {
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

void Forest::travelToLocation(Game &game, Location *location) {
  int cashOnHand = 0;  // Temporary - Needed for function call
  if (location->getName() == game.viewLocations()[0]->getName()) {
    game.travel(location);
    game.viewCurrentLocation()->showLocation(game, cashOnHand);
  }
}

void Forest::showLocation(Game &game, int &cashOnHand, Entity *player, Entity *enemy, int &numBossesDefeated)
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
            cout << divider << endl; 
            break;
        case 3: 
            sleep_for(seconds(1));
            openTreasure(player, numBossesDefeated);
            break;
        case 4:
            sleep_for(seconds(1));

      break;
    default:
      sleep_for(seconds(1));
      cout << "You seem lost. Perhaps you should stay where you are" << endl
           << divider << endl;
      break;
  }
}

void Forest::callForBattle(Entity *player, Entity *enemy) {
  while (player->GetIsAlive() == true && enemy->GetIsAlive() == true) {
  }
}

void Forest::explore() {
  // Generate new enemies
  for (int i = 0; i < 5; i++) {
    enemies[i] = Entity();  // Change to Enemy later
  }

  cout << "New Enemies have appeared!" << endl;

  // Get a different random number each time the program runs
  srand(time(0));

  // Generate a random number between 1 and 3
  int randomNumber = (rand() % 3) + 1;

  // Determine if treasure appears
  if (randomNumber == 2) {
    treasure = true;
    cout << "You have found treasure!" << endl;
  }
}

void Forest::openTreasure(Entity *player, int &numBossesDefeated)
{
    if (treasure == true) {
    
    }
}
