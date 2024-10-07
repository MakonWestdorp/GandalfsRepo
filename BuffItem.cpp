#include "BuffItem.h"

BuffItem::BuffItem(int NumBossesDefeated) {
  DamageOrBuff = DamageOrBuff % 5 * NumBossesDefeated + 5 * NumBossesDefeated;
  DamageTypeOrNameOfStat = getRandomElement(nameOfStats, nameOfStatsSize);
}

void BuffItem::UseItem(Entity* Target) {}
