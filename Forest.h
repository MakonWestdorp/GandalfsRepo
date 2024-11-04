#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>

#include "Location.h"

using namespace std;

class Game;
class Entity;
class Enemy;
class Player;

class Forest : public Location {
 private:
 // Forest variables
  Enemy **enemies; 
  bool treasure;

 public:
  ~Forest() {}; // Destructor
  Forest(); // Constructor
  Forest(string name, string description, string asciiDescription); // Specific constructor
  void travelToLocation(Game &game, Location *location, Player *player,
                        int numBossesDefeated) override; // Allows player to travel to other locations
  void showLocation(Game &game, Player *player, int numBossesDefeated) override; // Displays Forest
  void callForBattle(Game &game, Player *player, Enemy *enemy, 
                     int numBossesDefeated); // Calls for battle
  void explore(int numBossesDefeated); // Loads new enemies and possibly treasure
  void openTreasure(Player *player, int numBossesDefeated); // Allows user to open treasure
  void viewEnemies(Game &game, Player *player, int numBossesDefeated); // Displays enemies within forest
};

#endif