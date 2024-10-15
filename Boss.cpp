#include "Boss.h"

#include <iostream>
void Boss::TakeTurn(Entity* Target, int CurrentRound) {
  if (CurrentRound % 4 == 0) {
    cout << "Boss is healing itself!" << endl;
    healthPoints += 20;
  }
  cout << "Boss is using " << Inventory[1]->getName() << " to attack you!"
       << endl;
  Inventory[1]->UseItem(Target);
  cout << "Boss is using " << Inventory[0]->getName() << " to buff itself"
       << endl;
  Inventory[0]->UseItem(this);
}

Boss::Boss(int NumBossesDefeated) {
  BossAttackItem = AttackItem(NumBossesDefeated);
  BossBuffItem = BuffItem(NumBossesDefeated);
  Inventory[0] = &BossBuffItem;
  Inventory[1] = &BossAttackItem;
  healthPoints = 20;
  strength = 20;
  defence = 20;
  magic = 20;
  isAlive = true;
  name = "Boss: " + RandomEnemyName();
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;
  Resistance = "Magic";
}
