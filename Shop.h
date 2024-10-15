#ifndef SHOP_H
#define SHOP_H

// Include libraries
#include <iostream>
#include <string>

#include "BaseItem.h"
#include "Player.h"

using namespace std;

class BaseItem;
class Player;
class Game;

class Shop {
 private:
  // Inventory variables
  BaseItem **inventory;
  int *prices;
  bool *forSaleStatus;
  // Description variables
  string shopName, shopKeeperName, description, asciiDescription;
  // Other variables
  int shopLevel, inventorySize;
  float ownerAnnoyanceLevel;

 public:
  ~Shop() {};
  Shop();  // Default Constructor
  Shop(int numBossesDefeated, string shopName, string shopKeeperName,
       string description, string asciiDescription, int type);  // Constructor
  BaseItem *viewInventory();  // Returns inventory
  int *viewPrices();          // Returns prices
  bool *viewForSaleStatus();  // Returns for sale statuses
  string purchaseItem(int itemNumber,
                      Player *player);  // Allows user to purchase item
  bool showShopInterface(Player *player, Game &game,
                         int type);  // Shows the shop interface and items
  void updateShop(int numBossesDefeated, int type);  // Updates inventory
};
#endif