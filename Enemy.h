#ifndef ENEMY_H
#define ENEMY_H
#include "BaseItem.h"
#include "Entity.h"
class Enemy : public Entity {
 public:
  void takeDamage(int Damage, string DamageType);
  void MeleeAttack(Entity* Target);
  void MagicAttack(Entity* Target);

 private:
  BaseItem RandomItemForEnemy();
  BaseItem Inventory = RandomItemForEnemy();
};
#endif