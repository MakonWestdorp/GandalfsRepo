#ifndef PLAYER_H
#define PLAYER_H
#include "BaseItem.h"
#include "Enemy.h"
#include "Entity.h"
class Player : public Entity {
 public:
  Player();  // This constructor should never be called.
  Player(string inputName, int inputHP, int inputSTR, int inputDEF,
         int inputMAG,
         string inputResistance);  // Call this constructor in the class creator
                                   // part of the game
  int TakeTurn(Enemy* Target, int CurrentRound, bool& KeepFighting);
  void AddItemToInventory(BaseItem* Item);
  int getPlayerInventorySize();
  void setPlayerInventorySize(int inventorySize);
  void setInventory(BaseItem **inventory);
  BaseItem **viewInventory() {return Inventory; }

 private:
  BaseItem** Inventory;
  int CurrentInventorySize = 0;
};
#endif