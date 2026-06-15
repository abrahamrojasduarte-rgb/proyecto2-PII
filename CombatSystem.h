//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_COMBATSYSTEM_H
#define PROYECTOII_COMBATSYSTEM_H
#include "Characters.h"
#include "Enemy.h"
#include "Logger.h"
#include <iostream>

using namespace std;


class CombatSystem {
public:
    struct CombatResult {
        bool playerWon;
        int damageDealt;
        int damageTaken;
        int turnsElapsed;
    };

    static CombatResult fight(Characters& player, Enemy& enemy, Logger& logger);
};



#endif //PROYECTOII_COMBATSYSTEM_H