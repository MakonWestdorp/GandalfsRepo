#ifndef GAME_H
#define GAME_H

// Include libraries
#include <iostream>
#include <string>

// Include classes
#include "Location.h"

// Namespace
using namespace std;

class Game {
    private:
        // Variables for keeping track of the game
        int bossesDefeated;
        Location currentLocation; 
        bool playerAlive; 
    protected:
        Game(); // Default constructor
        Game(int bossesDefeated, Location location, bool playerAlive); // Constructor
        bool initialiseShops(); // Initialises shops
        bool initialiseLocations(); // Initialises locations
        void playTutorial(); // Plays the tutorial 
        void openCharacterCreator(); // Runs the character creator
        bool saveGame(); // Saves the game
        void exitGame(); // Exits the game
        bool loadGame(); // Loads the game
        void endGame(); // Ends the game if the player dies
    public: 
        bool travelToLocation(Location destination); // Switches location
        bool travelToShop(); // Switches to a shop
        void setCurrentLocation(Location currentLocation); // Sets current location
        Location viewCurrentLocation(); // Returns current location
};

#endif