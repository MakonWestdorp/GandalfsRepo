#include "Enemy.h"

#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"
void Enemy::takeDamage(int Damage, string DamageType) {}

void Enemy::MeleeAttack(Entity* Target) {}

void Enemy::MagicAttack(Entity* Target) {}

BaseItem Enemy::RandomItemForEnemy(int NumBossesDeafeated) {
  BaseItem RandomItem;
  if (rand() % 2 < 1) {
    RandomItem =
        AttackItem(NumBossesDeafeated);  // Whatever a buff item ends up being
  } else {
    RandomItem = BuffItem(NumBossesDeafeated);  // Handheld Item
  };
  return RandomItem;
}
