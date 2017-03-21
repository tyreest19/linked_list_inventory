//
//  Linked_List.hpp
//  Linked_List_Inventory1
//
//  Created by Tyree Stevenson on 3/20/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Linked_List_hpp
#define Linked_List_hpp

#include <stdio.h>
#include "Item.h"

class Linked_List
{
public:
    
    struct Node
    {
        Item item;
        Node* next;
    };
    
    Linked_List();
    void append_node(Item item);
    void delete_node(Item item);
    void print_list();
    Node* head;
};
#endif /* Linked_List_hpp */
