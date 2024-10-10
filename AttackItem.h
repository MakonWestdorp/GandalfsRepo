#ifndef ATTACKITEM_H
#define ATTACKITEM_H
#include "BaseItem.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

class AttackItem : public BaseItem {
 public:
  AttackItem() : BaseItem() {}
  AttackItem(int NumBossesDefeated);
  void UseItem(Player *Player, Entity* Target);
  bool IsBuff = false;
};

#endif