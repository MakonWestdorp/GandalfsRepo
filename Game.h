#ifndef GAME_H
#define GAME_H

// Include libraries
#include <iostream>
#include <string>

// Include classes
#include "Location.h"

// Namespace
using namespace std;

/*
  Forward Declaring Entity class to allow Game to declare Entity as a friend
  class give access to bossesDefeated variable
  Forward declaring Unit testing class to give it access to the game functions
*/

class Entity;
class Game {
  // Declaring Entity and Unit test as a Friend Class
  friend class Entity;
  friend class UnitTest;

 private:
  // Variables for keeping track of the game
  int bossesDefeated;
  Location currentLocation;
  bool playerAlive;

 protected:
  Game();  // Default constructor
  Game(int bossesDefeated, Location location, bool playerAlive);  // Constructor
  bool initialiseShops();       // Initialises shops
  bool initialiseLocations();   // Initialises locations
  void playTutorial();          // Plays the tutorial
  void openCharacterCreator();  // Runs the character creator
  bool saveGame();              // Saves the game
  void exitGame();              // Exits the game
  bool loadGame();              // Loads the game
  void endGame();               // Ends the game if the player dies
 public:
  void travelToLocation(Location destination);        // Switches location
  void travelToShop();                                // Switches to a shop
  void setCurrentLocation(Location location);         // Sets the location
  Location viewCurrentLocation();                     // Returns current location
};

#endif