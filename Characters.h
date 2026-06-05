//
// Created by Abraham on 6/4/2026.
//

#ifndef PROYECTOII_CHARACTERS_H
#define PROYECTOII_CHARACTERS_H
#include "Utiles.h"
#include "Entity.h"

using namespace std;

class Character : public Entity {
public:
    Character();
    Character(string name, int health, int attack);

    string toString()const override;
};

#endif //PROYECTOII_CHARACTERS_H