#include "BaseItem.h"

BaseItem::BaseItem()
{
    this->name = "No name";
}

BaseItem::BaseItem(string name)
{
    this->name = name; 
}

string BaseItem::getName()
{
    return this->name;
}
