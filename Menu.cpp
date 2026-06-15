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
        cout << "Choose a character: " <<endl;
        cout <<"    Name       Healt       Attack";
        cout << "\n1. Knight     120          15" << endl;
        cout << "2. Wizard     80           25" << endl;
        cout << "3. Rogue      90           20" << endl;
        cout << "4. Priest     100          10" << endl;

        CharacterManager manager;

        cout << "\n  Character Abilities:" << endl;
        cout << "  1. Knight  - Shield Block (reduces damage by 20%)" << endl;
        cout << "  2. Wizard  - Arcane Surge (50% chance for critical hit)" << endl;
        cout << "  3. Rogue   - Shadow Dodge (50% chance to evade)" << endl;
        cout << "  4. Priest  - Divine Heal  (50% chance to heal each turn)" << endl;

        int option;
        do {
            cout << "\n  Select character (1-" << manager.getCharacterCount() << "): ";
            cin >> option;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                option = 0;
            }
        } while (option < 1 || option > manager.getCharacterCount());

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
            default:
                ability = new KnightAbility();
                break;
        }
        hero.setAbility(ability);

        cout << "\n  Your hero:" << endl;
        cout << hero.toString();
        cout << "  Ability: " << ability->getName() << endl;

        GameEngine game(hero);
        game.setupLevels();
        game.startGame();
    }
}