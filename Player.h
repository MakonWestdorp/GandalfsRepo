#ifndef PLAYER_H
#define PLAYER_H
#include "BaseItem.h"
#include "Enemy.h"
#include "Entity.h"
class Player : public Entity {
 public:
  ~Player() {};
  Player();  // Calls the "Character Creator". Displays Users Options to input
             // in a Name and Player Stats.
  Player(string inputName, int inputHP, int inputSTR, int inputDEF,
         int inputMAG,
         string inputResistance);  // This constructor should never be called.

  int TakeTurn(
      Enemy* Target, int CurrentRound,
      bool& KeepFighting);  // Used in Combat. displays available options for
                            // combat, and applies them based on user input.

  void AddItemToInventory(
      BaseItem* Item);  // Used by Shop when the player buys something.

  int getPlayerInventorySize();  // Used to load in a save

  void setPlayerInventorySize(int inventorySize);  // Used to load in a save

  void setInventory(BaseItem** inventory);  // Used to load in a save

  BaseItem** viewInventory() { return Inventory; }  // Used to load in a save

 private:
  BaseItem** Inventory;
  int CurrentInventorySize = 0;
};
#endif