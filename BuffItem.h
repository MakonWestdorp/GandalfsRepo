#ifndef BUFFITEM_H
#define BUFFITEM_H
#include "BaseItem.h"
#include "Entity.h"
class BuffItem : public BaseItem {
 public:
  using BaseItem::UseItem;
  BuffItem(int NumBossesDefeated);
  void UseItem(Entity* Target, string ApplyWithdraw);
  bool IsBuff = true;
};
#endif