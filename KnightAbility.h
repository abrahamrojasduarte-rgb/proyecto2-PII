//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_KNIGHTABILITY_H
#define PROYECTOII_KNIGHTABILITY_H
#include "Ability.h"

class KnightAbility : public Ability{
public:
    void onDefense(Characters &player, Enemy &enemy, int &damage) override;
};


#endif //PROYECTOII_KNIGHTABILITY_H