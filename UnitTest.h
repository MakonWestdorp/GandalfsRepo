#ifndef UNITTEST_H
#define UNITTEST_H
#include "Entity.h"
class UnitTest {
 public:
  void StartTests();

 private:
  void EntityTakeDamage();
  void EntityMeleeAttack();
  void EntityMagicAttack();
};
#endif