#ifndef UNITTEST_H
#define UNITTEST_H

#include "Arena.h"
#include "BaseItem.h"
#include "Entity.h"
#include "Forest.h"
#include "Game.h"
#include "Location.h"
#include "Shop.h"
#include "Town.h"

class UnitTest {
 public:
  void StartAllTests();
  void StartEntityTests();
  void StartLocationTests();
  void StartShopTests();
  void StartTownTests();
  void StartBaseItemTests();

 private:
  // Entity class tests
  void EntityTakeDamage();
  void EntityAttack();

  // Location class tests
  void LocationTravel();

  // Shop class tests
  void BasicShopTest();

  // Town Class tests
  void FirstTownTest();
  // Base Item tests
  void BaseItemNameGeneratorTest();
};
#endif