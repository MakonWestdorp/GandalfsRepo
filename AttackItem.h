#ifndef ATTACKITEM_H
#define ATTACKITEM_H
#include "BaseItem.h"
#include "Entity.h"
class AttackItem : public BaseItem {
 public:
  AttackItem(int NumBossesDefeated);
  void UseItem(Entity* Target);
};

#endif