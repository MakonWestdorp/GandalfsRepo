#ifndef SHOP_H
#define SHOP_H

// Include libraries
#include <iostream>
#include <string> 

using namespace std; 

// Temporary forward declare as BaseItem class does not yet exist
class BaseItem; 

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
        Shop(BaseItem *inventory, int *prices, bool *forSaleStatus, string shopName, 
             string shopKeeperName, string description, string asciiDescription); // Constructor 
        BaseItem* viewInventory(); // Returns inventory
        int* viewPrices(); // Returns prices
        bool* viewForSaleStatus(); // Returns for sale statuses 
        string purchaseItem(int itemNumber); // Allows user to purchase item
        void showShopInterface(); // Shows the shop interface and items
        void updateShop(BaseItem *inventory, int *prices, bool *forSaleStatus); // Updates inventory


};
#endif