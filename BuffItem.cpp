#include "BuffItem.h"

BuffItem::BuffItem(int NumBossesDefeated) {
  DamageOrBuff = DamageOrBuff % 5 * NumBossesDefeated + rand() % 5 + 1;
  ChallengeRating = DamageOrBuff;
  DamageTypeOrNameOfStat = getRandomElement(nameOfStats, nameOfStatsSize);
  setIsBool(true);
  name = BuffNameRandomiser();
}

BuffItem::BuffItem(string name, int damageOrBuff, string damageTypeOrNameOfStat,
                   int challengeRating, bool isBuff)
    : BaseItem::BaseItem(name, damageOrBuff, damageTypeOrNameOfStat,
                         challengeRating, isBuff) {}

void BuffItem::UseItem(Entity* Target) { UseItem(Target, "Apply"); }

void BuffItem::UseItem(Entity* Target, string ApplyWithdraw) {
  if (ApplyWithdraw == "Apply") {
    cout << this->getName() << " is applying a buff!" << endl;
    cout << "+" << this->DamageOrBuff << " to " << DamageTypeOrNameOfStat
         << endl;
    Target->ApplyBuff(DamageOrBuff, DamageTypeOrNameOfStat);
  } else if (ApplyWithdraw == "Withdraw") {
    Target->WithdrawBuff(DamageOrBuff, DamageTypeOrNameOfStat);
  }
}

string BuffItem::BuffNameRandomiser() {
  string itemTypes[] = {"Amulet",   "Ring",  "Cloak",
                        "Talisman", "Charm", "Totem"};
  string buffEffects[] = {"Vitality",  "Strength",         "Fortitude",
                          "Wisdom",    "the Phoenix",      "the Tiger",
                          "Endurance", "the Eternal Flame"};
  string BuffItemName =
      itemTypes[rand() % 6] + " of " + buffEffects[rand() % 8];
  return BuffItemName;
};
