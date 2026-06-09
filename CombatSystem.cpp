//
// Created by joaoa on 8/6/2026.
//

#include "CombatSystem.h"

bool CombatSystem::fight(Character &player, Enemy &enemy) {
    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        enemy.setHealth(enemy.getHealth() - player.getAttack());
        cout << "Player hits " << enemy.getName() << " (-"<< player.getAttack() << " HP)\n";

        if (enemy.getHealth() <= 0) break;

        player.setHealth(player.getHealth() - enemy.getAttack());
        cout << enemy.getName() << " hits player (-" << enemy.getAttack() << " HP)\n";
        cout << "Player HP: "<< player.getHealth() << endl;
    }

    return player.getHealth() > 0;
}
