#include "Game.h"

#include "Location.h"
#include "Town.h"
#include "Forest.h"
#include "Arena.h"
#include "Shop.h"

#include <algorithm>
#include <fstream>
using namespace std;

// Protected functions
Game::Game() {
  this->currentLocation = nullptr;
  this->playerAlive = true;
  this->gameRunning = true;
}

void Game::initialiseShops() {
  int numBossesDefeated = 0; // Temporary
  // Shop Descriptions
  string WeaponDescription = "Steel & Sorcery offers finely crafted blades, \nfrom master-forged steel to rare enchanted swords";
  string MagicDescription = "A mystical emporium filled with enchanting staves, \neach imbued with the essence of elemental magic";
  string ArmourDescription = "A haven for warriors and mages a like, \nshowcasing a stunning array of handcrafted armor";
  string GeneralDescription = "A bustling shop filled with essential adventurer supplies, \nfrom healing potions to magical buff items";
  
  // Ascii Art
  string WeaponAscii = "";
  string MagicAscii = "";
  string ArmourAscii = "";
  string GeneralAscii = "";


  // Specific constructors will be used later
  WeaponShop = Shop(numBossesDefeated,"Steel & Sorcery","Timmy", WeaponDescription, WeaponAscii,1);
  MagicShop = Shop(numBossesDefeated,"The Eldritch Emporium","Rufus",MagicDescription,MagicAscii,1);
  ArmourShop = Shop(numBossesDefeated,"Defender's Den","Keith",ArmourDescription,ArmourAscii,2);
  GeneralShop = Shop(numBossesDefeated,"The Adventurer's Arsenal","James",GeneralDescription,GeneralAscii,2);

  Shops = new Shop[4];
  Shops[0] = WeaponShop;
  Shops[1] = MagicShop;
  Shops[2] = ArmourShop;
  Shops[3] = GeneralShop;
}

void Game::initialiseLocations() {
  // Location Descriptions
  string townDescription = 
      "The medieval town bustles with life, its cobblestone streets \n winding "
      "past stone shops beneath the shadow of a towering castle";
  string forestDescription = 
      "In a dark, mist-shrouded forest teeming with fearsome monsters," 
      "\n hidden treasures glimmer among ancient ruins, luring adventurers";
  string arenaDescription =
      "Within these ancient walls, warriors gather to prove their strength," 
      "\n skill, and cunning in the ultimate test of combat";

  // Ascii Descriptions
  string townAscii = "";
  string forestAscii = "";
  string arenaAscii = "";

  // Specific constructors will be used later
  Town* TownName = new Town("Hidden Grove Settlement",townDescription,townAscii);
  Forest* ForestName = new Forest("Shadowleaf Woods",forestDescription,forestAscii);
  Arena* ArenaName = new Arena("The Colosseum of Champions",arenaDescription,arenaAscii);

  Locations = new Location*[3]; 
  Locations[0] = TownName;
  Locations[1] = ForestName;
  Locations[2] = ArenaName;
}

bool Game::saveGame(Player *player, int &numBossesDefeated, string fileName) {
    // Create file to be written to
    fileName = fileName + ".txt";
    ofstream savePlayerData(fileName);

    if (savePlayerData.is_open()) { // Write to file if it can be opened
        /*
          Writes player values to playerData.txt in the format
          Comment
          Player variable

          Returns true if values were written
          Returns false if values could not be written
        */

        savePlayerData << "Name:\n";
        savePlayerData << player->getName() << endl;
        savePlayerData << "Health:\n";
        savePlayerData << player->getHP() << endl;
        savePlayerData << "Strength:\n";
        savePlayerData << player->getSTR() << endl;
        savePlayerData << "Defence:\n";
        savePlayerData << player->getDEF() << endl;
        savePlayerData << "Magic:\n";
        savePlayerData << player->getMAG() << endl;
        savePlayerData << "Resistance:\n";
        savePlayerData << player->getRes() << endl;
        savePlayerData << "Bosses_defeated:\n";
        savePlayerData << numBossesDefeated << endl;
        savePlayerData << "Cash_On_Hand:\n";
        savePlayerData << player->getCashOnHand() << endl;
        savePlayerData << "Challenge_Rating:\n";
        savePlayerData << player->getChallengeRating() << endl;

        savePlayerData.close(); // Close file 

        return true;
    } else 
    {
        return false;
    }
}

void Game::exitGame() {
    gameRunning = false;
}

bool Game::loadGame(Player *player, int &numBossesDefeated, string fileName) { 
    fileName = fileName + ".txt";
    ifstream playerFileIn(fileName);

    // Create temporary variables
    string name = "", resistance = "";
    int health = 0, strength = 0, defence = 0, magic = 0, challengeRating = 0, cashOnHand = -1;

    // Set to -1 so the program can check for an update later
    numBossesDefeated = -1;

    if (playerFileIn.is_open()) {
        string commentsHolder = "";

        // Read in name
        playerFileIn >> commentsHolder >> name; // Read into temporary variable
        player->setName(name); // Set name

        // Read in health
        playerFileIn >> commentsHolder >> health;
        player->setHP(health);
      
        // Read in strength
        playerFileIn >> commentsHolder >> strength;
        player->setSTR(strength);

        // Read in defence
        playerFileIn >> commentsHolder >> defence;
        player->setDEF(defence);

        // Read in magic
        playerFileIn >> commentsHolder >> magic;
        player->setMAG(magic);

        // Read in resistance
        playerFileIn >> commentsHolder >> resistance;
        player->setRes(resistance);

        // Read in bosses defeatead 
        playerFileIn >> commentsHolder >> numBossesDefeated;

        // Read in cash on hand
        playerFileIn >> commentsHolder >> cashOnHand;
        player->setCashOnHand(cashOnHand);

        // Read in challenge rating
        playerFileIn >> commentsHolder >> challengeRating;
        player->setChallengeRating(challengeRating);

        playerFileIn.close();

        // Check if read in was successful
        if (name == "" || health == 0 || strength == 0 || defence == 0 || magic == 0 || 
            resistance == "" || numBossesDefeated == -1 || cashOnHand == -1 || challengeRating == 0) {
          return false;
        } else {
          Shops[0].updateShop(numBossesDefeated,1);
          Shops[1].updateShop(numBossesDefeated,1);
          Shops[2].updateShop(numBossesDefeated,2);
          Shops[3].updateShop(numBossesDefeated,2);
          return true;
        }
    } else {
        return false;
    }

 }

void Game::endGame() {
  this->gameRunning = false;
}

// Public functions
void Game::travel(Location *destination) {
  this->currentLocation = destination;
}

void Game::setCurrentLocation(Location *location) {
  this->currentLocation = location;
}

Location *Game::viewCurrentLocation() { return this->currentLocation; }

Shop *Game::viewShops()
{
    return this->Shops;
}

Location **Game::viewLocations()
{
    return this->Locations;
}

  bool Game::isGameRunning()
  {
      return gameRunning;
  }
