#include "AttackItem.h"

AttackItem::AttackItem(int NumBossesDefeated) {
  ChallengeRating = NumBossesDefeated;
  DamageOrBuff = DamageOrBuff % NumBossesDefeated + 5 * NumBossesDefeated;
  DamageTypeOrNameOfStat = getRandomElement(damageTypes, damageTypesSize);
  IsBuff = false;
}

void AttackItem::UseItem(Entity* Target) {
  Target->takeDamage(DamageOrBuff, DamageTypeOrNameOfStat);
}