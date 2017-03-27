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

using namespace std;

int main()
{
    cout << "This is an inventory program which mimics an inventory! \n";
    cout << "Use the menu to access your inventory! \n\n";
    Inventory inventory;
    string continue_using_menu;
    do
    {
        Menu(inventory);
        cout << "\nIf you wish to continue enter yes or YES. If you wish to quit enter anything: ";
        getline(cin, continue_using_menu);
        cout << "\n";
    } while (continue_using_menu == "YES" || continue_using_menu == "yes");
    return 0;
}
