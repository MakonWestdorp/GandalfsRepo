// Include libraries
#include <iostream>
#include <string>

// Include classes
#include "Game.h"
#include "Location.h"
#include "BaseItem.h"
#include "Entity.h"
#include "Shop.h"
#include "AttackItem.h"
#include "BuffItem.h"
#include "Town.h"
#include "Forest.h"
#include "Arena.h"
#include "Player.h"
#include "Enemy.h"

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
    ChampionsOfSand.viewCurrentLocation()->showLocation(ChampionsOfSand, player, numBossesDefeated);
    }
}