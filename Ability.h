//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ABILITY_H
#define PROYECTOII_ABILITY_H
#include "Utiles.h"
#include "Characters.h"
#include "Enemy.h"
class Characters;
class Ability {
    public:
public:
    virtual ~Ability() = default;

    virtual string getName() const = 0;
    virtual void onAttack(Characters& player, Enemy& enemy) {}
    virtual void onDefense(Characters& player, Enemy& enemy, int& damage) {}
    virtual void onTurn(Characters& player) {}
};


#endif //PROYECTOII_ABILITY_H