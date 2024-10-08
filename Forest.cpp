#include "Forest.h"

#include "Arena.h"
#include "Entity.h"
#include "Game.h"
#include "Location.h"
#include "Town.h"
#include "Enemy.h"

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

Forest::Forest(string name, string description, string asciiDescription, int numBossesDefeated) : Location(name,description,asciiDescription)
{
    treasure = false;   
    enemies = new Enemy*[5];
    for (int i = 0; i < 5; i++) {
        srand(time(0));
        enemies[i] = new Enemy(numBossesDefeated);
    }

}

void Forest::travelToLocation(Game &game, Location *location, Entity *player, Enemy *enemy) {
  int cashOnHand = 0;  // Temporary - Needed for function call
  if (location->getName() == game.viewLocations()[0]->getName()) {
    game.travel(location);
    game.viewCurrentLocation()->showLocation(game, cashOnHand,player,enemy,1);
  }
}

void Forest::showLocation(Game &game, int &cashOnHand, Entity *player, Enemy *enemy, int numBossesDefeated)
{
    string divider = "+------------------------------------------------------------------+"; 
    int userDecision = 0;
    Location::showLocation(game,cashOnHand,player,enemy,1);
    cout << "1. Travel to Town" << endl << "2. Explore" << endl << "3. Search for treasure" 
         << endl << "4. View Enemies" << endl << divider << endl;
    cin >> userDecision; 
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000, '\n');
      userDecision = 5;
    }
    cout << divider << endl;

    switch (userDecision) {
        case 1:
            sleep_for(seconds(1));
            travelToLocation(game,game.viewLocations()[0],player,enemy);
            break;
        case 2:
            explore(numBossesDefeated);
            cout << divider << endl; 
            sleep_for(seconds(1));
            break;
        case 3: 
            openTreasure(player, numBossesDefeated);
            cout << divider << endl;
            sleep_for(seconds(1));
            break;
        case 4:
            sleep_for(seconds(1));
            viewEnemies(game,cashOnHand,player,enemy);
            break;
        default:
          sleep_for(seconds(1));
          cout << "You seem lost. Perhaps you should stay where you are" << endl
                << divider << endl;
          break;
  }
}

void Forest::callForBattle(Entity *player, Enemy *enemy) {
  while (player->GetIsAlive() == true && enemy->GetIsAlive() == true) {

  }
}

void Forest::explore(int numBossesDefeated) {
  // Generate new enemies
  for (int i = 0; i < 5; i++) {
    srand(time(0));
    enemies[i] = new Enemy(numBossesDefeated);  // Change to Enemy later
  }

  cout << "New Enemies have appeared!" << endl;

  // Get a different random number each time the program runs
  srand(time(0));

  // Generate a random number between 1 and 3
  int randomNumber = (rand() % 3) + 1;

  // Determine if treasure appears
  if (randomNumber == 2) {
    treasure = true;
    cout << "You have spotted treasure!" << endl;
  }
}

void Forest::openTreasure(Entity *player, int numBossesDefeated)
{
    if (treasure == true) {
        player->setCashOnHand((player->getCashOnHand() + 5 * numBossesDefeated));
        cout << 5 * numBossesDefeated << " coins collected!" << endl; 
        treasure = false; 
    } else {
        cout << "There is no treasure..." << endl;
    }
}

void Forest::viewEnemies(Game &game, int &cashOnHand, Entity *player, Enemy *enemy)
{
    int userDecision = 0, cashLost = 0; // Used to select an enemy to fight

    // Clears terminal
    cout << endl << endl << endl << endl << endl << endl << endl;; 
    
    // Divider
    string divider = "+------------------------------------------------------------------+"; 

    // Show location
    Location::showLocation(game, cashOnHand,player,enemy,1);
    cout << "Select the enemy you wish to fight | Player challenge rating: " << "CR" << endl << divider << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " " << enemies[i]->getName() << " | Challenge rating : " << enemies[i]->getChallengeRating() << endl;
    }
    cout << "6. Return to the main paths safety" << endl << divider << endl;
    cin >> userDecision;
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000, '\n');
      userDecision = 10;
    }
    cout << divider << endl;
    
    if (userDecision > 0 && userDecision <= 5) {
      callForBattle(player,enemy);
      sleep_for(seconds(1));
    } else if (userDecision == 6) {
      cout << "You return to the safety of the main path" << endl << divider << endl;
      sleep_for(seconds(1));
    } else {
      srand(time(0));
      cashLost = (rand() % 5) + 1;
      cashOnHand -= cashLost; 

      cout << "You get lost and lose " << cashLost 
      << " coins, finding your way back after a while" 
      << endl << divider << endl;
      sleep_for(seconds(1));
    }

}
