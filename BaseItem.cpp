#include "BaseItem.h"

BaseItem::BaseItem() { name = nameRandomiser(); }

BaseItem::BaseItem(string inputName) { name = inputName; }

string BaseItem::getName() { return name; }

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
