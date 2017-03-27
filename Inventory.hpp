//
//  Inventory.hpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <string>
#include "Item.h"

using namespace std;
const int MAXIMUM_INVETORY_SIZE = 100;


class Inventory
{
public:
    
    struct Node
    {
        Item item;
        Node* next = nullptr;
    };
    
    Inventory();
    bool Is_Empty();
    void Add_New_Item(Item new_item);
    int Get_Quantity(string key);
    void Update_Quantity(string key, int new_quantity);
    void Delete_Item(string key);
    void Print_Inventory(int order_code, bool ascending_order);
    bool Is_Full();
    bool Does_Item_Exist(string key);
    Node* head;
private:
    
    int length;
    void Sort_Inventory_By_Name(bool ascending_order);
    void Sort_Inventory_By_Key(bool ascending_order);
};
#endif /* Inventory_hpp */
