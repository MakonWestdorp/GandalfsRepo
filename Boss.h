#ifndef BOSS_H
#define BOSS_H
#include "AttackItem.h"
#include "BuffItem.h"
#include "Enemy.h"
class Boss : public Enemy {
 public:
  void TakeTurn(Entity* Target, int CurrentRound);
  Boss();
  Boss(int NumBossesDefeated);
  ~Boss() {};

 private:
  BaseItem** Inventory = new BaseItem*[2];
  BuffItem BossBuffItem;
  AttackItem BossAttackItem;
};
#endif