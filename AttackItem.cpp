#include "AttackItem.h"

AttackItem::AttackItem(int NumBossesDefeated) {
  ChallengeRating = NumBossesDefeated;
  DamageOrBuff = 5;
  // DamageOrBuff = DamageOrBuff % NumBossesDefeated + 5 * NumBossesDefeated;
  // DamageTypeOrNameOfStat = getRandomElement(damageTypes, damageTypesSize);
  DamageTypeOrNameOfStat = "Blugeoning";
  IsBuff = false;
}

void AttackItem::UseItem(Entity* Target) {
  Target->takeDamage(DamageOrBuff, DamageTypeOrNameOfStat);
}
