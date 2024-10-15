#include "Entity.h"

#include <iostream>
// Default uses randomized stats based upon #bosses defeated.
Entity::Entity() {}
Entity::Entity(string inputName, int InputNumBossesDefeated) {
  name = inputName;
  NumBossesDeafeated = InputNumBossesDefeated;
  healthPoints = (InputNumBossesDefeated * 5) + 5;
  strength = InputNumBossesDefeated * 5 + 5;
  defence = InputNumBossesDefeated * 5 + 5;
  magic = InputNumBossesDefeated * 5 + 5;
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
  // If the Target is resistant to the damage type, it will take half the total
  // damage
  if (DamageType == Resistance) {
    Damage = Damage / 2;
    cout << this->getName() << " is resistant to " << Resistance << " damage!"
         << endl;
  }
  int DefenceChange = rand() % (defence / 2) + defence / 4;
  Damage -= DefenceChange;
  this->healthPoints = healthPoints - Damage;
  // Check to see if Target is dead.
  if (healthPoints <= 0) {
    this->isAlive = false;
  }
}

void Entity::Attack(Entity* Target) {
  Target->takeDamage((rand() % (strength)) + 1, "Bludgeoning");
}

void Entity::Attack(Entity* Target, int damage, string damageType) {
  Target->takeDamage(damage, damageType);
}

void Entity::takeTurn(Entity* Target) { Attack(Target); }

bool Entity::GetIsAlive() { return isAlive; }

int Entity::getCashOnHand() { return CashOnHand; }

void Entity::setCashOnHand(int inputCashOnHand) {
  CashOnHand = inputCashOnHand;
}

void Entity::ApplyBuff(int Buff, string Stat) {
  if (Stat == "HP") {
    healthPoints = getHP() + Buff;
  } else if (Stat == "STR") {
    strength = getSTR() + Buff;
  } else if (Stat == "DEF") {
    defence = getDEF() + Buff;
  } else if (Stat == "MAG") {
    magic = getMAG() + Buff;
  }
}

void Entity::WithdrawBuff(int Buff, string Stat) {
  if (Stat == "HP") {
    healthPoints = getHP();
  } else if (Stat == "STR") {
    strength = getSTR() - Buff;
  } else if (Stat == "DEF") {
    defence = getDEF() - Buff;
  } else if (Stat == "MAG") {
    magic = getMAG() - Buff;
  }
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
int Entity::getChallengeRating() { return ChallengeRating; }

int Entity::getHP() { return healthPoints; }

int Entity::getSTR() { return strength; }

int Entity::getDEF() { return defence; }

int Entity::getMAG() { return magic; }

string Entity::getName() { return name; }

string Entity::getRes() { return Resistance; }

void Entity::setChallengeRating(int InputChallengeRating) {
  ChallengeRating = InputChallengeRating;
}

void Entity::setHP(int InputHP) { healthPoints = InputHP; }

void Entity::setSTR(int InputSTR) { strength = InputSTR; }

void Entity::setDEF(int InputDEF) { defence = InputDEF; }

void Entity::setMAG(int InputMAG) { magic = InputMAG; }

void Entity::setName(string InputName) { name = InputName; }

void Entity::setRes(string InputName) { Resistance = InputName; }
