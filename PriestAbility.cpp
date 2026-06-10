//
// Created by joaoa on 9/6/2026.
//

#include "PriestAbility.h"

void PriestAbility::onTurn(Characters &player) {
    if (rand() % 2 == 0) {
        player.heal(25);
        cout<< "Priest passive heal +25 HP\n";
    }
}
