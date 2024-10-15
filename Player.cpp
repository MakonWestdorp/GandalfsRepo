#include "Player.h"

#include "BuffItem.h"
#include "Enemy.h"
#include "Entity.h"

Player::Player() {
  // Player wil obviously start the game alive, and has $50 to buy items.
  isAlive = true;
  CashOnHand = 50;

  int NumberOfPointsToDistrubute = 20;
  strength = 0;
  healthPoints = 0;
  defence = 0;
  magic = 0;
  string divider =
      "+------------------------------------------------------------------+";
  cout << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << divider << endl
       << "Welcome to the Character Creator!" << endl
       << "Your Character has 4 Stats. Health Points, Strength, Defence and "
          "Magic."
       << endl;
  cout << divider << endl
       << "You have: " << NumberOfPointsToDistrubute
       << " points to distribute among your Character Stats." << endl
       << divider << endl;

  while (true) {
    cout << "You have: " << NumberOfPointsToDistrubute
         << " left to distribute to your stats." << endl;
    cout << "How many points would you like to allocate to your Health Points?"
         << endl;
    // READ IN USER INPUT FOR HP;
    int UserInput;

    while (true) {
      cin >> UserInput;

      if (cin.fail() || UserInput < 1 ||
          UserInput > NumberOfPointsToDistrubute) {
        cin.clear();             // Clear the error flags
        cin.ignore(1000, '\n');  // Ignore the rest of the invalid input
        cout << "That doesn't look right! Please enter a number between 0 and "
             << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // Valid input, exit loop
      }
    }

    cout << divider << endl;
    healthPoints += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << " left to distribute to your stats." << endl;
    cout << "How many points would you like to allocate to Strength?" << endl;
    // READ IN USER INPUT FOR STR;
    while (true) {
      cin >> UserInput;

      if (cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        cin.clear();             // Clear the error flags
        cin.ignore(1000, '\n');  // Ignore the rest of the invalid input
        cout << "That doesn't look right! Please enter a number between 0 and "
             << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // Valid input, exit loop
      }
    }

    cout << divider << endl;
    strength += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << " left to distribute to your stats." << endl;
    cout << "How many points would you like to allocate to Defence?" << endl;
    // READ IN USER INPUT FOR DEF;
    while (true) {
      cin >> UserInput;

      if (cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        cin.clear();             // Clear the error flags
        cin.ignore(1000, '\n');  // Ignore the rest of the invalid input
        cout << "That doesn't look right! Please enter a number between 0 and "
             << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // Valid input, exit loop
      }
    }

    cout << divider << endl;
    defence += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << "left to distribute to your stats." << endl;
    cout << "How many points would you like to allocate to Magic?" << endl;
    // READ IN USER INPUT FOR MAG;
    while (true) {
      cin >> UserInput;

      if (cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        cin.clear();             // Clear the error flags
        cin.ignore(1000, '\n');  // Ignore the rest of the invalid input
        cout << "That doesn't look right! Please enter a number between 0 and "
             << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // Valid input, exit loop
      }
    }

    cout << divider << endl;
    magic += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << "left to distribute to your stats." << endl;
    if (NumberOfPointsToDistrubute == 0) {
      break;
    }
  }

  cout << "Please enter a name for your character:";
  cin >> name;
  cout << endl;
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;
  cout << "Please choose what type of damage you would like to be resistant to:"
       << endl
       << "1. Magic" << endl
       << "2. Piercing" << endl
       << "3. Bludgeoning" << endl
       << "4. Slashing" << endl;
  int UserInput = 0;
  while (true) {
    cin >> UserInput;

    if (cin.fail() || UserInput <= 0) {
      cin.clear();             // Clear the error flags
      cin.ignore(1000, '\n');  // Ignore the rest of the invalid input
      cout << "That doesn't look right! Please enter a number between 1 and 4:";
    } else {
      break;  // Valid input, exit loop
    }
  }
  switch (UserInput) {
    case 1:
      Resistance = "Magic";
      break;
    case 2:
      Resistance = "Piercing";
      break;
    case 3:
      Resistance = "Bludgeoning";
      break;
    case 4:
      Resistance = "Slashing";
      break;
  }

  CurrentInventorySize = 0;
  Inventory = nullptr;
}

Player::Player(string inputName, int inputHP, int inputSTR, int inputDEF,
               int inputMAG, string inputResistance) {
  // Set values
  name = inputName;
  healthPoints = inputHP;
  defence = inputDEF;
  strength = inputSTR;
  magic = inputMAG;
  Resistance = inputResistance;
  isAlive = true;
  CashOnHand = 50;

  // Calculate Challenge Rating
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;

  CurrentInventorySize = 0;
  Inventory = nullptr;
}

int Player::TakeTurn(Enemy* Target, int CurrentRound, bool& KeepFighting) {
  string divider =
      "+------------------------------------------------------------------+";
  cout << "Player HP: " << healthPoints
       << "  |  Current Round: " << CurrentRound
       << "  |  Enemy HP: " << Target->getHP() << endl
       << divider << endl;

  cout << "1. Attack normally" << endl;
  cout << "2. Attack using Magic." << endl;
  if (CurrentInventorySize != 0) {
    for (int i = 0; i < CurrentInventorySize; i++) {
      if (Inventory[i]->getIsBuff() == true) {
        cout << i + 3 << ". Use Item: " << Inventory[i]->getName()
             << " | Item Type:" << "Buff" << endl;
      } else {
        cout << i + 3 << ". Use Item: " << Inventory[i]->getName()
             << " | Item Type:" << "Attack" << endl;
      }
    }
  }
  cout << CurrentInventorySize + 3 << ". Leave Fight" << endl;
  int UserInput = 0;
  cin >> UserInput;

  // Check if input is correct
  while (cin.fail() || UserInput < 1 || UserInput > CurrentInventorySize + 4) {
    cin.clear();  // clear the error flag
    cin.ignore(1000, '\n');
    cout << "That doesnt look right! Please enter a number between 1 and "
         << CurrentInventorySize + 4 << ": ";
    cin >> UserInput;
  }

  if (UserInput == 1) {
    cout << "You are punching " << Target->getName() << endl;
    Attack(Target);
    // Attack
  } else if (UserInput == 2) {
    cout << "You are using magic to hurt " << Target->getName() << endl;
    Attack(Target, rand() % magic + 1, "Magic");
  }
  if (UserInput == CurrentInventorySize + 3) {
    KeepFighting = false;
    // Leave
  } else if (UserInput > 2 && (UserInput - 2) <= CurrentInventorySize) {
    if (Inventory[UserInput - 3]->getIsBuff() == true) {
      cout << "You are using your " << Inventory[UserInput - 3]->getName()
           << " to buff your "
           << Inventory[UserInput - 3]->getDamageOrNameStat() << " by "
           << Inventory[UserInput - 3]->getDamageOrBuff() << " points!" << endl;
      BuffItem* buffItem = dynamic_cast<BuffItem*>(Inventory[UserInput - 3]);
      buffItem->UseItem(this, "Apply");
    } else {
      cout << "You are using your " << Inventory[UserInput - 3]->getName()
           << " to attack " << Target->getName() << endl;
      Inventory[UserInput - 3]->UseItem(Target);
    }
  }

  // Use inventory item
  return KeepFighting;
}

// for loop, 1 option per Item in inventory
// Leave Fight *Warning* this causes you to take damage.

void Player::AddItemToInventory(BaseItem* Item) {
  BaseItem** TempInventory = new BaseItem*[CurrentInventorySize + 1];

  for (int i = 0; i < CurrentInventorySize; i++) {
    TempInventory[i] = Inventory[i];
  }

  TempInventory[CurrentInventorySize] = Item;
  delete[] Inventory;
  Inventory = TempInventory;
  CurrentInventorySize++;
}

int Player::getPlayerInventorySize() { return CurrentInventorySize; }

void Player::setPlayerInventorySize(int inventorySize) {
  this->CurrentInventorySize = inventorySize;
}

void Player::setInventory(BaseItem** inventory) { this->Inventory = inventory; }
