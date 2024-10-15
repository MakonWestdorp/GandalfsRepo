#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <string>

#include "Location.h"

using namespace std;

class Game;

class Arena : public Location {
 private:
  // Arena variables
  Enemy *Opponent; 
  int EnemiesDefeated = 0;

 public:
  Arena(); // Default constructor
  Arena(string name, string description, string asciiDescription); // Specific constructor
  ~Arena() {}; // Destructor
  void travelToLocation(Game &game, Location *location, Player *player,
                        int numBossesDefeated); // Allows the player to travel between locations
  void showLocation(Game &game, Player *player, int numBossesDefeated); // Displays the location
  void viewPlayerStats(Game &game, Player *player, int numBossesDefeated); // Displays player stats
  void callForBattle(Game &game, Player *player, int numBossesDefeated); // Calls for battle
};

#endif