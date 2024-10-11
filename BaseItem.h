#ifndef BASEITEM_H
#define BASEITEM_H

#include <iostream>
#include <string>

using namespace std;

class Game;
class Entity;

class BaseItem {
 protected:
  string name;
  int DamageOrBuff;
  string DamageTypeOrNameOfStat;
  int ChallengeRating;
  string damageTypes[4] = {"Magic", "Piercing", "Bludgeoning", "Slashing"};
  int damageTypesSize = sizeof(damageTypes) / sizeof(damageTypes[0]);
  string nameOfStats[4] = {"HP", "STR", "DEF", "MAG"};
  int nameOfStatsSize = sizeof(nameOfStats) / sizeof(nameOfStats[0]);

 public:
  int GetChallengeRating();
  virtual void UseItem(Entity* Target) = 0;
  BaseItem();
  BaseItem(int NumBossesDefeated);  // Defeault Constructor
  string getName();                 // Returns name
  string nameRandomiser();          // Generates a random name for the item.
  string getRandomElement(const string elements[],
                          int size);  // Used inside nameRandomiser
  bool IsBuff;
};

#endif