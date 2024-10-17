#include "Boss.h"

#include <iostream>
void Boss::TakeTurn(Entity* Target, int CurrentRound) {
  if (CurrentRound % 4 == 0 && CurrentRound != 1) {
    cout << "Boss is healing itself!" << endl;
    healthPoints += 5;
  }
  cout << "Boss is using " << BossAttackItem.getName() << " to attack you!"
       << endl;
  BossAttackItem.UseItem(Target);
  cout << "Boss is using " << BossBuffItem.getName() << " to buff itself"
       << endl;
  BossBuffItem.UseItem(this);
}

Boss::Boss(int NumBossesDefeated) {
  BuffItem BossBuffItem = BuffItem(NumBossesDeafeated);
  AttackItem BossAttackItem = AttackItem(NumBossesDeafeated);
  healthPoints = 10 + rand() % 10;
  strength = 10 + rand() % 10;
  defence = 10 + rand() % 10;
  magic = 10 + rand() % 10;
  isAlive = true;
  name = "Boss: " + RandomEnemyName();
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;
  Resistance = "Magic";
}
