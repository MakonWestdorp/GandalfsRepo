#include "Shop.h"

Shop::Shop()
{
    this->inventory = nullptr; 
    this->prices = nullptr; 
    this->forSaleStatus = nullptr;
    this->shopName = "No name";
    this->shopKeeperName = "No Name"; 
    this->description = "No description";
    this->asciiDescription = "No ascii description"; 
    this->shopLevel = 0; 
    this->ownerAnnoyanceLevel = 0; 
    this->inventorySize = 0;

}

Shop::Shop(BaseItem *inventory, int *prices, bool *forSaleStatus, string shopName, string shopKeeperName, string description, string asciiDescription)
{
    this->inventory = inventory; 
    this->prices = prices; 
    this->forSaleStatus = forSaleStatus;
    this->shopName = shopName;
    this->shopKeeperName = shopKeeperName; 
    this->description = description;
    this->asciiDescription = asciiDescription; 
    this->shopLevel = 1; 
    this->ownerAnnoyanceLevel = 0; 
    this->inventorySize = 5; 
}

BaseItem *Shop::viewInventory()
{
    return this->inventory;
}

int *Shop::viewPrices()
{
    return this->prices;
}

bool *Shop::viewForSaleStatus()
{
    return this->forSaleStatus;
}

string Shop::purchaseItem(int itemNumber)
{
    int cashOnHand = 10; // Temporary variable as player class does not yet exist

    // Checking if item exists
    if (itemNumber > inventorySize) { 
        this->ownerAnnoyanceLevel += 0.5; // Owner will be annoyed if user input is invalid
        return "Item does not exist";

    } else {
        itemNumber -= 1; // Decreases item number by 1 so it can be used to access the correct element of the array

        if (forSaleStatus[itemNumber] == false) {
            return "Item not for sale"; 

        } else {
            if (prices[itemNumber] > cashOnHand) {
                return "Insufficient funds";

            } else {
                forSaleStatus[itemNumber] = false;
                cashOnHand -= prices[itemNumber];
                return "Item purchased";
            }
        }

        return "Error"; 
    }

    

}

void Shop::showShopInterface()
{
    // Divider to seperate elements of the visual
    string divider = "+------------------------------------------------------------------+";

    // Clears terminal
    cout << endl << endl << endl << endl << endl << endl; 

    // Show shop visuals 
    cout << divider << endl << this->shopName << "  : " << this->shopKeeperName << endl 
         << divider << endl << this->description << endl << divider << endl; 

    // Show shop options
    for (int i = 0; i < inventorySize; i++) {
        cout << i+1 << ". " << endl ;
    }
}

void Shop::updateShop(BaseItem *inventory, int *prices, bool *forSaleStatus)
{
    // Delete old inventory
    delete this->inventory; 
    delete this->prices; 
    delete this->forSaleStatus; 

    // Implement new inventory
    this->inventory = inventory; 
    this->prices = prices; 
    this->forSaleStatus = forSaleStatus;
}
