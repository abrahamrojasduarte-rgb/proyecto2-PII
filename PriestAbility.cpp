//
// Created by joaoa on 9/6/2026.
//

#include "PriestAbility.h"

string PriestAbility::getName() const {
    return "Divine Heal";
}

void PriestAbility::onTurn(Characters& player) {
    if (rand() % 2 == 0) {
        player.heal(25);
        cout << "  >> Divine Heal +25 HP" << endl;
    }
}
