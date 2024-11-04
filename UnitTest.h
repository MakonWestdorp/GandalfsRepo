#ifndef UNITTEST_H
#define UNITTEST_H

#include "Arena.h"
#include "AttackItem.h"
#include "BaseItem.h"
#include "BuffItem.h"
#include "Entity.h"
#include "Forest.h"
#include "Game.h"
#include "Location.h"
#include "Player.h"
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
  void StartSaveLoadTests();

 private:
  // Entity class tests
  void EntityTakeDamage();
  void EntityAttack();

  // Location class tests
  void LocationTravel();

  // Shop class tests
  void ShopTest();

  // Town Class tests
  void TownTest();

  // Base Item tests
  void BaseItemNameGeneratorTest();

  // Save & Load tests
  void saveAndLoadTest();
};
#endif