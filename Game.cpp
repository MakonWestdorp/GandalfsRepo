#include "Game.h"

#include "Location.h"
#include "Town.h"
#include "Forest.h"
#include "Arena.h"
#include "Shop.h"

#include <algorithm>
using namespace std;

// Protected functions
Game::Game() {
  this->currentLocation = nullptr;
  this->playerAlive = true;
  this->gameRunning = true;
}

void Game::initialiseShops() {
  int numBossesDefeated = 1; // Temporary
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

  // Shop prices - temporary 
  int *WeaponPrices = new int[5];
  fill(WeaponPrices,WeaponPrices + 5,20);
  int *MagicPrices = new int[5];
  fill(MagicPrices,MagicPrices + 5,30);
  int *ArmourPrices = new int[5];
  fill(ArmourPrices,ArmourPrices + 5,40);
  int *GeneralPrices = new int[5];
  fill(GeneralPrices,GeneralPrices + 5,10);

  // Shop for sale statues - temporary
  bool *WeaponForSale = new bool[5];
  fill(WeaponForSale,WeaponForSale+5,true);
  bool *MagicForSale = new bool[5];
  fill(MagicForSale,MagicForSale+5,true);
  bool *ArmourForSale = new bool[5];
  fill(ArmourForSale,ArmourForSale+5,true);
  bool *GeneralForSale = new bool[5];
  fill(GeneralForSale,GeneralForSale+5,true);

  // Specific constructors will be used later
  WeaponShop = Shop(numBossesDefeated,WeaponPrices,WeaponForSale,"Steel & Sorcery","Timmy", WeaponDescription, WeaponAscii,"Attack");
  MagicShop = Shop(numBossesDefeated,MagicPrices,MagicForSale,"The Eldritch Emporium","Rufus",MagicDescription,MagicAscii,"Attack");
  ArmourShop = Shop(numBossesDefeated,ArmourPrices,ArmourForSale,"Defender's Den","Keith",ArmourDescription,ArmourAscii,"Buff");
  GeneralShop = Shop(numBossesDefeated,GeneralPrices,GeneralForSale,"The Adventurer's Arsenal","James",GeneralDescription,GeneralAscii,"Buff");

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
  Forest* ForestName = new Forest("Shadowleaf Woods",forestDescription,forestAscii,1);
  Arena* ArenaName = new Arena("The Colosseum of Champions",arenaDescription,arenaAscii);

  Locations = new Location*[3]; 
  Locations[0] = TownName;
  Locations[1] = ForestName;
  Locations[2] = ArenaName;
}

void Game::playTutorial() {}

void Game::openCharacterCreator() {}

bool Game::saveGame() { return false; }

void Game::exitGame() {}

bool Game::loadGame() { return false; }

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
