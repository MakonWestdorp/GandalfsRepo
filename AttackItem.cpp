#include "AttackItem.h"

AttackItem::AttackItem(int NumBossesDefeated) {
  DamageOrBuff = DamageOrBuff % NumBossesDefeated + 5 * NumBossesDefeated;
  DamageTypeOrNameOfStat = getRandomElement(damageTypes, damageTypesSize);
}

void AttackItem::UseItem(Entity* Target) {
  Target->takeDamage(DamageOrBuff, DamageTypeOrNameOfStat);
}