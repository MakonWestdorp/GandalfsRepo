#include "Entity.h"

Entity::Entity() {}

Entity::Entity(string Name, int HP, int STR, int DEF, int MAG,
               string Resistance) {}

void Entity::takeDamage(int Damage, string DamageType) {}

void Entity::MeleeAttack(Entity* Target) {}

void Entity::MagicAttack(Entity* Target) {}
