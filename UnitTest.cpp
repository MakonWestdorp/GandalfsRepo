#include "UnitTest.h"

#include <iostream>
using namespace std;
void UnitTest::EntityTakeDamage() {
  Entity Gandalf = Entity("Gandalf", 10, 4, 7, 35, "Magic");
  Gandalf.takeDamage(2, "Magic");
  if (Gandalf.getHP() != 9) {
    cout << "EntityTakeDamage Resistance Check Failed" << endl;
  };
  Gandalf.setHP(15);
  Gandalf.takeDamage(4, "BluntForce");
  if (Gandalf.getHP() != 11) {
    cout << "EntityTakeDamage Non-Resistance Check Failed" << endl;
  };
}