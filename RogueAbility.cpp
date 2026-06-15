//
// Created by joaoa on 9/6/2026.
//

#include "RogueAbility.h"

string RogueAbility::getName() const {
    return "Shadow Dodge";
}

void RogueAbility::onDefense(Characters& player, Enemy& enemy, int& damage) {
    if (rand() % 2 == 0) {
        damage = 0;
        cout << "  >> DODGE! (Shadow Dodge)" << endl;
    }
}