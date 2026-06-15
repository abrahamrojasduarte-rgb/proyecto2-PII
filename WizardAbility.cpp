//
// Created by joaoa on 9/6/2026.
//

#include "WizardAbility.h"

string WizardAbility::getName() const {
    return "Arcane Surge";
}

void WizardAbility::onAttack(Characters& player, Enemy& enemy) {
    if (rand() % 2 == 0) {
        enemy.setHealth(enemy.getHealth() - player.getAttack());
        cout << "  >> CRITICAL HIT! (Arcane Surge)" << endl;
    }
}