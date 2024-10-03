#include "Game.h"

#include "Location.h"

// Protected functions
Game::Game() {
  this->bossesDefeated = 0;
  this->currentLocation = Location();
  this->playerAlive = true;
}

Game::Game(int bossesDefeated, Location location, bool playerAlive) {
  this->bossesDefeated = bossesDefeated;
  this->currentLocation = location;
  this->playerAlive = playerAlive;
}

bool Game::initialiseShops() { return false; }

bool Game::initialiseLocations() { return false; }

void Game::playTutorial() {}

void Game::openCharacterCreator() {}

bool Game::saveGame() { return false; }

void Game::exitGame() {}

bool Game::loadGame() { return false; }

void Game::endGame() {}

// Public functions
void Game::travel(Location destination) { this->currentLocation = destination; }

void Game::travelToShop() {}

void Game::setCurrentLocation(Location location) {
  this->currentLocation = location;
}

Location Game::viewCurrentLocation() { return this->currentLocation; }

int Game::getNumBosses() { return bossesDefeated; }

void Game::setNumBosses(int InputNumBosses) { bossesDefeated = InputNumBosses; }
