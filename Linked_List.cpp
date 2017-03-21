//
//  Linked_List.cpp
//  Linked_List_Inventory1
//
//  Created by Tyree Stevenson on 3/20/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//
#include <ostream>
#include "Linked_List.hpp"
#include "Item.h"

using namespace std;
Linked_List:: Linked_List()
{
    head = nullptr;
}

void Linked_List:: append_node(Item item)
{
    cout << item.Name << endl;
    Node *traversal_node;
    Node *new_node;
    new_node = new Node;
    new_node->item = item;
    
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

void Linked_List:: delete_node(Item item)
{
    Node *previous_node;
    Node *traversal_node;
    
    if ((head->item.Name == item.Name) && (head->item.Name == item.Key) && (head->item.Quantity == item.Quantity))
    {
        previous_node = head;
        head = head->next;
        delete previous_node;
    }
    
    else
    {
        previous_node = head;
        traversal_node = head->next;
        bool found_node = false;
        while (traversal_node->next && !found_node)
        {
            if ((head->item.Name == item.Name) && (head->item.Name == item.Key) && (head->item.Quantity == item.Quantity))
            {
                traversal_node = previous_node;
                previous_node = previous_node->next;
                delete previous_node;
                found_node = true;
            }
            else
            {
                previous_node = previous_node->next;
                traversal_node = traversal_node->next;
            }
        }
    }
}

void Linked_List:: print_list()
{
    Node *traversal_node = head;
    while (traversal_node)
    {
        cout << traversal_node->item.Name << "\n";
        traversal_node = traversal_node->next;
    }
}
