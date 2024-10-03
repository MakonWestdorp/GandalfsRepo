#include "UnitTest.h"

#include <iostream>
using namespace std;
void UnitTest::StartAllTests()
{
  void StartEntityTests();
  void StartLocationTests();
  void StartShopTests();
}
// Start tests
void UnitTest::StartEntityTests() {
  EntityTakeDamage();
  EntityMeleeAttack();
  EntityMagicAttack();
}

void UnitTest::StartLocationTests() {
  LocationTravel();
}

void UnitTest::StartShopTests() {
  BasicShopTest();
}

void UnitTest::StartTownTests()
{
  FirstTownTest();
}

// Entity test functions
void UnitTest::EntityTakeDamage() {
  Entity Gandalf = Entity("Gandalf", 15, 4, 7, 35, "Magic");
  Gandalf.takeDamage(2, "Magic");
  if (Gandalf.getHP() != 14) {
    cout << "EntityTakeDamage Resistance Check Failed" << endl;
  };
  Gandalf.setHP(15);
  Gandalf.takeDamage(4, "BluntForce");
  if (Gandalf.getHP() != 11) {
    cout << "EntityTakeDamage Non-Resistance Check Failed" << endl;
  };
  Gandalf.setHP(15);
  Gandalf.takeDamage(0, "BluntForce");
  if (Gandalf.getHP() != 15) {
    cout << "EntityTakeDamage No Damage Check failed" << endl;
  };
}

void UnitTest::EntityMeleeAttack() {
  Entity Gandalf = Entity("Gandalf", 15, 4, 8, 15, "Magic");
  Entity Sauron = Entity("Sauron", 15, 4, 8, 10, "BluntForce");
  Entity* PtrToGandalf = &Gandalf;
  Entity* PtrToSauron = &Sauron;
  Sauron.MeleeAttack(PtrToGandalf);
  if (Gandalf.getHP() != 15 - Sauron.getSTR()) {
    cout << "EntityMeleeAttack Non-Resistance attack failed" << endl;
  };
  Gandalf.MeleeAttack(PtrToSauron);
  if (Sauron.getHP() != 15 - 0.5 * Gandalf.getSTR()) {
    cout << "EntityMeleeAttack Resistance attack failed" << endl;
  };
}

void UnitTest::EntityMagicAttack() {
  Entity Gandalf = Entity("Gandalf", 15, 4, 8, 14, "Magic");
  Entity Sauron = Entity("Sauron", 15, 4, 8, 10, "BluntForce");
  Entity* PtrToGandalf = &Gandalf;
  Entity* PtrToSauron = &Sauron;
  Sauron.MagicAttack(PtrToGandalf);
  if (Gandalf.getHP() != 10) {
    cout << "EntityMeleeAttack Resistance attack failed" << endl;
  };
  Gandalf.MagicAttack(PtrToSauron);
  if (Sauron.getHP() != 1) {
    cout << "EntityMeleeAttack Non-Resistance attack failed" << endl;
  };
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

  int cashOnHand = 0; // Needed to call function

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
  LocationTest.viewCurrentLocation()->showLocation(LocationTest,cashOnHand);
  LocationTest.viewCurrentLocation()->travelToLocation(LocationTest, Town);
  cout << LocationTest.viewCurrentLocation()->getName() << endl;
  LocationTest.viewCurrentLocation()->showLocation(LocationTest,cashOnHand);
}

void UnitTest::BasicShopTest()
{
  // Create inventory
  BaseItem *inventory = new BaseItem[5]; 
  inventory[0] = BaseItem("Big Sword");
  inventory[1] = BaseItem("Small Sword");
  inventory[2] = BaseItem("Legendary Sword");
  inventory[3] = BaseItem("Fire Sword");
  inventory[4] = BaseItem("Ancient Sword");

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
  string shopDescription = "Steel & Sorcery offers finely crafted blades, \nfrom master-forged steel to rare enchanted swords";
  Shop WeaponsShop(inventory,prices,forSaleStatus,"Steel & Sorcery","Timmy",shopDescription,"");

  // Test shop interface
  int cashOnHand = 50;
  while (WeaponsShop.showShopInterface(cashOnHand) == true) {
  
  }

  // Create new inventory
  inventory[0] = BaseItem("Bigger Sword");
  inventory[1] = BaseItem("Smaller Sword");
  inventory[2] = BaseItem("Gods Sword");
  inventory[3] = BaseItem("Blazing Sword");
  inventory[4] = BaseItem("The Origin Sword");
  
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

  WeaponsShop.updateShop(inventory,prices,forSaleStatus);

   // Test shop interface
  while (WeaponsShop.showShopInterface(cashOnHand) == true) {
  
  }
}

void UnitTest::FirstTownTest()
{ 
  Game game; 
  int cashOnHand = 50;
  game.initialiseLocations();
  game.initialiseShops();
  game.setCurrentLocation(game.viewLocations()[0]);

  while(game.isGameRunning() == true) {
    game.viewCurrentLocation()->showLocation(game,cashOnHand);
  }
}
