#ifndef BASEITEM_H
#define BASEITEM_H

#include <iostream>
#include <string>

using namespace std;

class BaseItem {
    private:
        string name; 
    public:
        BaseItem(); // Defeault Constructor
        BaseItem(string name); // Constructor 
        string getName(); // Returns name
};

#endif