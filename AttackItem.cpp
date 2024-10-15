#include "AttackItem.h"

AttackItem::AttackItem(int numBossesDefeated) {
  // Constructor for Attack Item. Challenge Rating used to determin price in
  // store,DamageOrBuff is how much damage the Item Deals.DamageTypeOrStat
  // determines what damage type the weapon deals:Used in damage recieving
  // calculations. Attack Item is not a Buff item, so isBuff is false.
  DamageOrBuff = 5 * numBossesDefeated + 5;
  ChallengeRating = DamageOrBuff;
  DamageTypeOrNameOfStat = damageTypes[rand() % 4];
  setIsBool(false);
}

AttackItem::AttackItem(string name, int damageOrBuff,
                       string damageTypeOrNameOfStat, int challengeRating,
                       bool isBuff)
    : BaseItem::BaseItem(name, damageOrBuff, damageTypeOrNameOfStat,
                         challengeRating, isBuff) {}

// Because this is a Attack Item, all it will do is call the targets TakeDamage
// function, dealing DamageOrBuff units of damage.Function also passes
// DamageTypeOrNameOfStat to see if Target is resistant to said damage type.
void AttackItem::UseItem(Entity* Target) {
  Target->takeDamage(DamageOrBuff, DamageTypeOrNameOfStat);
}
