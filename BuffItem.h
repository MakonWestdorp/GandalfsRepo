#ifndef BUFFITEM_H
#define BUFFITEM_H
#include "BaseItem.h"
#include "Entity.h"
class BuffItem : public BaseItem {
 public:
  BuffItem(int NumBossesDefeated);
  void UseItem(Entity* Target);
};
#endif