#ifndef ATTACKITEM_H
#define ATTACKITEM_H
#include "BaseItem.h"
#include "Entity.h"

class AttackItem : public BaseItem {
 public:
  ~AttackItem() {};
  AttackItem() : BaseItem() {}
  AttackItem(int numBossesDefeated);
  AttackItem(string name, int damageOrBuff, string damageTypeOrNameOfStat,
             int challengeRating, bool isBuff);
  void UseItem(Entity* Target) override;
  bool IsBuff = false;
};

#endif