//
//  Inventory.cpp
//  inventory_Linked_List
//
//  Created by Tyree Stevenson on 3/20/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Inventory.hpp"
#include <iostream>

using namespace std;

//============================================================================================
// Inventory constructor and sets the length of the inventory as zero.
//============================================================================================

Inventory:: Inventory()
{
    length = 0;
}

//============================================================================================
// Returns true if the inventory is empty and false if it is not empty.
//============================================================================================

bool Inventory:: Is_Empty()
{
    return length == 0;
}

//============================================================================================
// Pass in an Item and the method adds it to a inventory.
//============================================================================================

void Inventory:: Add_New_Item(Item new_item)
{
    inventory[length] = new_item;
    length++;
}

//============================================================================================
// Sets the maxium length of the inventory.
//============================================================================================

void Inventory:: Create_Investory(int desired_upper_bound)
{
    upper_bounds = desired_upper_bound;
}

//============================================================================================
// Enter the key for an item and the method returns the Quantity.
//============================================================================================

int Inventory:: Get_Quantity(string key)
{
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].Key == key)
        {
            return inventory[i].Quantity;
        }
    }
    return -1;
}

//============================================================================================
// Pass in a key and int value positive or negative.
// The function then finds the item by the key and adds the int value to the item quantity.
//============================================================================================

void Inventory:: Update_Quantity(string key, int new_quantity)
{
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].Key == key)
        {
            inventory[i].Quantity += new_quantity;
        }
    }
}

//============================================================================================
// Deletes item from the inventory.
//============================================================================================

void Inventory:: Delete_Item(string key)
{
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].Key == key)
        {
            Item temp = inventory[i + 1];
            inventory[i + 1] = inventory[i];
            inventory[i] = temp;
        }
    }
    length -= 1;
}

//============================================================================================
// prints the items in the inventory in different orders
// order code: 1: by name, 2: by key
// bool: true=ascending order, false=descending order
//============================================================================================

void Inventory:: Print_Inventory(int order_code, bool ascending_order)
{
    if (order_code == 1 && ascending_order)
    {
        Ascending_Sort_Inventory_By_Name();
    }
    
    else if (order_code == 1 && !ascending_order)
    {
        Descending_Sort_Inventory_By_Name();
    }
    
    else if (order_code == 2 && ascending_order)
    {
        Ascending_Sort_Inventory_By_Key();
    }
    
    else if (order_code == 2 && !ascending_order)
    {
        Descending_Sort_Inventory_By_Key();
    }
    
    for (int i = 0; i < length; i++)
    {
        cout << "item #" << i + 1 << "\n";
        cout << "item name: " << inventory[i].Name << "\n";
        cout << "item key: " << inventory[i].Key << "\n";
        cout << "item quantity: " << inventory[i].Quantity << "\n\n";
    }
}

//============================================================================================
// Sorts items in ascending baised off of their name.
//============================================================================================

void Inventory:: Ascending_Sort_Inventory_By_Name()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].Name < inventory[j].Name) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

//============================================================================================
// Sorts items in ascending baised off of their key.
//============================================================================================

void Inventory:: Ascending_Sort_Inventory_By_Key()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].Key < inventory[j].Key) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

//============================================================================================
// Sorts items in descending baised off of their name.
//============================================================================================

void Inventory:: Descending_Sort_Inventory_By_Name()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].Name > inventory[j].Name) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

//============================================================================================
// Sorts items in descending baised off of their key.
//============================================================================================

void Inventory:: Descending_Sort_Inventory_By_Key()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].Key > inventory[j].Key) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

//============================================================================================
// Checks if inventory is full.
// Returns true if full.
// Returns false if not full.
//============================================================================================

bool Inventory:: Is_Full()
{
    return length == upper_bounds;
}

//============================================================================================
// Checks if the an Item exist in the inventory.
//============================================================================================

bool Inventory:: Does_Item_Exist(string key)
{
    bool item_found = false;
    for (int i = 0; i < length && !item_found; i++)
    {
        if (inventory[i].Key == key)
        {
            item_found = true;
        }
    }
    return item_found;
}
