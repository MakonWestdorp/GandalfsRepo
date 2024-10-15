#ifndef GAME_H
#define GAME_H

// Include libraries
#include <iostream>
#include <string>

// Include classes
#include "Arena.h"
#include "Entity.h"
#include "Forest.h"
#include "Location.h"
#include "Shop.h"
#include "Town.h"
#include "UnitTest.h"

// Namespace
using namespace std;

class Game {
  // Declaring Entity and Unit test as a Friend Class
  friend class Entity;
  friend class UnitTest;
  friend class Location;
  friend class Town;

 private:
  // Variables for keeping track of the game
  Location *currentLocation;
  bool playerAlive, gameRunning;

  // Shops
  Shop *Shops;
  Shop attackShop;
  Shop buffShop;

  // Locations
  Location **Locations;
  Town TownName;
  Forest ForestName;
  Arena ArenaName;

 public:
  ~Game() {};
  Game();                      // Default constructor
  void initialiseShops();      // Initialises shops
  void initialiseLocations();  // Initialises locations
  bool saveGame(Player *player, int &numBossesDefeated,
                string fileName);  // Saves the game
  void exitGame();                 // Exits the game
  bool loadGame(Player *player, int &numBossesDefeated,
                string fileName);      // Loads the game
  void endGame();                      // Ends the game if the player dies
  void travel(Location *destination);  // Switches location
  void setCurrentLocation(Location *location);  // Sets the location
  Location *viewCurrentLocation();              // Returns current location
  Shop *viewShops();                            // Returns list of shops
  Location **viewLocations();                   // Returns list of locations

  bool
  isGameRunning();  // Returns true if the game is still running, false if not
  int cinChecker(int lowerParameter, int upperParameter,
                 int userDecision);  // Cin checker
};

#endif