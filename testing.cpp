#include <iostream>
#include <string>

#include "UnitTest.h"
#include "Game.h"
#include "Location.h"
#include "Entity.h"
#include "Shop.h"
#include "BaseItem.h"

int main() {
    UnitTest test; 
    int testSelector = 0; 
    string divider = "+------------------------------------------------------------------+";

    cout << divider << endl << "Select which test to run" << endl << divider << endl << "1. All tests" 
         << endl << "2. Entity Tests" << endl << "3. Location Tests" << endl << "4. Shop Tests" 
         << endl << divider << endl;

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
        default: 
            break;
    }

    cout << endl << "Test Complete" << endl << divider;

    return 0; 
}