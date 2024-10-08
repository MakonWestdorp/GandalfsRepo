#include "Enemy.h"

#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"
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
  srand(time(0));
  string prefix = prefixes[rand() % 10];
  string suffix = suffixes[rand() % 10];
  string type = types[rand() % 10];

  // Combine them to form a name
  return prefix + " " + type + " of the " + suffix;
}
int Enemy::getChallengeRating() { return ChallengeRating; }
void Enemy::TakeTurn(Entity* Target, int CurrentRound, int roundBuffUsed) {
  BaseItem* InventoryPTR = &Inventory;
  BuffItem* buffItem = dynamic_cast<BuffItem*>(InventoryPTR);
  bool BuffItemUsed = false;
  if (BuffItemUsed) {
    if (roundBuffUsed == CurrentRound - 1) {
      buffItem->UseItem(this, "Withdraw");
      BuffItemUsed = false;
    }
  }
  srand(time(0));
  if (rand() % 2 < 1) {
    Attack(Target);
  } else {
    if (buffItem) {
      buffItem->UseItem(this, "Apply");
    } else {
      Inventory.UseItem(Target);
    }
  }
}
BaseItem Enemy::RandomItemForEnemy(int NumBossesDeafeated) {
  BaseItem RandomItem;
  srand(time(0));
  if (rand() % 2 < 1) {
    RandomItem = AttackItem(NumBossesDeafeated);
  } else {
    RandomItem = BuffItem(NumBossesDeafeated);
  };
  return RandomItem;
}
