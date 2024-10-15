#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <string>

#include "Location.h"

using namespace std;

class Game;

class Arena : public Location {
 private:
  Enemy *Opponent;
  int EnemiesDefeated = 0;

 public:
  Arena();
  Arena(string name, string description, string asciiDescription);
  ~Arena() {};
  void travelToLocation(Game &game, Location *location, Player *player,
                        int numBossesDefeated);
  void showLocation(Game &game, Player *player, int numBossesDefeated);
  void viewPlayerStats(Game &game, Player *player, int numBossesDefeated);
  void callForBattle(Game &game, Player *player, int numBossesDefeated);
};

#endif