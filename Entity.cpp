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
  isAlive = true;
}
// TakeDamage function decreasing the health of the entity by the specified
// damage. Damage is halfed if entity is resistant to the damage type.
void Entity::takeDamage(int Damage, string DamageType) {
  int InputDamage = Damage;
  // If the Target is resistant to the damage type, it will take half the total
  // damage
  if (DamageType == Resistance) {
    InputDamage = InputDamage / 2;
  }
  healthPoints = healthPoints - InputDamage;
  // Check to see if Target is dead.
  if (healthPoints <= 0) {
    isAlive = false;
  }
}
// Triggers the Targets TakeDamage Function, as this is a melee attack it
// deals damage equal to the strength stat, and the damage type is BluntForce.
void Entity::MeleeAttack(Entity* Target) {
  Target->takeDamage(strength, "BluntForce");
}

// Triggers the Targets TakeDamage Function, as this is a magic attack it deals
// damage equal to the magic stat, and the damage type is Magic.
void Entity::MagicAttack(Entity* Target) { Target->takeDamage(magic, "Magic"); }

// If you need a comment to explain a Getter/Setter, please seek help.
int Entity::getHP() { return healthPoints; }

int Entity::getSTR() { return strength; }

int Entity::getDEF() { return defence; }

int Entity::getMAG() { return magic; }

string Entity::getName() { return name; }

string Entity::getRes() { return Resistance; }

void Entity::setHP(int InputHP) { healthPoints = InputHP; }

void Entity::setSTR(int InputSTR) { strength = InputSTR; }

void Entity::setDEF(int InputDEF) { defence = InputDEF; }

void Entity::setMAG(int InputMAG) { magic = InputMAG; }

void Entity::setName(string InputName) { name = InputName; }

void Entity::setRes(string InputName) { Resistance = InputName; }
