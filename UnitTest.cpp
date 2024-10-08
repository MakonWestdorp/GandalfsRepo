#include "UnitTest.h"

#include <iostream>
using namespace std;
void UnitTest::StartAllTests() {
  void StartEntityTests();
  void StartLocationTests();
  void StartShopTests();
}
// Start tests
void UnitTest::StartEntityTests() {
  EntityTakeDamage();
  EntityAttack();
}

void UnitTest::StartLocationTests() { LocationTravel(); }

void UnitTest::StartShopTests() { BasicShopTest(); }

void UnitTest::StartTownTests() { FirstTownTest(); }

void UnitTest::StartBaseItemTests() { BaseItemNameGeneratorTest(); }

// Entity test functions
void UnitTest::EntityTakeDamage() {
  Entity Gandalf = Entity("Gandalf", 15, 4, 7, 35, "Magic");
  Gandalf.takeDamage(2, "Magic");
  if (Gandalf.getHP() != 14) {
    cout << "EntityTakeDamage Resistance Check Failed" << endl;
  } else {
    cout << "EntityTakeDamage Resistance Check Succeeded" << endl;
  };
  Gandalf.setHP(15);
  Gandalf.takeDamage(4, "BluntForce");
  if (Gandalf.getHP() != 11) {
    cout << "EntityTakeDamage Non-Resistance Check Failed" << endl;
  } else {
    cout << "EntityTakeDamage Non-Resistance Check Succeeded" << endl;
  };
  Gandalf.setHP(15);
  Gandalf.takeDamage(0, "BluntForce");
  if (Gandalf.getHP() != 15) {
    cout << "EntityTakeDamage No Damage Check Failed" << endl;
  } else {
    cout << "EntityTakeDamage No Damage Check Succeeded" << endl;
  };
}

void UnitTest::EntityAttack() {
  Entity Gandalf = Entity("Gandalf", 4);
  Entity Sauron = Entity("Sauron", 3);
  Entity *PtrToGandalf = &Gandalf;
  Entity *PtrToSauron = &Sauron;
  string GandalfsResistance = Gandalf.getRes();
  string SauronsResistance = Sauron.getRes();
  cout << "Sauron has " << Sauron.getHP() << "health points" << endl;
  Gandalf.Attack(PtrToSauron, SauronsResistance, "MAG", 0);
  cout << "Gandalf has attacked Sauron" << endl;
  cout << "Sauron now has" << Sauron.getHP() << "health points" << endl;
}

// Location test functions
void UnitTest::LocationTravel() {
  // Descriptions
  string forestDescription =
      "In a dark, mist-shrouded forest teeming with fearsome monsters, \n "
      "hidden treasures glimmer among ancient ruins, luring the brave and "
      "foolish alike.";
  string townDescription =
      "The medieval town bustles with life, its cobblestone streets \n winding "
      "past stone shops beneath the shadow of a towering castle";

  // Create locations
  Location *Forest = new Location("Forest", forestDescription, "");
  Location *Town = new Location("Town", townDescription, "");

  // Create temporary game
  Game LocationTest;

  int cashOnHand = 0;  // Needed to call function

  /*
    Runs a short test that
    - Outputs current locations name
    - Shows the Forest
    - Travels to the Town
    - Shows the town
    - Output current locations mae
  */
  LocationTest.setCurrentLocation(Forest);
  cout << LocationTest.viewCurrentLocation()->getName() << endl;
  LocationTest.viewCurrentLocation()->showLocation(LocationTest, cashOnHand);
  LocationTest.viewCurrentLocation()->travelToLocation(LocationTest, Town);
  cout << LocationTest.viewCurrentLocation()->getName() << endl;
  LocationTest.viewCurrentLocation()->showLocation(LocationTest, cashOnHand);
}

void UnitTest::BasicShopTest() {
  // Create inventory
  int numBossesDefeated = 1;

  int *prices = new int[5];
  prices[0] = 10;
  prices[1] = 5;
  prices[2] = 100;
  prices[3] = 30;
  prices[4] = 60;

  bool *forSaleStatus = new bool[5];
  forSaleStatus[0] = true;
  forSaleStatus[1] = true;
  forSaleStatus[2] = true;
  forSaleStatus[3] = true;
  forSaleStatus[4] = true;

  // Create shop
  string shopDescription =
      "Steel & Sorcery offers finely crafted blades, \nfrom master-forged "
      "steel to rare enchanted swords";
  Shop WeaponsShop(numBossesDefeated, prices, forSaleStatus, "Steel & Sorcery",
                   "Timmy", shopDescription, "");

  // Test shop interface
  int cashOnHand = 50;
  while (WeaponsShop.showShopInterface(cashOnHand) == true) {
  }

  // Create new inventory
  prices[0] = 20;
  prices[1] = 2;
  prices[2] = 200;
  prices[3] = 60;
  prices[4] = 120;

  forSaleStatus[0] = true;
  forSaleStatus[1] = true;
  forSaleStatus[2] = true;
  forSaleStatus[3] = true;
  forSaleStatus[4] = true;

  WeaponsShop.updateShop(numBossesDefeated, prices, forSaleStatus);

  // Test shop interface
  while (WeaponsShop.showShopInterface(cashOnHand) == true) {
  }
}

void UnitTest::FirstTownTest() {
  Game game;
  int cashOnHand = 50;
  game.initialiseLocations();
  game.initialiseShops();
  game.setCurrentLocation(game.viewLocations()[0]);

  while (game.isGameRunning() == true) {
    game.viewCurrentLocation()->showLocation(game, cashOnHand);
  }
}

void UnitTest::BaseItemNameGeneratorTest() {
  int numBossesDefeated = 1;
  BaseItem Item1 = BaseItem(numBossesDefeated);
  BaseItem Item2 = BaseItem(numBossesDefeated);
  BaseItem Item3 = BaseItem(numBossesDefeated);
  cout << "Item1 name: " << Item1.getName() << endl;
  cout << "Item2 name: " << Item2.getName() << endl;
  cout << "Item3 name: " << Item3.getName() << endl;
}
