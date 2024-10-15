// Include libraries
#include <chrono>
#include <iostream>
#include <string>
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
#include "Boss.h"

// Namespaces
using namespace std;
using namespace chrono;
using namespace this_thread;

int main() {
  srand(time(0));
  // Create game
  Game ChampionsOfSand;
  int numBossesDefeated = 0, userDecision = 0;
  Player *player = new Player("", 0, 0, 0, 0, "");
  string fileName = "";
  string divider =
      "+------------------------------------------------------------------+";

  // Initialies shops and locations
  ChampionsOfSand.initialiseShops();
  ChampionsOfSand.initialiseLocations();

  // Start Game menu
  cout << divider << endl
       << "Champions of Sand!" << endl
       << divider << endl
       << "1. Start a new game" << endl
       << "2. Load Game" << endl
       << "3. Exit Game" << endl
       << divider << endl;

  cin >> userDecision;
  userDecision = ChampionsOfSand.cinChecker(1, 3, userDecision);
  cout << divider << endl;
  sleep_for(seconds(1));

  if (userDecision == 1) {
    player = new Player();
  } else if (userDecision == 2) {
    cout << "Enter the name of the file you wish to enter (without .txt): ";
    cin >> fileName;
    cout << divider << endl;
    while (!ChampionsOfSand.loadGame(player, numBossesDefeated, fileName)) {
      userDecision = 0;
      fileName = "";
      cout << "This file could not be loaded. Do you wish to load another file?"
           << endl
           << divider << endl
           << "1. Load another file" << endl
           << "2. Exit Game" << endl
           << divider << endl;
      cin >> userDecision;
      userDecision = ChampionsOfSand.cinChecker(1, 2, userDecision);
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
  cout << divider << endl << "Do you wish to view the tutorial?" 
       << endl << divider << endl << "1. Yes I do" << endl 
       << "2. No I do not" << endl;
  userDecision = 0;
  cin >> userDecision;
  userDecision = ChampionsOfSand.cinChecker(1,2,userDecision);
  if (userDecision == 1) {
    cout << divider << endl 
    << "Welcome to Champions of Sand! A terminal turn based based fantasy fighting game developed in C++!" << endl
    << divider << "To begin a new game you will need to assign points to your stats; health," 
    "strength, defence, and magic, and choose your resistance" << endl << endl
    << "Press enter when you are ready to learn about your players stats" << endl << divider;

    cin.get(); // Wait for the user to press enter

    cout << endl << endl << divider << endl 
    << "Health is your life points, if they reach 0 your game will be over" << endl
    << "Strength is your damage, the higher it is the stronger your weapons and attacks" << endl
    << "Defence helps keep you alive, the higher it is the less damage you'll take" << endl
    << "" << endl
    << "Resistance protects you against the damage types of the game; Magic, Slashing, Piercing and Bludgeoning." << endl
    << endl << "Press enter when you are ready to learn about the games locations; Town, Forest and Arena" << endl;

    cin.get(); // Wait for enter

    cout << endl << endl << divider << endl 
    << "The Town is the centre of the game. Here you can access the shops, travel to the forest" << endl
    << "or the Arena, view the attack or buff item shops, save the game, and exit the game." << endl
    << "The forest is where you set off in search of enemies and treasure. Here you can " << endl
    << "Fight limitless enemies for cash, or search for treasure to gain even more cash." << endl
    << "The Arena is the centre of battle within the game. Here you can fight enemies, or bosses " << endl
    << "that spawn every 2 enemies killed in the arena. You can also view your stas and" << endl
    << "change your players resistence here" << endl << endl
    << "Press enter when you are ready to learn about the games shops and items" << endl;

    cin.get(); // Wait for enter

    cout << endl << endl << divider << endl
    << "Shops are where you purchase attack and buff items for your player to use in battle." << endl
    << "Here your cash can be spent on attack items to help you deal damage in battle, " << endl
    << "with each weapon having a different damage type to assist you against certain enemies." << endl
    << "Or you can spend your cash on buff items to temporarily boost your stats within battle. " << endl
    << endl << "Press enter when you are ready to learn about battle." << endl;

    cin.get(); // Wait for enter

    cout << endl << endl << divider << endl
    << "As mentioned previously combat occurs in turns, with the player going first." << endl
    << "During your turn you can choose to attack using your base strength and magic stats" << endl
    << "attack using your items to deal extra damage, or use your buff items to temporarily " << endl
    << "improve your stats. " << endl << "Within the game you will come across something known" 
    "as Challenge Rating (CR)."  << endl << "For players and enemies this is an average of your stats" 
    ", giving you an indication of how strong you or your opponent is." << endl << endl
    << "Press enter to learn how to navigate the game" << endl;

    cin.get(); // Wait for enetr

    cout << endl << endl << divider << endl
    << "This game uses numerical inputs to allow the player to choose what they wish to do." << endl
    << "To prevent unexpected errors or inputs please only enter a value when the game says to." << endl 
    << "For the best experience we recommend you move the terminal into the editor window by" << endl
    << "pressing zsh in the top right corner of your terminal, and zoom as needed" << endl
    << endl << "Press enter to begin the game. Have fun!" << endl;

    cin.get(); // Wait for enter
  } 
 

  // Game Loop
  ChampionsOfSand.setCurrentLocation(ChampionsOfSand.viewLocations()[0]);

  while (ChampionsOfSand.isGameRunning() == true) {
    ChampionsOfSand.viewCurrentLocation()->showLocation(ChampionsOfSand, player,
                                                        numBossesDefeated);
  }
  if (!player->GetIsAlive()) {
    cout << "Game Over! We hope you enjoyed this game of Champions of the Sand!"
         << endl;
  }
}