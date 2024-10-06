#include "Enemy.h"

void Enemy::takeDamage(int Damage, string DamageType) {}

void Enemy::MeleeAttack(Entity* Target) {}

void Enemy::MagicAttack(Entity* Target) {}

BaseItem Enemy::RandomItemForEnemy() {
  BaseItem RandomItem();
  if (rand() % 2 < 1) {
    RandomItem;  // Whatever a buff item ends up being
  } else {
    RandomItem;  // Handheld Item
  };
  return RandomItem;
}
