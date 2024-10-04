#ifndef BASEITEM_H
#define BASEITEM_H

#include <iostream>
#include <string>

using namespace std;

class BaseItem {
 private:
  string name;

 public:
  BaseItem();               // Defeault Constructor
  BaseItem(string name);    // Constructor
  string getName();         // Returns name
  string nameRandomiser();  // Generates a random name for the item.
  string getRandomElement(const string elements[], int size);
};

#endif