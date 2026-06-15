//
// Created by joaoa on 9/6/2026.
//

#include "KnightAbility.h"

string KnightAbility::getName() const {
    return "Shield Block";
}

void KnightAbility::onDefense(Characters& player, Enemy& enemy, int& damage) {
    damage = (int)(damage * 0.8);
}