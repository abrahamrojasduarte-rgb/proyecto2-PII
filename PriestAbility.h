//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_PRIESTABILITY_H
#define PROYECTOII_PRIESTABILITY_H
#include "Ability.h"

class PriestAbility : public Ability{
    public:
    string getName() const override;
    void onTurn(Characters& player) override;
};


#endif //PROYECTOII_PRIESTABILITY_H