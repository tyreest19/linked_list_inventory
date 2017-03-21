//
//  main.cpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Item.h"
#include "Inventory.hpp"
#include "constants.h"
#include "helper_functions.h"
#include "Linked_List.hpp"

using namespace std;

int main()
{
    Item item1;
    Item item2;
    Item item3;
    Item item4;
    Item item5;
    Item item6;
    item1.Name = "Tyree";
    item2.Name = "Sam";
    item3.Name = "bill";
    item4.Name = "bob";
    item5.Name = "geogre";
    item6.Name = "cam";
    item1.Key = "key1";
    item2.Key = "key2";
    item3.Key = "key3";
    item4.Key = "key4";
    item5.Key = "key5";
    item6.Key = "key6";
    item1.Quantity = 7;
    item2.Quantity = 2;
    item3.Quantity = 5;
    item4.Quantity = 1;
    item5.Quantity = 0;
    item6.Quantity = 9;
    Linked_List list;
    list.append_node(item1);
    list.append_node(item2);
    list.append_node(item3);
    list.append_node(item4);
    list.append_node(item5);
    list.append_node(item6);
//    cout << "This is an inventory program which mimics an inventory! \n\n";
//    
//    int size_of_inventory = User_Inputted_Number(CREATE_INVENTORY_PROMPT, INVALID_INPUT, INVENTORY_INVALID_SIZE, MINIMUM_INVENTORY_SIZE, MAXIMUM_INVETORY_SIZE);
//    Inventory inventory;
//    string continue_using_menu;
//    inventory.Create_Investory(size_of_inventory);
//    
//    do
//    {
//        Menu(inventory);
//        cout << "\nIf you wish to continue enter yes or YES. If you wish to quit enter anything: ";
//        getline(cin, continue_using_menu);
//        cout << "\n";
//    } while (continue_using_menu == "YES" || continue_using_menu == "yes");
    return 0;
}
