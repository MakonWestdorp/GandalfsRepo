#include "BaseItem.h"

#include "Entity.h"
#include "Game.h"

void BaseItem::UseItem(Entity* Target) {
  // BaseItem UseItem function does nothing, it gets overloaded by inherited
  // classes
}

BaseItem::BaseItem() {
  DamageOrBuff = rand();
  name = nameRandomiser();
}
BaseItem::BaseItem(int NumBossesDefeated) {
  srand(time(0));
  DamageOrBuff = (rand() % 5 * NumBossesDefeated) + 5 * NumBossesDefeated;
  name = nameRandomiser();
}

string BaseItem::getName() { return name; }

string BaseItem::nameRandomiser() {
  // 1% chance for a rare prefix
  srand(time(0));
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
  srand(time(0));
  return elements[rand() % size];
}
