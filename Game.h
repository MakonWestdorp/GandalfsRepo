#ifndef GAME_H
#define GAME_H

// Include libraries
#include <iostream>
#include <string>

// Include classes
#include "Entity.h"
#include "Location.h"
#include "Town.h"
#include "Arena.h"
#include "Forest.h"
#include "UnitTest.h"
#include "Shop.h"

// Namespace
using namespace std;

/*
  Forward Declaring Entity class to allow Game to declare Entity as a friend
  class give access to bossesDefeated variable
  Forward declaring Unit testing class to give it access to the game functions
*/

class Game {
  // Declaring Entity and Unit test as a Friend Class
  friend class Entity;
  friend class UnitTest;
  friend class Location;

 private:
  // Variables for keeping track of the game
  Location *currentLocation;
  bool playerAlive, gameRunning;

  // Shops
  Shop *Shops;
  Shop WeaponShop;
  Shop MagicShop;
  Shop ArmourShop;
  Shop GeneralShop;

  // Locations
  Location **Locations;
  Town TownName;
  Forest ForestName;
  Arena ArenaName;

 protected:
  Game();                       // Default constructor
  void initialiseShops();       // Initialises shops
  void initialiseLocations();   // Initialises locations
  void playTutorial();          // Plays the tutorial
  void openCharacterCreator();  // Runs the character creator
 public:
  bool saveGame();                     // Saves the game
  void exitGame();                     // Exits the game
  bool loadGame();                     // Loads the game
  void endGame();                      // Ends the game if the player dies
  void travel(Location *destination);  // Switches location
  void setCurrentLocation(Location *location);  // Sets the location
  Location *viewCurrentLocation();              // Returns current location
  Shop *viewShops();                            // Returns list of shops
  Location **viewLocations();                   // Returns list of locations

  bool isGameRunning();  // Returns true if the game is still run, false if not
};

#endif