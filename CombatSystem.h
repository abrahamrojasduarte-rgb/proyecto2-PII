//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_COMBATSYSTEM_H
#define PROYECTOII_COMBATSYSTEM_H
#include "Characters.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

class CombatSystem {
    public:
    static bool fight(Character& player, Enemy& enemy);
};


#endif //PROYECTOII_COMBATSYSTEM_H