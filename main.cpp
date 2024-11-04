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
  // Calls srand so all rands are properly random
  srand(time(0));
  // Create game
  Game ChampionsOfSand;
  int numBossesDefeated = 0, userDecision = 0;
  Player *player = new Player("", 0, 0, 0, 0, "");
  string fileName = "";
  string divider =
      "+------------------------------------------------------------------+";
  string newLine = string(25,'\n');
  bool newGame = false;

  // Initialies shops and locations
  ChampionsOfSand.initialiseShops();
  ChampionsOfSand.initialiseLocations();

  // Start Game menu
  cout << newLine << divider << endl
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

  // Process user decision
  if (userDecision == 1) { // Start new game
    newGame = true;
  } else if (userDecision == 2) { // Load file
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
  cout << newLine;
  cout << divider << endl << "Do you wish to view the tutorial?" 
       << endl << divider << endl << "1. Yes I do" << endl 
       << "2. No I do not" << endl;
  userDecision = 0;
  cin >> userDecision;
  userDecision = ChampionsOfSand.cinChecker(1,2,userDecision);
  if (userDecision == 1) {
    cout << divider << endl 
    << "Welcome to Champions of Sand! A terminal turn based " 
    << endl << "fantasy fighting game developed in C++!" << endl << divider << endl 
    << "To begin a new game you will need to assign points to your stats;" << endl
    << "health, strength, defence, and magic, and choose your resistance" << endl << endl
    << "Press enter when you are ready to learn about your players stats" << endl << divider;

    cin.get(); // Wait for the user to press enter
    cout << newLine;

    cout << divider << endl 
    << "Health is your life points, if they reach 0 your game will be over" << endl
    << "Strength is your damage, the higher it is the stronger your weapons"
    << endl << "and attacks" << endl
    << "Defence helps keep you alive, the higher it is the less damage" << endl << 
    "you'll take" << endl
    << "" << endl
    << "Resistance protects you against the damage types of the game;" << endl 
    <<"Magic, Slashing, Piercing and Bludgeoning." << endl
    << endl << "Press enter when you are ready to learn about the games locations;" << endl 
    << "Town, Forest and Arena" << endl;

    cin.get(); // Wait for enter
    cout << newLine;

    cout << divider << endl 
    << "The Town is the centre of the game. Here you can access the shops," << endl 
    << "travel to the forest or the Arena, view the attack or buff item shops, " << endl
    << "save the game, and exit the game." << endl
    << "The forest is where you search for in search of enemies and treasure." << endl 
    << "Here you can Fight limitless enemies for cash, or search for treasure to " << endl
    << "The Arena is the centre of battle within the game. Here you can" << endl 
    <<"fight enemies, or bosses that spawn every 2 enemies killed in the arena." << endl
    << "You can also view your stas and change your players resistence here" << endl << endl
    << "Press enter when you are ready to learn about the games shops and items" << endl;

    cin.get(); // Wait for enter
    cout << newLine;

    cout << divider << endl
    << "Shops are where you purchase attack and buff items for your player to use." << endl
    << "Here you can buy attack items to help you deal damage in battle, " << endl
    << "with each weapon having a different damage type to deal more damage" << endl
    << "if an enemy is weak to that damage type." << endl
    << "Or you can spend your cash on buff items to temporarily boost" << endl 
    << "your stats within battle. " << endl
    << endl << "Press enter when you are ready to learn about battle." << endl;

    cin.get(); // Wait for enter
    cout << newLine;

    cout << divider << endl
    << "As mentioned previously combat occurs in turns, with the player's first." << endl
    << "During your turn you can attack using your base strength and magic stats," << endl
    << "attack using your items to deal extra damage, or use your buff items to " << endl
    << "temporarily improve your stats. " << endl 
    << "Within the game you will come across something known as Challenge Rating/CR."  << endl 
    << "For players and enemies this is an average of your stats, " << endl
    << "giving you an indication of how strong you or your opponent is." << endl << endl
    << "Press enter to learn how to navigate the game" << endl;

    cin.get(); // Wait for enter
    cout << newLine;

    cout << endl << endl << divider << endl
    << "This game uses numerical inputs to allow the player to interact with the game" << endl
    << "To prevent unexpected errors or inputs please only enter a value prompted to." << endl 
    << "For the best experience we recommend you move the terminal into a new window" << endl
    << "by pressing zsh in the top right corner of your terminal, and zoom as needed" << endl
    << endl << "Press enter to begin the game. Have fun!" << endl;

    cin.get(); // Wait for enter
    cout << newLine;
  } 
 
  if (newGame) {
    player = new Player(); // If new game true enter character creator
  }

  cout << newLine;

  /*
    Game Loop
    - Player begins in the town, calling its showLocation function  
       - If a player enters a shop it will display the options until they leave
        - When they leave the game will go back to displaying the town
    - If the player travels to the forest the game will set the current location
      to the forest and call its showLocation function
      - If the player travels to the town it will display the town and update current location
      - If the player explores the forest will create new enemies and possibly spawn treasure
      - If the player opens the treasure they will gain cash if the treasure exists
      - If the player chooses to view enemy it will list the enemies
        - The player can choose to fight an enemy
          - This will enter a battle loop until the player or enemy dies, or the player chooses to leave
          - When they leave they will return to the view enemies display
        - The player can choose to leave
        - When they leave the game will display the forest again
      - If the player travels back to the town they can travel to the Arena
        - If the player travels to the town it will display the town
        - If the player chooses to view their stats it will display their stats
          - The player can change their resistance
          - When they leave they will return to the arena
        - If the player chooses to fight they will enter battle
          - Every 2 enemies killed in the arena a boss will spawn
        - When the battle is over and the player is not dead they will return to the arena   
  */
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