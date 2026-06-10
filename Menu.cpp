//
// Created by Abraham on 6/6/2026.
//

#include <iostream>
#include "Menu.h"
#include "CharacterManager.h"
#include "GameEngine.h"
#include "KnightAbility.h"
#include "PriestAbility.h"
#include "RogueAbility.h"
#include "WizardAbility.h"

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
        Characters hero = manager.loadCharacter(option);

        Ability* ability = nullptr;
        switch (option) {
            case 1:
                ability = new KnightAbility();
                break;
            case 2:
                ability = new WizardAbility();
                break;
            case 3:
                ability = new RogueAbility();
                break;
            case 4:
                ability = new PriestAbility();
                break;
        }
        hero.setAbility(ability);

        cout<<hero.toString();

        GameEngine game(hero);
        game.setupLevels();
        game.startGame();
    }
}