#include "BuffItem.h"

BuffItem::BuffItem(int NumBossesDefeated) {
  DamageOrBuff = DamageOrBuff % NumBossesDefeated + 5 * NumBossesDefeated;
  DamageTypeOrNameOfStat = getRandomElement(nameOfStats, nameOfStatsSize);
}

void BuffItem::UseItem(Entity* Target) {}
