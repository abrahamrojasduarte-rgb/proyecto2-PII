//
// Created by Abraham on 6/6/2026.
//

#include "CharacterManager.h"

#include <iomanip>

CharacterManager::CharacterManager() {
    loadFromFile("characters.txt");
}

void CharacterManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file '" + filename + "'. Make sure it exists in the working directory.");
    }

    string name;
    int health;
    int attack;

    while (file >> name >> health >> attack) {
        if (health <= 0 || attack <= 0) {
            throw invalid_argument("Error: Invalid stats for character '" + name + "'. Health and attack must be positive.");
        }
        characters.emplace_back(name, health, attack, name);
    }

    if (characters.empty()) {
        throw runtime_error("Error: No characters found in '" + filename + "'.");
    }

    file.close();
}

Characters CharacterManager::loadCharacter(int option) {
    if (option < 1 || option > (int)characters.size()) {
        throw invalid_argument("Error: Invalid character selection. Choose between 1 and " + to_string(characters.size()));
    }
    return characters[option - 1];
}

int CharacterManager::getCharacterCount() const {
    return (int)characters.size();
}
