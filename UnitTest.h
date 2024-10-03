#ifndef UNITTEST_H
#define UNITTEST_H

#include "Entity.h"
#include "Location.h"
#include "Game.h"
#include "BaseItem.h"
#include "Shop.h"
#include "Town.h"
#include "Forest.h"
#include "Arena.h"

class UnitTest {
 public:
  void StartAllTests();
  void StartEntityTests();
  void StartLocationTests();
  void StartShopTests();
  void StartTownTests();

 private:
  // Entity class tests
  void EntityTakeDamage();
  void EntityMeleeAttack();
  void EntityMagicAttack();

  // Location class tests
  void LocationTravel();

  // Shop class tests
  void BasicShopTest();

  // Town Class tests
  void FirstTownTest(); 

};
#endif