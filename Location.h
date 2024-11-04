#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

#include "Enemy.h"
#include "Entity.h"
#include "Player.h"

using namespace std;

/*
    An abstract class for the locations of the game
    Forward declaring Unit test to allow for test functions to access location
   functions
*/

class UnitTest;
class Game;

class Location {
  friend class UnitTest;

 private:
  // Variables describing a location
  string name;
  string description;
  string asciiDescription;

 public:
  ~Location() {};
  Location();  // Default constructor
  Location(string name, string description,
           string asciiDescription);  // Constructor
  virtual void showLocation(
      Game &game, Player *player,
      int numBossesDefeated);  // Displays the locations details
  virtual void travelToLocation(Game &game, Location *destination,
                                Player *player,
                                int numBossesDefeated);  // Changes the location
  string getName();                                      // Returns the name
};

#endif