#include "Enemy.h"

#include <chrono>
#include <thread>

#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"

using namespace chrono;
using namespace this_thread;

Enemy::Enemy() {
  healthPoints = 0;
  strength = 0;
  defence = 0;
  magic = 0;
  isAlive = false;
  name = "No Name";
  ChallengeRating = 0;
}
Enemy::Enemy(int NumBossesDeafeated) {
  healthPoints = NumBossesDeafeated * 5 + rand() % 10 + 5;
  strength = NumBossesDeafeated * 5 + 5;
  defence = NumBossesDeafeated * 5 + 5;
  magic = NumBossesDeafeated * 5 + 5;
  string damageTypes[4] = {"Magic", "Piercing", "Bludgeoning", "Slashing"};
  int damageTypesSize = sizeof(damageTypes) / sizeof(damageTypes[0]);
  Resistance = damageTypes[rand() % damageTypesSize];
  isAlive = true;
  name = RandomEnemyName();
  ChallengeRating = healthPoints + strength + defence + magic;
  ChallengeRating = ChallengeRating / 4;
}

string Enemy::RandomEnemyName() {
  // Randomly choose a prefix, suffix, and type
  string prefix = prefixes[rand() % 10];
  string suffix = suffixes[rand() % 10];
  string type = types[rand() % 10];

  // Combine them to form a name
  return prefix + " " + type + " of the " + suffix;
}
int Enemy::getChallengeRating() { return ChallengeRating; }

string Enemy::getName() { return name; }

void Enemy::TakeTurn(Entity* Target, int CurrentRound) {
  if (rand() % 2 < 1) {
    Attack(Target);
    cout << "Enemy is punching you!" << endl;
  } else {
    Inventory->UseItem(Target);
    cout << "Enemy is using its " << Inventory->getName() << " to attack you!"
         << endl;
  }
  sleep_for(seconds(1));
}
