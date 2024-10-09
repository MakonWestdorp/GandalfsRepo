#ifndef PLAYER_H
#define PLAYER_H
#include "BaseItem.h"
#include "Entity.h"
class Player : public Entity {
 public:
  Player();  // This constructor should never be called.
  Player(string inputName, int inputHP, int inputSTR, int inputDEF,
         int inputMAG,
         string inputResistance);  // Call this constructor in the class creator
                                   // part of the game
  void TakeTurn();
  void AddItemToInventory(BaseItem Item);

 private:
  BaseItem *Inventory;
  int CurrentInventorySize = 0;
};
#endif