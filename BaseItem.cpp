#include "BaseItem.h"

#include "Entity.h"
#include "Game.h"

void BaseItem::UseItem(Entity* Target) {
  // BaseItem UseItem function does nothing, it gets overloaded by inherited
  // classes
}

BaseItem::BaseItem() {
  ChallengeRating = 0;
  DamageOrBuff = (rand() % 5) + 1;
  name = nameRandomiser();
  IsBuff = false;
}
BaseItem::BaseItem(int NumBossesDefeated) {
  IsBuff = false;
  ChallengeRating = NumBossesDefeated;
  DamageOrBuff = (rand() % 5) + 1 + 5 * NumBossesDefeated;
  name = nameRandomiser();
}

BaseItem::BaseItem(string name, int damageOrBuff, string damageTypeOrNameOfStat, int challengeRating, bool isBuff) {
  this->name = name;
  this->DamageOrBuff = damageOrBuff;
  this->DamageTypeOrNameOfStat = damageTypeOrNameOfStat;
  this->ChallengeRating = challengeRating;
  this->IsBuff = isBuff;
}

string BaseItem::getName() { return name; }

int BaseItem::getDamageOrBuff() { return DamageOrBuff; }

string BaseItem::getDamageOrNameStat() { return DamageTypeOrNameOfStat; }

int BaseItem::GetChallengeRating() { return ChallengeRating; }

bool BaseItem::getIsBuff() { return IsBuff; }

void BaseItem::setName(string name) { this->name = name;}

void BaseItem::setDamageOrBuff(int damageOrBuff) {this->DamageOrBuff = damageOrBuff; }

void BaseItem::setSetDamageTypeOrNameOfStat(string damageTypeOrNameOfStat) { this->DamageTypeOrNameOfStat = damageTypeOrNameOfStat; }

void BaseItem::setChallengRating(int challengeRating) {this->ChallengeRating = challengeRating; }

void BaseItem::setIsBool(bool isBuff) {this->IsBuff = isBuff; }

string BaseItem::nameRandomiser() {
  // 1% chance for a rare prefix
  bool isRare = (rand() % 100) < 1;

  // Array of rare prefixes
  const std::string rarePrefixes[] = {"Ancient", "Great", "Legendary",
                                      "Mythic"};
  int rarePrefixesSize = sizeof(rarePrefixes) / sizeof(rarePrefixes[0]);

  // Array of weapon types
  const std::string weapons[] = {"Katana", "Nunchucks", "Sword", "Bow",
                                 "Axe",    "Dagger",    "Staff"};
  int weaponsSize = sizeof(weapons) / sizeof(weapons[0]);

  // Array of adjectives
  const std::string adjectives[] = {"Doom",       "Fury",    "the Phoenix",
                                    "Vengeance",  "Thunder", "the Dragon",
                                    "Destruction"};
  int adjectivesSize = sizeof(adjectives) / sizeof(adjectives[0]);

  // Generate the weapon name
  std::string weapon = getRandomElement(weapons, weaponsSize);

  // Generate the adjective
  std::string adjective = getRandomElement(adjectives, adjectivesSize);

  // Construct the final item name
  std::string itemName;
  if (isRare) {
    itemName = getRandomElement(rarePrefixes, rarePrefixesSize) + " " + weapon +
               " of " + adjective;
  } else {
    itemName = weapon + " of " + adjective;
  }

  return itemName;
}

string BaseItem::getRandomElement(const string elements[], int size) {
  return elements[rand() % size];
}
