#include "BuffItem.h"

BuffItem::BuffItem(int NumBossesDefeated) {
  ChallengeRating = NumBossesDefeated;
  DamageOrBuff = DamageOrBuff % 5 * NumBossesDefeated + 5 * NumBossesDefeated;
  DamageTypeOrNameOfStat = getRandomElement(nameOfStats, nameOfStatsSize);
  IsBuff = true;
}

void BuffItem::UseItem(Entity* Target) { UseItem(Target, "Apply"); }

void BuffItem::UseItem(Entity* Target, string ApplyWithdraw) {
  if (ApplyWithdraw == "Apply") {
    Target->ApplyBuff(DamageOrBuff, DamageTypeOrNameOfStat);
  } else if (ApplyWithdraw == "Withdraw") {
    Target->WithdrawBuff(DamageOrBuff, DamageTypeOrNameOfStat);
  }
  cout << "called\n";
}
