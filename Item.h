//
//  Item.h
//  Linked_List_Inventory1
//
//  Created by Tyree Stevenson on 3/20/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
struct Item
{
    string Name;
    string Key;
    int Quantity;
//    bool operator==(const Item& item);
};
//bool Item::operator==(const Item& item)
//{
//    return (this->Name == item.Name) && (this->Key == item.Key) && (this->Quantity == item.Quantity);
//};


#endif /* Item_h */
