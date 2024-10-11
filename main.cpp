// Include libraries
#include <iostream>
#include <string>

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

int main() {
  // Create game
  Game ChampionsOfSand;
  int numBossesDefeated = 0;

  // Initialies shops and locations
  ChampionsOfSand.initialiseShops();
  ChampionsOfSand.initialiseLocations();

  // Start Game menu

  // New || Load Game
  Player *player;
  // Tutorial

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