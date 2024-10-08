#include "Shop.h"
#include "BaseItem.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread> 
using namespace chrono;
using namespace this_thread;

// Include library for fill
#include <algorithm>

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

Shop::Shop(int &numBossesDefeated, int *prices, bool *forSaleStatus, string shopName, string shopKeeperName, string description, string asciiDescription)
{
    this->prices = prices; 
    this->forSaleStatus = forSaleStatus;
    this->shopName = shopName;
    this->shopKeeperName = shopKeeperName; 
    this->description = description;
    this->asciiDescription = asciiDescription; 
    this->shopLevel = 1; 
    this->ownerAnnoyanceLevel = 0; 
    this->inventorySize = 5; 

    // Generate inventory
    this->inventory = new BaseItem[5];
    for (int i = 0; i < inventorySize; i++) {
        inventory[i] = BaseItem(numBossesDefeated);
    }

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

string Shop::purchaseItem(int itemNumber, int &cashOnHand)
{

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

bool Shop::showShopInterface(int &cashOnHand)
{
    // Divider to seperate elements of the visual
    string divider = "+------------------------------------------------------------------+";
    int userDecision = 0, count = 0; ; 

    // Clears terminal
    cout << endl << endl << endl << endl << endl << endl; 

    // Show shop visuals 
    cout << divider << endl << this->shopName << "   |   Shop Keeper : " << this->shopKeeperName 
         << "   |   Cash on hand : " << cashOnHand << endl << divider << endl << this->description 
         << endl << divider << endl; 

    // Show shop options
    for (count = 0; count < inventorySize; count++) {
        cout << count+1 << ". " << inventory[count].getName() << " $" << prices[count] << " " 
             << (forSaleStatus[count] ? "For Sale." : "Not for sale.") << endl;
    }
    
    // Prompt user for input
    count++; 
    cout << count << ". Leave Shop" << endl << divider << endl;
    cin >> userDecision; 
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000, '\n');
      userDecision = 10;
    }
    cout << divider << endl; 

    if (userDecision <= inventorySize && userDecision > 0) {
        cout << purchaseItem(userDecision,cashOnHand) << endl << divider << endl; 
        sleep_for(seconds(2));
        return true; // User will stay in the shop
    } else if (userDecision == count) {
        cout << "Have a good day!" << endl << divider << endl; 
        sleep_for(seconds(2));
        return false; // User will leave
    } else {
        cout << "I think you mispoke" << endl << divider << endl;
        sleep_for(seconds(2));
        return true; // User will stay
    }
     


}

void Shop::updateShop(int &numBossesDefeated, int *prices, bool *forSaleStatus)
{
    // Delete old inventory
    //delete this->inventory; 
    //delete this->prices; 
    //delete this->forSaleStatus; 

    // Implement new inventory
    this->prices = prices; 
    this->forSaleStatus = forSaleStatus;

    for (int i = 0; i < inventorySize; i++) {
        inventory[i] = BaseItem(numBossesDefeated);
    }
}
