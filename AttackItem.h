#ifndef ATTACKITEM_H
#define ATTACKITEM_H
#include "BaseItem.h"
#include "Entity.h"

class AttackItem : public BaseItem {
 public:
  AttackItem() : BaseItem() {}
  AttackItem(int NumBossesDefeated);
  void UseItem(Entity* Target) override;
  bool IsBuff = false;
};

#endif