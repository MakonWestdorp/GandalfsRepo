#include "BuffItem.h"

BuffItem::BuffItem(int NumBossesDefeated) {
  DamageOrBuff = DamageOrBuff % 5 * NumBossesDefeated + 5 * NumBossesDefeated;
  ChallengeRating = DamageOrBuff;
  DamageTypeOrNameOfStat = getRandomElement(nameOfStats, nameOfStatsSize);
  IsBuff = true;
}

BuffItem::BuffItem(string name, int damageOrBuff, string damageTypeOrNameOfStat, int challengeRating, bool isBuff) 
: BaseItem::BaseItem(name,damageOrBuff,damageTypeOrNameOfStat,challengeRating,isBuff) {}


void BuffItem::UseItem(Entity* Target) { UseItem(Target, "Apply"); }

void BuffItem::UseItem(Entity* Target, string ApplyWithdraw) {
  if (ApplyWithdraw == "Apply") {
    Target->ApplyBuff(DamageOrBuff, DamageTypeOrNameOfStat);
  } else if (ApplyWithdraw == "Withdraw") {
    Target->WithdrawBuff(DamageOrBuff, DamageTypeOrNameOfStat);
  }
  cout << "called\n";
}
