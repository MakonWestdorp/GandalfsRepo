#ifndef ENEMY_H
#define ENEMY_H
#include "AttackItem.h"
#include "Entity.h"
class Enemy : public Entity {
 public:
  Enemy();
  Enemy(int NumBossesDeafeated);
  string getName();
  int getChallengeRating();
  void TakeTurn(Entity* Target, int CurrentRound);
  ~Enemy() {};

 protected:
  const string prefixes[10] = {"Dark",  "Flame",  "Shadow", "Frost", "Venom",
                               "Steel", "Cursed", "Wild",   "Blood", "Ghost"};
  const string suffixes[10] = {"Fang",    "Claw",   "Gaze",    "Blade",
                               "Wing",    "Spirit", "Stalker", "Reaper",
                               "Bringer", "Warden"};
  const string types[10] = {"Dragon",  "Wraith", "Goblin", "Orc",     "Beast",
                            "Serpent", "Knight", "Golem",  "Specter", "Troll"};
  int CurrentNumBossesDefeated = 1;
  int ChallengeRating;
  string RandomEnemyName();
  AttackItem EnemyAttackItem;
  BaseItem* Inventory = &EnemyAttackItem;
};
#endif