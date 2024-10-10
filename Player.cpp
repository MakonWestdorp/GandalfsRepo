#include "Player.h"
#include "BuffItem.h"
#include "Entity.h"
#include "Enemy.h"

Player::Player() {
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
       << "You have: " << NumberOfPointsToDistrubute
       << " points to distribute among your Character Stats." << endl
       << divider << endl;
  cout << "Yours Character has 4 Stats.Health Points, Strength, Defence and "
          "Magic."
       << endl;

  while (true) {
    cout << "You have: " << NumberOfPointsToDistrubute
         << " left to distribute to your stats." << endl;
    cout << "How many points would you like to allocate to your Health Points?"
         << endl;
    // READ IN USER INPUT FOR HP;
    int UserInput;

    while (true) {
      std::cin >> UserInput;

      if (std::cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        std::cin.clear();  // clear the error flag
        std::cout
            << "That doesnt look right! Please enter a number between 0 and "
            << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // valid input, exit loop
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
      std::cin >> UserInput;

      if (std::cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        std::cin.clear();  // clear the error flag
        std::cout
            << "That doesnt look right! Please enter a number between 0 and "
            << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // valid input, exit loop
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
      std::cin >> UserInput;

      if (std::cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        std::cin.clear();  // clear the error flag
        std::cout
            << "That doesnt look right! Please enter a number between 0 and "
            << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // valid input, exit loop
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
      std::cin >> UserInput;

      if (std::cin.fail() || UserInput < 0 ||
          UserInput > NumberOfPointsToDistrubute) {
        std::cin.clear();  // clear the error flag
        std::cout
            << "That doesnt look right! Please enter a number between 0 and "
            << NumberOfPointsToDistrubute << ": ";
      } else {
        break;  // valid input, exit loop
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
  string name;
  cout << "Please enter a name for your character:";
  std::cin >> name;
  cout << endl;
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;
  Resistance = "Magic";
}

Player::Player(string inputName, int inputHP, int inputSTR, int inputDEF,
               int inputMAG, string inputResistance) {
  name = inputName;
  healthPoints = inputHP;
  defence = inputDEF;
  strength = inputSTR;
  magic = inputMAG;
  Resistance = inputResistance;
  isAlive = true;
}

int Player::TakeTurn(Enemy* Target, int CurrentRound, bool &KeepFighting) {
  string divider =
      "+------------------------------------------------------------------+";
  cout << "Player HP: " << healthPoints
       << "  |  Current Round: " << CurrentRound
       << "  |  Enemy HP: " << Target->getHP() << endl
       << divider << endl;

  cout << "1. Attack normally" << endl;
  if (CurrentInventorySize != 0) {
    for (int i = 0; i < CurrentInventorySize; i++) {
      if (Inventory[i].IsBuff) {
        cout << i + 2 << ". Use Item: " << Inventory[i].getName()
            << " | Item Type:" << "Buff" << endl;
      } else {
        cout << i + 2 << ". Use Item: " << Inventory[i].getName()
            << " | Item Type:" << "Attack" << endl;
      }
    }
  }
  cout << CurrentInventorySize + 2 << ". Leave Fight" << endl;
  int UserInput = 0;
    std::cin >> UserInput;

    // Check if input is correct
    while (std::cin.fail() || UserInput < 1 ||
        UserInput > CurrentInventorySize + 3) {
      std::cin.clear();  // clear the error flag
      std::cin.ignore(1000, '\n');
      std::cout
          << "That doesnt look right! Please enter a number between 1 and "
          << CurrentInventorySize + 3 << ": ";
      std::cin >> UserInput;
    }


  if (UserInput == 1) {
    Attack(Target);
    cout << "1\n";
    // Attack
  } else if (UserInput == CurrentInventorySize + 2) {
    KeepFighting = false;
    cout << "2\n";
    // Leave
  } else if (UserInput > 1 && (UserInput-2) <= CurrentInventorySize) {
    cout << "AHH\n";
      if (Inventory[UserInput - 2].IsBuff == true) {
        BaseItem* InventoryPTR = &Inventory[UserInput - 2];
        BuffItem* buffItem = dynamic_cast<BuffItem*>(InventoryPTR);
        buffItem->UseItem(this, "Apply");
        cout << "3\n";
      } else {
        Inventory[UserInput - 2].UseItem(Target);
        cout << Inventory[0].getName() << endl;
        cout << "4\n";
      }
  }

    // Use inventory item
    return KeepFighting;
}
  

// for loop, 1 option per Item in inventory
// Leave Fight *Warning* this causes you to take damage.

void Player::AddItemToInventory(BaseItem Item) {
  BaseItem* TempInventory = new BaseItem[CurrentInventorySize + 1];

  for (int i = 0; i < CurrentInventorySize; i++) {
    TempInventory[i] = Inventory[i];
  }

  TempInventory[CurrentInventorySize] = Item;
  delete[] Inventory;
  Inventory = TempInventory;
  CurrentInventorySize++;
}
