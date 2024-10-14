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

 private:
  BuffItem BossBuffItem;
  AttackItem BossAttackItem;
  BaseItem* Inventory[2];
};
#endif