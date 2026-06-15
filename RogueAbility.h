//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ROGUEABILITY_H
#define PROYECTOII_ROGUEABILITY_H
#include "Ability.h"

class RogueAbility : public Ability{
    public:
    string getName() const override;
    void onDefense(Characters& player, Enemy& enemy, int& damage) override;
};


#endif //PROYECTOII_ROGUEABILITY_H