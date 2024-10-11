#include "AttackItem.h"

AttackItem::AttackItem(int NumBossesDefeated) {
  // Constructor for Attack Item. Challenge Rating used to determin price in
  // store,DamageOrBuff is how much damage the Item Deals.DamageTypeOrStat
  // determines what damage type the weapon deals:Used in damage recieving
  // calculations. Attack Item is not a Buff item, so isBuff is false.
  ChallengeRating = NumBossesDefeated;
  DamageOrBuff = 5 * NumBossesDefeated + 5;
  DamageTypeOrNameOfStat = damageTypes[rand() % 4];
  IsBuff = false;
}

// Because this is a Attack Item, all it will do is call the targets TakeDamage
// function, dealing DamageOrBuff units of damage.Function also passes
// DamageTypeOrNameOfStat to see if Target is resistant to said damage type.
void AttackItem::UseItem(Entity* Target) {
  Target->takeDamage(DamageOrBuff, DamageTypeOrNameOfStat);
}
