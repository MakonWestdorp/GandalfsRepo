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
  string attackShopDescription = 
  "In the shadowy corners of this ancient weapons shop, enchanted swords, \n"
  "mystical bows, and arcane artifacts line the walls, each weapon imbued\n"
  "with a unique tale of valor, waiting for a hero worthy to wield \nits legendary power.";
  string buffShopDescription = 
  "In the dim glow of this magical apothecary, shelves are stacked with \nshimmering"
  "potions and enchanted scrolls, each ready to bestow powerful \nbuffs and magical" 
  "enhancements on brave travelers.";
  
  // Ascii Art
  string attackShopAscii = "";
  string buffShopAscii = "";


  // Specific constructors will be used later
  attackShop = Shop(numBossesDefeated,"Steel & Sorcery","Timmy", attackShopDescription, attackShopAscii,1);
  buffShop = Shop(numBossesDefeated,"Charms & Brews","Rufus",buffShopDescription,buffShopAscii,2);

  Shops = new Shop[2];
  Shops[0] = attackShop;
  Shops[1] = buffShop;

}

void Game::initialiseLocations() {
  // Location Descriptions
  string townDescription = 
      "The medieval town bustles with life, its cobblestone streets \nwinding "
      "past stone shops beneath the shadow of a towering castle";
  string forestDescription = 
      "In a dark, mist-shrouded forest teeming with fearsome monsters," 
      "\n hidden treasures glimmer among ancient ruins, luring adventurers";
  string arenaDescription =
      "Within these ancient walls, warriors gather to prove their strength," 
      "\nskill, and cunning in the ultimate test of combat";

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

        // Save player data
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

        // Save player inventory
        int tempInventorySize = player->getPlayerInventorySize();
        savePlayerData << "Player_Inventory_Size\n";
        savePlayerData << player->getPlayerInventorySize() << endl;
        for (int i = 0; i < tempInventorySize; i ++) {
        savePlayerData << "Item_" << i+1 << endl;
        savePlayerData << player->viewInventory()[i]->getName() << endl;
        savePlayerData << player->viewInventory()[i]->getDamageOrBuff() << endl;
        savePlayerData << player->viewInventory()[i]->getDamageOrNameStat() << endl;
        savePlayerData << player->viewInventory()[i]->GetChallengeRating() << endl;
        savePlayerData << player->viewInventory()[i]->getIsBuff() << endl;
        }

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
        playerFileIn >> commentsHolder >> health; // Store comment in string to be discarded then value into temporary variable
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

        // Read in player inventory
        int inventorySize = 0;
        playerFileIn >> commentsHolder >> inventorySize;
        player->setPlayerInventorySize(inventorySize);
        BaseItem **tempInventory = new BaseItem*[inventorySize];
        string itemName = "", damageTypeOrNameOfStat = "";
        int damageOrBuff = 0, itemChallengeRating = 0;
        bool isBuff = false;

        for (int i = 0; i < inventorySize; i++) {
          cout << "Running loop" << endl;
          itemName = "";
          damageTypeOrNameOfStat = "";
          damageOrBuff = 0;
          itemChallengeRating = 0;
          isBuff = false;

          playerFileIn >> commentsHolder;
          playerFileIn.ignore();
          getline(playerFileIn,itemName);
          playerFileIn >> damageOrBuff;
          playerFileIn >> damageTypeOrNameOfStat;
          playerFileIn >> itemChallengeRating; 
          playerFileIn >> isBuff;

          if (!isBuff) {
            tempInventory[i] = new AttackItem(itemName,damageOrBuff,damageTypeOrNameOfStat,challengeRating,isBuff);
          } else {
            tempInventory[i] = new BuffItem(itemName,damageOrBuff,damageTypeOrNameOfStat,challengeRating,isBuff);
          }
          
        }
        player->setInventory(tempInventory);

        playerFileIn.close();

        // Check if read in was successful
        if (name == "" || health == 0 || strength == 0 || defence == 0 || magic == 0 || 
            resistance == "" || numBossesDefeated == -1 || cashOnHand == -1 || challengeRating == 0) {
          cout << name << endl << health << endl << strength << endl << defence << endl << magic << endl << resistance << endl << numBossesDefeated << endl << cashOnHand << endl << challengeRating << endl;
          return false;
        } else {
          Shops[0].updateShop(numBossesDefeated,1);
          Shops[1].updateShop(numBossesDefeated,2);
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
