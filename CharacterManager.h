//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_CHARACTERMANAGER_H
#define PROYECTOII_CHARACTERMANAGER_H
#include "Characters.h"

class CharacterManager {
private:
    vector<Characters> characters;

public:
    CharacterManager();
    void loadFromFile(const string& filename);
    Characters loadCharacter(int option);
    int getCharacterCount() const;
    void displayAll() const;
};


#endif //PROYECTOII_CHARACTERMANAGER_H