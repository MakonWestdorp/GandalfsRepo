#ifndef SHOP_H
#define SHOP_H

// Include libraries
#include <iostream>
#include <string> 

using namespace std; 

// Temporary forward declare as BaseItem class does not yet exist
class BaseItem;
class Player;

class Shop {
    private:
        // Inventory variables
        BaseItem *inventory; 
        int *prices;
        bool *forSaleStatus;  
        // Description variables
        string shopName, shopKeeperName, description, asciiDescription; 
        // Other variables
        int shopLevel, inventorySize; 
        float ownerAnnoyanceLevel; 
    public:
        Shop(); // Default Constructor 
        Shop(int &numBossesDefeated, int *prices, bool *forSaleStatus, string shopName, 
             string shopKeeperName, string description, string asciiDescription, string type); // Constructor 
        BaseItem *viewInventory(); // Returns inventory
        int *viewPrices(); // Returns prices
        bool *viewForSaleStatus(); // Returns for sale statuses 
        string purchaseItem(int itemNumber, Player *player); // Allows user to purchase item
        bool showShopInterface(Player *player); // Shows the shop interface and items
        void updateShop(int &numBossesDefeated, int *prices, bool *forSaleStatus); // Updates inventory


};
#endif