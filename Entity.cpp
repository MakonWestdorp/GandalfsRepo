#include "Entity.h"
// Default uses randomized stats based upon #bosses defeated.
Entity::Entity() {}
// Specific Constructor used for Player Class
Entity::Entity(string InputName, int InputHP, int InputSTR, int InputDEF,
               int InputMAG, string InputResistance) {
  name = InputName;
  healthPoints = InputHP;
  defence = InputDEF;
  strength = InputSTR;
  magic = InputMAG;
  Resistance = InputResistance;
}

void Entity::takeDamage(int Damage, string DamageType) {
  int InputDamage = Damage;
  if (DamageType == Resistance) {
    InputDamage = InputDamage / 2;
  }
  healthPoints = healthPoints - InputDamage;
  if (healthPoints <= 0) {
    isAlive = false;
  }
}

void Entity::MeleeAttack(Entity* Target) {
  Target->takeDamage(strength, "BluntForce");
}

void Entity::MagicAttack(Entity* Target) { Target->takeDamage(magic, "Magic"); }
