//
// Created by Abraham on 6/6/2026.
//

#include "CharacterManager.h"

Character CharacterManager::loadCharacter(int option) {
    ifstream file("characters.txt");
    if (!file) {
        cout<<"file characters failed"<<endl;
    }

    string name;
    int health;
    int attack;

    int counter = 1;

    while(file >> name >> health >> attack) {

        if(counter == option) {
            return Character(name, health, attack);
        }

        counter++;
    }

    throw invalid_argument("Invalid character");
}
