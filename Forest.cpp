// Include classes
#include "Forest.h"
#include "Arena.h"
#include "Enemy.h"
#include "Entity.h"
#include "Game.h"
#include "Location.h"
#include "Town.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;

// Include libraries for random number generator
#include <cstdlib>  // for the random part
#include <ctime>    // For time

Forest::Forest() : Location() {
  enemies = nullptr;
  treasure = false;
}

Forest::Forest(string name, string description, string asciiDescription)
    : Location(name, description, asciiDescription) {
  // Set values and create enemies
  treasure = false;
  enemies = new Enemy *[5];
  for (int i = 0; i < 5; i++) {
    enemies[i] = new Enemy(0);
  }
}

void Forest::travelToLocation(Game &game, Location *location, Player *player,
                              int numBossesDefeated) {
  // Allows user to travel to the Town
  if (location->getName() == game.viewLocations()[0]->getName()) {
    game.travel(location);
    game.viewCurrentLocation()->showLocation(game, player, numBossesDefeated);
  } else {
    cout << "You cannot travel to that location!" << endl;
  }
}

void Forest::showLocation(Game &game, Player *player, int numBossesDefeated) {
  // Show Location
  string divider =
      "+------------------------------------------------------------------+";
  int userDecision = 0;
  Location::showLocation(game, player, numBossesDefeated); // Displays default location
  // Displays options
  cout << "1. Travel to Town" << endl
       << "2. Search for enemies and treasure" << endl
       << "3. Open treasure" << endl
       << "4. View Enemies" << endl
       << divider << endl;
  cin >> userDecision;
  userDecision = game.cinChecker(1, 4, userDecision);
  cout << divider << endl;

  switch (userDecision) { // Proccess options
    case 1: // Travel to Town
      sleep_for(seconds(1));
      travelToLocation(game, game.viewLocations()[0], player,
                       numBossesDefeated);
      break;
    case 2: // Create new enemies and possibly treasure
      explore(numBossesDefeated);
      cout << divider << endl;
      sleep_for(seconds(1));
      break;
    case 3: // Open treasure if there is treasure
      openTreasure(player, numBossesDefeated);
      cout << divider << endl;
      sleep_for(seconds(1));
      break;
    case 4: // Displays enemies
      sleep_for(seconds(1));
      viewEnemies(game, player, numBossesDefeated);
      break;
    default: // Shouldnt occur, will return player to forest
      sleep_for(seconds(1));
      cout << "You seem lost. Perhaps you should stay where you are" << endl
           << divider << endl;
      break;
  }
}

void Forest::callForBattle(Game &game, Player *player, Enemy *enemy,
                           int numBossesDefeated) {
  // Initialise variables for this function
  int currentRound = 0;
  bool keepFighting = true;
  string divider =
      "+------------------------------------------------------------------+";

  // Whilst player and enemy are alive, and player wants to keep fighting run loop
  while (player->GetIsAlive() == true && enemy->GetIsAlive() == true &&
         keepFighting == true) {
    Location::showLocation(game, player, numBossesDefeated); // Show forest description
    player->TakeTurn(enemy, currentRound, keepFighting);
    if (player->GetIsAlive() == false) {
      game.endGame(); // End game if player is dead
    } else if (keepFighting == false) {
      break; // If player doesn't wish to fight exit loop and battle
    } else if (enemy->GetIsAlive() == false) {
      break; // If enemy has died exit loop before enemies turn
    } else {
      enemy->TakeTurn(player, currentRound);
      if (player->GetIsAlive() == false) {
        break; // If player has died exit loop and battle
        game.endGame();
      }
    }
    currentRound++;
    sleep_for(seconds(1));
    cout << divider << endl;
  }
  
  // Output battle result
  if (player->GetIsAlive() == false) {
    cout << "You died!" << endl;
    game.endGame();
  }
  if (player->GetIsAlive() == true && keepFighting == true) {
    cout << "You killed " << enemy->getName() << endl;
  }
  sleep_for(seconds(1));
}

void Forest::explore(int numBossesDefeated) {
  // Generate new enemies
  for (int i = 0; i < 5; i++) {
    enemies[i] = new Enemy(numBossesDefeated);  // Change to Enemy later
  }

  cout << "New Enemies have appeared!" << endl;

  // Generate a random number between 1 and 3
  int randomNumber = (rand() % 3) + 1;

  // Determine if treasure appears
  if (randomNumber == 2) {
    treasure = true;
    cout << "You have spotted treasure!" << endl;
  }
}

void Forest::openTreasure(Player *player, int numBossesDefeated) {
  int cashGained = 0;
  if (treasure == true) {
    // Generate number of cash found
    cashGained = (5 * numBossesDefeated) + (rand() % 10) + 1;
    player->setCashOnHand(player->getCashOnHand() + cashGained); // Add to players inventory
    cout << cashGained << " coins collected!" << endl;
    treasure = false;
  } else {
    cout << "There is no treasure..." << endl;
  }
}

void Forest::viewEnemies(Game &game, Player *player, int numBossesDefeated) {
  int userDecision = 0, cashLost = 0;  // Used to select an enemy to fight

  // Clears terminal
  cout << endl << endl << endl << endl << endl << endl << endl;
  ;

  // Divider
  string divider =
      "+------------------------------------------------------------------+";

  // Show location
  Location::showLocation(game, player, numBossesDefeated);
  cout << "Select the enemy you wish to fight | Player challenge rating: "
       << player->getChallengeRating() << endl
       << divider << endl;
  // Display enemies player cna fight
  for (int i = 0; i < 5; i++) {
    if (enemies[i]->GetIsAlive()) {
      cout << i + 1 << " " << enemies[i]->getName()
           << " | CR : " << enemies[i]->getChallengeRating()
           << " | Status: Alive"
           << " | Res: " << enemies[i]->getRes() << endl;
    } else {
      cout << i + 1 << " " << enemies[i]->getName()
           << " | CR : " << enemies[i]->getChallengeRating()
           << " | Status: Dead" << endl
           << " | Res: " << enemies[i]->getRes() << endl;
    }
  }
  // Display option to leave
  cout << "6. Return to the main paths safety" << endl << divider << endl;
  cin >> userDecision;
  userDecision = game.cinChecker(1, 6, userDecision);
  cout << divider << endl;

  // Process user decision
  if (userDecision > 0 && userDecision <= 5 && 
      enemies[userDecision - 1]->GetIsAlive()) {
    // Fight the chosen enemy
    callForBattle(game, player, enemies[userDecision - 1], numBossesDefeated);
    sleep_for(seconds(1));
  } else if (userDecision > 0 && userDecision <= 5) {
    // If the enemy is dead alert player and ask them to pick again
    cout << "Theres not much fun fighting a dead body... Choose again." << endl;
    sleep_for(seconds(1));
    viewEnemies(game, player, numBossesDefeated);
  } else if (userDecision == 6) {
    // Allow player to leave, the game will continue on with the main forest loop
    cout << "You return to the safety of the main path" << endl
         << divider << endl;
    sleep_for(seconds(1));
  } else { // If none of the above are called return player to main forest loop
    cout << "You get lost, returning to the main path a while later" << endl
         << divider << endl;
    sleep_for(seconds(1));
  }
}
