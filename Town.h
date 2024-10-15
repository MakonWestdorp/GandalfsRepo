#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <string>

#include "Location.h"

class Game;
class Shop;
class Entity;
class Enemy;
class Player;

class Town : public Location {
 public:
  ~Town() {}; // Destructor
  Town(); // Constructor
  Town(string name, string description, string asciiDescription); // Specific constructor
  void travelToLocation(Game &game, Location *location, Player *player,
                        int numBossesDefeated); // Allows player to travel to forest or arena
  void enterShop(Shop &shopName, Player *player, Game &game, int type); // Allows user to enter shop
  void showLocation(Game &game, Player *player, int numBossesDefeated); // Displays town
};

#endif