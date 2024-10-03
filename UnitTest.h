#ifndef UNITTEST_H
#define UNITTEST_H

#include "Entity.h"
#include "Location.h"
#include "Game.h"
#include "BaseItem.h"
#include "Shop.h"

class UnitTest {
 public:
  void StartEntityTests();
  void StartLocationTests();
  void StartShopTests();

 private:
  // Entity class tests
  void EntityTakeDamage();
  void EntityMeleeAttack();
  void EntityMagicAttack();

  // Location class tests
  void LocationTravel();

  // Shop class tests
  void BasicShopTest();

};
#endif