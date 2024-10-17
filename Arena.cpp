// Include classes
#include "Arena.h"

#include "Boss.h"
#include "Forest.h"
#include "Game.h"
#include "Location.h"
#include "Player.h"
#include "Town.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread>
using namespace chrono;
using namespace this_thread;

Arena::Arena() : Location() {
  // No enemy currently
  Opponent = nullptr;
}

Arena::Arena(string name, string description, string asciiDescription)
    : Location(name, description, asciiDescription) {
  // Create enemy with 0 bosses defeated
  Opponent = new Enemy(0);
}

void Arena::travelToLocation(Game &game, Location *location, Player *player,
                             int numBossesDefeated) {
  /*
      Allows the user to travel to the Town from the Arena Only
      Player should not be able to travel to Forest from Arena

      If input location's name matches the name of town stored by game
      the game will set the current location to the input and call
      the new locations show location function

      An error message will be printed if a location other than town is passed
  */
  if (location->getName() == game.viewLocations()[0]->getName()) {
    game.travel(location);
    game.viewCurrentLocation()->showLocation(game, player, numBossesDefeated);
  } else {
    cout << "You cannot travel to that location!" << endl;
  }
}

void Arena::showLocation(Game &game, Player *player, int numBossesDefeated) {
  // Variables needed for displaying location
  string divider =
      "+------------------------------------------------------------------+";
  int userDecision = 0;

  // Calls base classes show location function
  Location::showLocation(game, player, numBossesDefeated);
  // Prints options
  cout << "1. Travel to Town" << endl
       << "2. View Player Stats " << endl
       << "3. Fight enemy | Challenge Rating: "
       << Opponent->getChallengeRating() << endl
       << divider << endl;
  cin >> userDecision;

  // Checking if cin failed
  userDecision = game.cinChecker(1, 4, userDecision);
  cout << divider << endl;

  // Processes users decision
  switch (userDecision) {
    case 1:  // Travels to town
      sleep_for(seconds(1));
      travelToLocation(game, game.viewLocations()[0], player,
                       numBossesDefeated);
      break;
    case 2:  // Shows players stats
      sleep_for(seconds(1));
      viewPlayerStats(game, player, numBossesDefeated);
      break;
    case 3:  // Call for battle
      sleep_for(seconds(1));
      callForBattle(game, player, numBossesDefeated);
      break;
    default:  // If user input isn't valid do nothing
      sleep_for(seconds(1));
      cout << "You seem lost. Perhaps you should stay where you are" << endl
           << divider << endl;
      break;
  }
}

void Arena::viewPlayerStats(Game &game, Player *player, int numBossesDefeated) {
  // Variables needed for displaying stats
  string divider =
      "+------------------------------------------------------------------+";
  int userDecision = 0;

  // Call default show location then display player stats
  Location::showLocation(game, player, numBossesDefeated);
  cout << "Health Points (HP) = " << player->getHP() << endl
       << "Strength (STR) = " << player->getSTR() << endl
       << "Defence (DEF) = " << player->getDEF() << endl
       << "Magic (MAG) = " << player->getMAG() << endl
       << "Resistance (RES) = " << player->getRes() << endl
       << divider << endl
       << "1. Return to Arena" << endl
       << "2. Travel to Town" << endl
       << "3. Change player Resistance" << endl
       << divider << endl;

  // Prompt for input
  cin >> userDecision;
  cout << divider << endl;
  userDecision = game.cinChecker(1, 3, userDecision);  // Check input

  switch (userDecision) {  // Process input
    case 1:                // Return to Arena
      cout << "Returning to Arena" << endl << divider << endl;
      sleep_for(seconds(1));
      break;
    case 2:  // Travel to town
      cout << "Traveling to Town" << endl << divider << endl;
      sleep_for(seconds(1));
      travelToLocation(game, game.viewLocations()[0], player,
                       numBossesDefeated);
      break;
    case 3:  // Change resistance
      sleep_for(seconds(1));
      cout << endl
           << endl
           << endl
           << endl
           << endl
           << endl
           << endl
           << divider << endl;  // Spacing

      userDecision = 0;  // Set back to 0 for safety

      // Output options
      cout << "Change resistance to: " << endl
           << "1. Magic" << endl
           << "2. Piercing" << endl
           << "3. Bludgeoning" << endl
           << "4. Slashing" << endl
           << "5. Return to Arena" << endl
           << divider << endl;

      // Prompt for and process options
      cin >> userDecision;
      userDecision = game.cinChecker(1, 5, userDecision);
      cout << userDecision << endl;
      switch (userDecision) {  // Set to input type
        case 1:
          player->setRes("Magic");
          cout << "Resistance set to Magic" << endl;
          sleep_for(seconds(1));
          break;
        case 2:
          player->setRes("Piercing");
          cout << "Resistance set to Piercing" << endl;
          sleep_for(seconds(1));
          break;
        case 3:
          player->setRes("Bludgeoning");
          cout << "Resistance set to Bludgeoning" << endl;
          sleep_for(seconds(1));
          break;
        case 4:
          player->setRes("Slashing");
          cout << "Resistance set to Slashing" << endl;
          sleep_for(seconds(1));
          break;
        case 5:
          cout << "Returning to Arena" << endl;
          sleep_for(seconds(1));
        default:
          sleep_for(seconds(1));  // Shouldn't occur, if default occurs player
                                  // will just be sent back to the arena
      }

    default:
      sleep_for(seconds(1));
      cout << "You seem confused. Perhaps you should return to the Arena"
           << endl
           << divider << endl;
      travelToLocation(game, game.viewLocations()[2], player,
                       numBossesDefeated);
      break;
  }
}

void Arena::callForBattle(Game &game, Player *player, int numBossesDefeated) {
  // Summon a boss if two enemies has been killed
  if (EnemiesDefeated % 10 == 0 && EnemiesDefeated != 0) {
    Boss CurrentBoss = Boss(numBossesDefeated);
    Opponent = &CurrentBoss;
  }
  // Intialise variables needed for this function
  int currentRound = 0;
  bool keepFighting = true;
  string divider =
      "+------------------------------------------------------------------+";

  // Whilst player and enemy are alive, and player wants to keep fighting run
  // loop
  while (player->GetIsAlive() == true && Opponent->GetIsAlive() == true &&
         keepFighting == true) {
    Location::showLocation(game, player,
                           numBossesDefeated);  // Show Arena description
    player->TakeTurn(Opponent, currentRound, keepFighting);
    if (player->GetIsAlive() == false) {
      game.endGame();  // End game if player is dead
    } else if (keepFighting == false) {
      break;  // If player doesn't wish to fight exit loop and battle
    } else if (Opponent->GetIsAlive() == false) {
      break;  // If enemy has died exit loop before enemies turn
    } else {
      Opponent->TakeTurn(player, currentRound);  //
      if (player->GetIsAlive() == false) {
        break;           // If player has died exit loop and battle
        game.endGame();  // End Game
      }
    }
    currentRound++;  // Increase round
    sleep_for(seconds(1));
    cout << divider << endl;
  }
  // Output result
  if (player->GetIsAlive() == false) {
    cout << "You died!" << endl;
    game.endGame();
  }
  if (player->GetIsAlive() == true) {
    cout << "You killed " << Opponent->getName() << endl;
  }
  sleep_for(seconds(1));
  if (Opponent->GetIsAlive() == false) {
    // Create new enemy and update shops
    Opponent = new Enemy(numBossesDefeated);
    EnemiesDefeated++;
    game.viewShops()[0].updateShop(numBossesDefeated, 1);
    game.viewShops()[1].updateShop(numBossesDefeated, 2);
  }
}
