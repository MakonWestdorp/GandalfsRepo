#ifndef BASEITEM_H
#define BASEITEM_H

#include <iostream>
#include <string>

using namespace std;

class BaseItem {
 private:
  string name;
  int DamageOrBuff;
  string DamageTypeOrNameOfStat;

  string damageTypes[4] = {"Magic", "Piercing", "Bludgeoning", "Slashing"};
  int damageTypesSize = sizeof(damageTypes) / sizeof(damageTypes[0]);
  string nameOfStats[4] = {"HP", "STR", "DEF", "MAG"};
  int nameOfStatsSize = sizeof(nameOfStats) / sizeof(nameOfStats[0]);

 public:
  BaseItem(Game &game);     // Defeault Constructor
  string getName();         // Returns name
  string nameRandomiser();  // Generates a random name for the item.
  string getRandomElement(const string elements[],
                          int size);  // Used inside nameRandomiser
};

#endif