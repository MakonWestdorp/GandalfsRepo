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
  treasure = false;
  enemies = new Enemy *[5];
  for (int i = 0; i < 5; i++) {
    enemies[i] = new Enemy(0);
  }
}

void Forest::travelToLocation(Game &game, Location *location, Player *player,
                              int numBossesDefeated) {
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
  Location::showLocation(game, player, numBossesDefeated);
  cout << "1. Travel to Town" << endl
       << "2. Explore" << endl
       << "3. Search for treasure" << endl
       << "4. View Enemies" << endl
       << divider << endl;
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
      travelToLocation(game, game.viewLocations()[0], player,
                       numBossesDefeated);
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
      viewEnemies(game, player, numBossesDefeated);
      break;
    default:
      sleep_for(seconds(1));
      cout << "You seem lost. Perhaps you should stay where you are" << endl
           << divider << endl;
      break;
  }
}

void Forest::callForBattle(Game &game, Player *player, Enemy *enemy,
                           int numBossesDefeated) {
  int currentRound = 0;
  bool keepFighting = true;
  string divider =
      "+------------------------------------------------------------------+";
  while (player->GetIsAlive() == true && enemy->GetIsAlive() == true &&
         keepFighting == true) {
    Location::showLocation(game, player, numBossesDefeated);
    player->TakeTurn(enemy, currentRound, keepFighting);
    if (player->GetIsAlive() == false) {
      game.endGame();
    } else if (keepFighting == false) {
      break;
    } else if (enemy->GetIsAlive() == false) {
      break;
    } else {
      enemy->TakeTurn(player, currentRound);
    }
    currentRound++;
    sleep_for(seconds(1));
    cout << divider << endl;
  }
  if (player->GetIsAlive() == false) {
    cout << "You died!" << endl;
    game.endGame();
  }
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
  if (treasure == true) {
    player->setCashOnHand((player->getCashOnHand() + 5 * numBossesDefeated));
    cout << 5 * numBossesDefeated << " coins collected!" << endl;
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
  for (int i = 0; i < 5; i++) {
    if (enemies[i]->GetIsAlive()) {
      cout << i + 1 << " " << enemies[i]->getName()
           << " | Challenge rating : " << enemies[i]->getChallengeRating()
           << " | Status: Alive" << endl;
    } else {
      cout << i + 1 << " " << enemies[i]->getName()
           << " | Challenge rating : " << enemies[i]->getChallengeRating()
           << " | Status: Dead" << endl;
    }
  }
  cout << "6. Return to the main paths safety" << endl << divider << endl;
  cin >> userDecision;
  if (cin.fail() == true) {
    cin.clear();
    cin.ignore(1000, '\n');
    userDecision = 10;
  }
  cout << divider << endl;

  if (userDecision > 0 && userDecision <= 5 &&
      enemies[userDecision - 1]->GetIsAlive()) {
    callForBattle(game, player, enemies[userDecision - 1], numBossesDefeated);
    sleep_for(seconds(1));
  } else if (!enemies[userDecision - 1]->GetIsAlive()) {
    cout << "Theres not much fun fighting a dead body... Choose again." << endl;
    sleep_for(seconds(3));
  } else if (userDecision == 6) {
    cout << "You return to the safety of the main path" << endl
         << divider << endl;
    sleep_for(seconds(1));
  } else {
    cashLost = (rand() % 5) + 1;
    player->setCashOnHand(player->getCashOnHand() - cashLost);

    cout << "You get lost and lose " << cashLost
         << " coins, finding your way back after a while" << endl
         << divider << endl;
    sleep_for(seconds(1));
  }
}
