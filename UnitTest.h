#ifndef UNITTEST_H
#define UNITTEST_H

#include "Entity.h"
#include "Location.h"
#include "Game.h"

class UnitTest {
 public:
  void StartTests();

 private:
  // Entity class tests
  void EntityTakeDamage();
  void EntityMeleeAttack();
  void EntityMagicAttack();

  // Location class tests
  void LocationTravel();

};
#endif