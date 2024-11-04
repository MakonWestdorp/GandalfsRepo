#include "Shop.h"

#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"
#include "Game.h"
#include "Player.h"

// Include libraries for pause and namepsaces
#include <chrono>
#include <thread>
using namespace chrono;
using namespace this_thread;

// Include library for fill
#include <algorithm>

Shop::Shop() {
  // Setting all variables to 0, nullptr or some equivalent
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

Shop::Shop(int numBossesDefeated, string shopName, string shopKeeperName,
           string description, string asciiDescription, int type) {
  // Setting all values to input values
  this->shopName = shopName;
  this->shopKeeperName = shopKeeperName;
  this->description = description;
  this->asciiDescription = asciiDescription;
  this->shopLevel = 1;
  this->ownerAnnoyanceLevel = 0;
  this->inventorySize = 5;

  // Generate inventory depending on type
  prices = new int[5];
  if (type == 1) {  // If type = 1 the shop will have an attack item inventory
    this->inventory = new BaseItem *[5];
    for (int i = 0; i < inventorySize; i++) {
      inventory[i] = new AttackItem(numBossesDefeated);
      // Set prices
      prices[i] = inventory[i]->GetChallengeRating() * 2 + ((rand() % 7) - 2);
    }
    
  } else if (type ==
             2) {  // If type = 2 the shop will have a base item inventory
    this->inventory = new BaseItem *[5];
    for (int i = 0; i < inventorySize; i++) {
      inventory[i] = new BuffItem(numBossesDefeated);
      prices[i] = numBossesDefeated * 10 + 10 + ((rand() % 7) - 2);
    }
  }

  // Set for sale statuses
  forSaleStatus = new bool[5];
  fill(forSaleStatus, forSaleStatus + inventorySize, true);
}

BaseItem *Shop::viewInventory() { return *this->inventory; }

int *Shop::viewPrices() { return this->prices; }

bool *Shop::viewForSaleStatus() { return this->forSaleStatus; }

string Shop::purchaseItem(int itemNumber, Player *player) {
  // Checking if item exists
  if (itemNumber > inventorySize) {
    this->ownerAnnoyanceLevel +=
        0.5;  // Owner will be annoyed if user input is invalid
    return "Item does not exist";

  } else {
    itemNumber -= 1;  // Decreases item number by 1 so it can be used to access
                      // the correct element of the array

    if (forSaleStatus[itemNumber] == false) {  // Check if item is for sale
      return "Item not for sale";

    } else {
      if (prices[itemNumber] >
          player->getCashOnHand()) {  // Check if player has enough cash
        return "Insufficient funds";

      } else {  // Add item to inventory
        forSaleStatus[itemNumber] = false;
        player->setCashOnHand(player->getCashOnHand() -
                              prices[itemNumber]);  // Take payment

        if (inventory[itemNumber]->getIsBuff() ==
            true) {  // Call buff item add inventory
          player->AddItemToInventory(inventory[itemNumber]);
        } else {  // Call attack item add inventory
          player->AddItemToInventory(inventory[itemNumber]);
        }

        return "Item purchased";
      }
    }

    return "Error";  // If none of the above returns have been called an error
                     // has occured
  }
}

bool Shop::showShopInterface(Player *player, Game &game, int type) {
  // Divider to seperate elements of the visual
  string divider =
      "+------------------------------------------------------------------+";
  int userDecision = 0, count = 0;
  ;

  // Clears terminal
  cout << endl << endl << endl << endl << endl << endl << endl << endl;

  // Show shop visuals
  cout << divider << endl
       << this->shopName << "   |   Shop Keeper : " << this->shopKeeperName
       << "   |   Cash on hand : " << player->getCashOnHand() << endl
       << divider << endl
       << this->description << endl
       << divider << endl;

  // Show shop options
  for (count = 0; count < inventorySize; count++) {
    cout << count + 1 << ". " << inventory[count]->getName() << " | $"
         << prices[count] << " "
         << (forSaleStatus[count] ? "For Sale |" : "N/A |");
        if (type == 1) {
        cout << " Damage: " << inventory[count]->GetChallengeRating();
        } else {
        cout << " Buff: " << inventory[count]->GetChallengeRating();
        }
        cout << " | Type: " << inventory[count]->getDamageOrNameStat() << endl;
  }

  // Prompt user for input
  count++;
  cout << count << ". Leave Shop" << endl << divider << endl;
  cin >> userDecision;

  // Check if cin failed or input invalid
  userDecision = game.cinChecker(1, count, userDecision);

  cout << divider << endl;

  // Process user decision
  if (userDecision <= inventorySize &&
      userDecision > 0) {  // If input matches item number buy item
    cout << purchaseItem(userDecision, player) << endl << divider << endl;
    sleep_for(seconds(1));
    return true;                       // User will stay in the shop
  } else if (userDecision == count) {  // If input matches leave shop option
    cout << "Have a good day!" << endl << divider << endl;
    sleep_for(seconds(1));
    return false;  // User will leave
  } else {         // If input matches niether of the above
    cout << "I think you mispoke" << endl << divider << endl;
    sleep_for(seconds(1));
    return true;  // User will stay
  }
}

void Shop::updateShop(int numBossesDefeated, int type) {
  // Delete old inventory
  delete this->inventory;
  delete this->prices;
  delete this->forSaleStatus;

  // Generate inventory depending on type
  if (type == 1) {  // If type = 1 the shop will have an attack item inventory
    this->inventory = new BaseItem *[5];
    for (int i = 0; i < inventorySize; i++) {
      inventory[i] = new AttackItem(numBossesDefeated);
    }
  } else if (type ==
             2) {  // If type = 2 the shop will have a base item inventory
    this->inventory = new BaseItem *[5];
    for (int i = 0; i < inventorySize; i++) {
      inventory[i] = new BuffItem(numBossesDefeated);
    }
  }

  // Set prices
  prices = new int[5];
  for (int i = 0; i < inventorySize; i++) {
    // Price = ChallengeRating (bosses defeated) times 10 + 10 + a random value
    // between -2 and 5 to vary price
    prices[i] =
        inventory[i]->GetChallengeRating() * 2 + ((rand() % 7) - 2 + 10);
  }

  // Set for sale statuses
  forSaleStatus = new bool[5];
  fill(forSaleStatus, forSaleStatus + inventorySize, true);
}
