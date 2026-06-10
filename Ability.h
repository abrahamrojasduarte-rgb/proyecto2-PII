//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ABILITY_H
#define PROYECTOII_ABILITY_H
#include "Characters.h"
#include "Enemy.h"

class Ability {
    public:
    virtual ~Ability() = default;

    virtual void onAttack(Characters& player, Enemy& enemy){}
    virtual void onDefense(Characters& player, Enemy& enemy, int& damage){}
    virtual void onTurn(Characters& player){}
};


#endif //PROYECTOII_ABILITY_H