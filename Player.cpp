#include "Player.h"

#include <limits>
Player::Player() {
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
       << "You have:" << NumberOfPointsToDistrubute
       << " to distribute among your Character Stats." << endl
       << divider << endl;
  cout << "Yours Character has 4 Stats.Health Points, Strength, Defence and "
          "Magic."
       << endl;

  while (true) {
    cout << "You have: " << NumberOfPointsToDistrubute
         << "left to distribute to your stats." << endl;
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
    healthPoints += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << "left to distribute to your stats." << endl;
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
    strength += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << "left to distribute to your stats." << endl;
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
    magic += UserInput;
    NumberOfPointsToDistrubute = NumberOfPointsToDistrubute - UserInput;
    cout << "You have: " << NumberOfPointsToDistrubute
         << "left to distribute to your stats." << endl;
    if (NumberOfPointsToDistrubute == 0) {
      break;
    }
  }
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

void Player::TakeTurn() {
  string divider =
      "+------------------------------------------------------------------+";
  cout << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << divider << endl
       << "   |   Character Name : " << this->name
       << "   |   Current HP: " << healthPoints << endl
       << divider << endl;
}

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
