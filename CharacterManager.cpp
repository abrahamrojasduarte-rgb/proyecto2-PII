//
// Created by Abraham on 6/6/2026.
//

#include "CharacterManager.h"

Characters CharacterManager::loadCharacter(int option) {
    ifstream file("characters.txt");
    if (!file) {
        throw runtime_error("characters.txt not found");
    }

    string name;
    int health;
    int attack;

    int counter = 1;

    while(file >> name >> health >> attack) {

        if(counter == option) {
            return Characters(name, health, attack);
        }

        counter++;
    }

    throw invalid_argument("Invalid character");
}
