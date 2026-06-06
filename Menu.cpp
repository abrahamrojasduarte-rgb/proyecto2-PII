//
// Created by Abraham on 6/6/2026.
//

#include <iostream>

#include "Menu.h"
#include "CharacterManager.h"

using namespace std;

namespace Menu {

    void startMenu() {
        cout << "      SOUL KNIGHT     " << endl;

        cout << "\n1. Knight" << endl;
        cout << "2. Wizard" << endl;
        cout << "3. Rogue" << endl;
        cout << "4. Priest" << endl;

        int option;

        do {
            cout << "\nChoose a character: ";
            cin >> option;
        } while(option < 1 || option > 4);

        CharacterManager manager;
        Character hero = manager.loadCharacter(option);

        cout<<hero.toString();
    }

}