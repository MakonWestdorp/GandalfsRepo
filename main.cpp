// Include libraries
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// Include classes
#include "Arena.h"
#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"
#include "Enemy.h"
#include "Entity.h"
#include "Forest.h"
#include "Game.h"
#include "Location.h"
#include "Player.h"
#include "Shop.h"
#include "Town.h"

// Namespaces
using namespace std;
using namespace chrono;
using namespace this_thread;

int main() {
  // Create game
  Game ChampionsOfSand;
  int numBossesDefeated = 0, userDecision = 0;
  Player *player = new Player("",0,0,0,0,"");
  string fileName = "";
  bool showTutorial = true;
  string divider =
  "+------------------------------------------------------------------+";


  // Initialies shops and locations
  ChampionsOfSand.initialiseShops();
  ChampionsOfSand.initialiseLocations();

  // Start Game menu
  cout << divider << endl << "Champions of Sand!" << endl << divider << endl <<
  "1. Start a new game" << endl << "2. Load Game" << endl << "3. Exit Game" << 
  endl << divider << endl;

  cin >> userDecision;
  userDecision = ChampionsOfSand.cinChecker(1,3,userDecision);
  cout << divider << endl;
  sleep_for(seconds(1));

  if (userDecision == 1) {
    player = new Player();
  } else if (userDecision == 2) {
    cout << "Enter the name of the file you wish to enter (without .txt): ";
    cin >> fileName;
    cout << divider << endl;
    while (!ChampionsOfSand.loadGame(player,numBossesDefeated,fileName)) {
      userDecision = 0;
      fileName = "";
      cout << "This file could not be loaded. Do you wish to load another file?" 
           << endl << divider << endl << "1. Load another file" << endl
           << "2. Exit Game" << endl << divider << endl;
      cin >> userDecision;
      userDecision = ChampionsOfSand.cinChecker(1,2,userDecision);
      if (userDecision == 1) {
        cout << "Enter the name of the file you wish to enter (without .txt): ";
        cin >> fileName;
        cout << divider << endl;
      } else {
        cout << "Exiting game" << endl << divider << endl;
        return 0;
      }
    }
  } else {
    cout << "Exiting game" << endl << divider << endl;
    return 0;
  }
  
  // Tutorial
  if (showTutorial == true) {
    
  }

  // Intro fight

  // Game Loop
  ChampionsOfSand.setCurrentLocation(ChampionsOfSand.viewLocations()[0]);

  while (ChampionsOfSand.isGameRunning() == true) {
    ChampionsOfSand.viewCurrentLocation()->showLocation(
        ChampionsOfSand, player, numBossesDefeated);
  }
  if (!player->GetIsAlive()) {
    cout << "Game Over! We hope you enjoyed this game of Champions of the Sand!"
         << endl;
  }
}