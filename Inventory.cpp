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
    head = nullptr;
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
    {
        Node *traversal_node;
        Node *new_node;
        new_node = new Node;
        new_node->item = new_item;
        
        if (!head)
        {
            head = new_node;
        }
        
        else
        {
            traversal_node = head;
            while (traversal_node->next)
            {
                traversal_node = traversal_node->next;
            }
            traversal_node->next = new_node;
        }
    }
    length++;
}


//============================================================================================
// Enter the key for an item and the method returns the Quantity.
//============================================================================================

int Inventory:: Get_Quantity(string key)
{
    int quantity = -1;
    bool found = false;
    Node *traversal_node = head;
    
    while (traversal_node && !found)
    {
        if (traversal_node->item.Key == key)
        {
            quantity = traversal_node->item.Quantity;
            found = true;
        }
        
        traversal_node = traversal_node->next;
    }
    
    return quantity;
}

//============================================================================================
// Pass in a key and int value positive or negative.
// The function then finds the item by the key and adds the int value to the item quantity.
//============================================================================================

void Inventory:: Update_Quantity(string key, int new_quantity)
{
    bool found = false;
    Node *traversal_node = head;
    
    while (traversal_node && !found)
    {
        if (traversal_node->item.Key == key)
        {
            traversal_node->item.Quantity += new_quantity;
            found = true;
        }
        
        traversal_node = traversal_node->next;
    }
}

//============================================================================================
// Deletes item from the inventory.
//============================================================================================

void Inventory:: Delete_Item(string key)
{
    {
        Node *previous_node = nullptr;
        Node *traversal_node = nullptr;
        
        if ((head->item.Key == key) && head !=nullptr)
        {
            traversal_node = head->next;
            delete head;
            head = traversal_node;
        }
        
        else
        {
            traversal_node = head;
            bool found_node = false;
            while (traversal_node != nullptr && !found_node)
            {
                if ((traversal_node->item.Key == key))
                {
                    previous_node->next = traversal_node->next;
                    delete traversal_node;
                    found_node = true;
                }
                else
                {
                    previous_node = traversal_node;
                    traversal_node = traversal_node->next;
                }
            }
        }
    }
    length--;
}

//============================================================================================
// prints the items in the inventory in different orders
// order code: 1: by name, 2: by key
// bool: true=ascending order, false=descending order
//============================================================================================

void Inventory:: Print_Inventory(int order_code, bool ascending_order)
{
    if (order_code == 1)
    {
        Sort_Inventory_By_Name(ascending_order);
    }
    
    else if (order_code == 2)
    {
        Sort_Inventory_By_Key(ascending_order);
    }
    
    Node *traversal_node = head;
    int count = 1;
    while (traversal_node)
    {
        cout << "Item #" << count << "\n";
        cout << "Item Name: " << traversal_node->item.Name << "\n";
        cout << "Item Key: " << traversal_node->item.Key << "\n";
        cout << "Item Quantity: " << traversal_node->item.Quantity << "\n\n";
        count++;
        traversal_node = traversal_node->next;
    }
}

//============================================================================================
// Sorts items in ascending baised off of their name.
//============================================================================================

void Inventory:: Sort_Inventory_By_Name(bool ascending_order)
{
    bool swap;
    if (ascending_order)
    {
        do {
            swap = false;
            for (Node *traversal_node = head; traversal_node->next; traversal_node = traversal_node->next)
        {
                if (traversal_node->item.Name > traversal_node->next->item.Name)
                {
                    Item temp = traversal_node->item;
                    traversal_node->item = traversal_node->next->item;
                    traversal_node->next->item = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
    
    else
    {
        do {
            swap = false;
            for (Node *traversal_node = head; traversal_node->next; traversal_node = traversal_node->next)
            {
                if (traversal_node->item.Name < traversal_node->next->item.Name)
                {
                    Item temp = traversal_node->next->item;
                    traversal_node->next->item = traversal_node->item;
                    traversal_node->item = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
}

//============================================================================================
// Sorts items in ascending baised off of their key.
//============================================================================================

void Inventory:: Sort_Inventory_By_Key(bool ascending_order)
{
    bool swap;
    if (ascending_order)
    {
        do {
            swap = false;
            for (Node *traversal_node = head; traversal_node->next; traversal_node = traversal_node->next)
            {
                if (traversal_node->item.Key > traversal_node->next->item.Key)
                {
                    Item temp = traversal_node->item;
                    traversal_node->item = traversal_node->next->item;
                    traversal_node->next->item = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
    
    else
    {
        do {
            swap = false;
            for (Node *traversal_node = head; traversal_node->next; traversal_node = traversal_node->next)
            {
                if (traversal_node->item.Key < traversal_node->next->item.Key)
                {
                    Item temp = traversal_node->next->item;
                    traversal_node->next->item = traversal_node->item;
                    traversal_node->item = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
}

//============================================================================================
// Checks if inventory is full.
// Returns true if full.
// Returns false if not full.
//============================================================================================

bool Inventory:: Is_Full()
{
    return false;
}

//============================================================================================
// Checks if the an Item exist in the inventory.
//============================================================================================

bool Inventory:: Does_Item_Exist(string key)
{
    bool found = false;
    Node *traversal_node = head;
    
    while (traversal_node && !found)
    {
        found = traversal_node->item.Key == key;
        traversal_node = traversal_node->next;
    }
    
    return found;
}
