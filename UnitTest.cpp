#include "UnitTest.h"

#include <iostream>
using namespace std;
// Start tests
void UnitTest::StartTests() {
  EntityTakeDamage();
  EntityMeleeAttack();
  EntityMagicAttack();
  LocationTravel();
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
  if (Gandalf.getHP() != 7) {
    cout << "EntityMeleeAttack Non-Resistance attack failed" << endl;
  };
  Gandalf.MeleeAttack(PtrToSauron);
  if (Sauron.getHP() != 11) {
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
void UnitTest::LocationTravel()
{ 
  // Descriptions
  string forestDescription = "In a dark, mist-shrouded forest teeming with fearsome monsters, \n hidden treasures glimmer among ancient ruins, luring the brave and foolish alike."; 
  string townDescription = "The medieval town bustles with life, its cobblestone streets \n winding past stone shops beneath the shadow of a towering castle";

  // Create locations
  Location Forest("Forest",forestDescription,"");
  Location Town("Town",townDescription,"");

  // Create temporary game
  Game LocationTest(0,Forest,true);

  /*
    Runs a short test that
    - Outputs current locations name
    - Shows the Forest
    - Travels to the Town
    - Shows the town
    - Output current locations mae
  */
  cout << LocationTest.viewCurrentLocation().getName() << endl;
  LocationTest.viewCurrentLocation().showLocation(); 
  LocationTest.viewCurrentLocation().travelToLocation(LocationTest,Town);
  cout << LocationTest.viewCurrentLocation().getName() << endl;
  LocationTest.viewCurrentLocation().showLocation();
}
