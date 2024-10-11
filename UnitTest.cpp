#include "UnitTest.h"
#include "Player.h"
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
  Entity Sauron = Entity("Sauron", 0);
  Entity *PtrToSauron = &Sauron;
  string GandalfsResistance = Gandalf.getRes();
  string SauronsResistance = Sauron.getRes();
  cout << "Sauron has " << Sauron.getHP() << " health points" << endl;
  Gandalf.Attack(PtrToSauron, SauronsResistance, "MAG", 0);
  cout << "Gandalf has attacked Sauron" << endl;
  cout << "Sauron now has" << Sauron.getHP() << " health points" << endl;
}

// Location test functions
void UnitTest::LocationTravel() {
  // Not required for test but needed for function calls
  Player *player = new Player("Player",5,5,5,5,"");
  int numBossesDefeated = 0;
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
  LocationTest.viewCurrentLocation()->showLocation(LocationTest,player, numBossesDefeated);
  LocationTest.viewCurrentLocation()->travelToLocation(LocationTest, Town, player,numBossesDefeated);
  cout << LocationTest.viewCurrentLocation()->getName() << endl;
  LocationTest.viewCurrentLocation()->showLocation(LocationTest, player, numBossesDefeated);
}

void UnitTest::BasicShopTest() {
  // Needed for test
  int numBossesDefeated = 0;
  Player *player = new Player("Player",5,5,5,5,"");

  // Create shop
  string shopDescription =
      "Steel & Sorcery offers finely crafted blades, \nfrom master-forged "
      "steel to rare enchanted swords";
  Shop WeaponsShop(numBossesDefeated, "Steel & Sorcery","Timmy", shopDescription, "",1);

  // Test shop interface
  while (WeaponsShop.showShopInterface(player) == true) {
  }

  WeaponsShop.updateShop(numBossesDefeated,1);

  // Test shop interface
  while (WeaponsShop.showShopInterface(player) == true) {
  }
}

void UnitTest::FirstTownTest() {
  Game game;
  srand(time(0));
  Player *player = new Player();
  int numBossesDefeated = 0;
  game.initialiseLocations();
  game.initialiseShops();
  game.setCurrentLocation(game.viewLocations()[0]);

  while (game.isGameRunning() == true) {
    game.viewCurrentLocation()->showLocation(game, player, numBossesDefeated);
  }
}

void UnitTest::BaseItemNameGeneratorTest() {
  int numBossesDefeated = 0;
  BaseItem Item1 = BaseItem(numBossesDefeated);
  BaseItem Item2 = BaseItem(numBossesDefeated);
  BaseItem Item3 = BaseItem(numBossesDefeated);
  cout << "Item1 name: " << Item1.getName() << endl;
  cout << "Item2 name: " << Item2.getName() << endl;
  cout << "Item3 name: " << Item3.getName() << endl;
}
