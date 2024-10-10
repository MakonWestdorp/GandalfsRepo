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
  string damageTypes[4] = {"Magic", "Piercing", "Bludgeoning", "Slashing"};
  int damageTypesSize = sizeof(damageTypes) / sizeof(damageTypes[0]);
  //Resistance = damageTypes[rand() % damageTypesSize];
  Resistance = "Magic";
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
  BaseItem* InventoryPTR = &Inventory;
  BuffItem* buffItem = dynamic_cast<BuffItem*>(InventoryPTR);
  bool BuffItemUsed = false;
  if (BuffItemUsed) {
    if (RoundBuffUsed == CurrentRound - 1) {
      buffItem->UseItem(this, "Withdraw");
      BuffItemUsed = false;
    }
  }
  if (rand() % 2 < 1) {
    Attack(Target);
    cout << "Enemy is Attacking Player!" << endl;
  } else {
    if (buffItem) {
      cout << "Enemy is using a BuffItem!" << endl;
      buffItem->UseItem(this, "Apply");
    } else {
      cout << "Enemy is attacking using its item!" << endl;
      Inventory.UseItem(Target);
    }
  }
}
int Enemy::getRoundBuffUsed() { return RoundBuffUsed; }
BaseItem Enemy::RandomItemForEnemy(int NumBossesDeafeated) {
  BaseItem RandomItem;
  if (rand() % 2 < 1) {
    RandomItem = AttackItem(NumBossesDeafeated);
  } else {
    RandomItem = BuffItem(NumBossesDeafeated);
  };
  return RandomItem;
}
