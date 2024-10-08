#include "Enemy.h"

#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"
Enemy::Enemy(int NumBossesDeafeated) {
  healthPoints = NumBossesDeafeated * 5 + 5;
  strength = NumBossesDeafeated * 5 + 5;
  defence = NumBossesDeafeated * 5 + 5;
  magic = NumBossesDeafeated * 5 + 5;
  isAlive = true;
  srand(time(0));
  name = RandomEnemyName();
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;
}
string Enemy::getName() { return name; }
string Enemy::RandomEnemyName() {
  // Randomly choose a prefix, suffix, and type
  string prefix = prefixes[rand() % 10];
  string suffix = suffixes[rand() % 10];
  string type = types[rand() % 10];

  // Combine them to form a name
  return prefix + " " + type + " of the " + suffix;
}
int Enemy::getChallengeRating() { return ChallengeRating; }
BaseItem Enemy::RandomItemForEnemy(int NumBossesDeafeated) {
  BaseItem RandomItem;
  if (rand() % 2 < 1) {
    RandomItem = AttackItem(NumBossesDeafeated);
  } else {
    RandomItem = BuffItem(NumBossesDeafeated);
  };
  return RandomItem;
}
