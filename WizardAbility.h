//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_WIZARDABILITY_H
#define PROYECTOII_WIZARDABILITY_H
#include "Ability.h"

class WizardAbility : public Ability{
    public:
    void onAttack(Characters &player, Enemy &enemy) override;
};


#endif //PROYECTOII_WIZARDABILITY_H