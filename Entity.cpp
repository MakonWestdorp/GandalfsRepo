#include "Entity.h"
// Default uses randomized stats based upon #bosses defeated.
Entity::Entity() {}
Entity::Entity(string inputName, int NumBossesDefeated) {
  name = inputName;
  healthPoints = NumBossesDeafeated * 5 + 5;
  strength = NumBossesDeafeated * 5 + 5;
  defence = NumBossesDeafeated * 5 + 5;
  magic = NumBossesDeafeated * 5 + 5;
  isAlive = true;
  string damageTypes[4] = {"Magic", "Piercing", "Bludgeoning", "Slashing"};
  int damageTypesSize = sizeof(damageTypes) / sizeof(damageTypes[0]);
  Resistance = damageTypes[rand() % damageTypesSize];
}
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

void Entity::Attack(Entity* Target) {
  Target->takeDamage(rand() % (strength), "Bludgeoning");
}

void Entity::takeTurn(Entity* Target) { Attack(Target); }

bool Entity::GetIsAlive() { return isAlive; }

int Entity::getCashOnHand() { return CashOnHand; }

void Entity::setCashOnHand(int inputCashOnHand) {
  CashOnHand = inputCashOnHand;
}

void Entity::Attack(Entity* Target, string TypeOfAttack, string StatUsed,
                    int DamageBuff) {
  if (StatUsed == "STR") {
    Target->takeDamage(strength + DamageBuff, TypeOfAttack);
  } else if (StatUsed == "MAG") {
    Target->takeDamage(magic + DamageBuff, TypeOfAttack);
  }
}

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
