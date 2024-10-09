#include "Player.h"

Player::Player() {}

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
  cout << endl << endl << endl << endl << endl << endl;
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
