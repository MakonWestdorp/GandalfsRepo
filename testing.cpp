#include <iostream>
#include <string>

#include "Arena.h"
#include "BaseItem.h"
#include "Entity.h"
#include "Forest.h"
#include "Game.h"
#include "Location.h"
#include "Shop.h"
#include "Town.h"
#include "UnitTest.h"

int main() {
  UnitTest test;
  int testSelector = 0;
  string divider =
      "+------------------------------------------------------------------+";

  cout << divider << endl
       << "Select which test to run" << endl
       << divider << endl
       << "1. All tests" << endl
       << "2. Entity Tests" << endl
       << "3. Location Tests" << endl
       << "4. Shop Tests" << endl
       << "5. Town tests" << endl
       << "6. BaseItem tests" << endl
       << divider << endl;

  cin >> testSelector;
  cout << "Test begin" << endl;

  switch (testSelector) {
    case 1:
      test.StartAllTests();
      break;
    case 2:
      test.StartEntityTests();
      break;
    case 3:
      test.StartLocationTests();
      break;
    case 4:
      test.StartShopTests();
      break;
    case 5:
      test.StartTownTests();
      break;
    case 6:
      test.StartBaseItemTests();
      break;
    default:
      break;
  }

  cout << endl << "Test's Complete" << endl << divider;
  cout << endl;
  return 0;
}