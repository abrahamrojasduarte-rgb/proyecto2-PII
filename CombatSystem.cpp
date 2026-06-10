//
// Created by joaoa on 8/6/2026.
//

#include "CombatSystem.h"

#include "Ability.h"

bool CombatSystem::fight(Characters &player, Enemy &enemy) {
    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        player.getAbility()->onAttack(player, enemy);
        enemy.setHealth(enemy.getHealth() - player.getAttack());
        cout << "Player hits " << enemy.getName() << " (-"<< player.getAttack() << " HP)\n";

        if (enemy.getHealth() <= 0) break;

        int damage = enemy.getAttack();
        player.getAbility()->onDefense(player,enemy,damage);
        player.setHealth(player.getHealth() - damage);
        cout << enemy.getName() << " hits player (-" << damage << " HP)\n";
        cout << "Player HP: "<< player.getHealth() << endl;
        player.getAbility()->onTurn(player);
    }

    return player.getHealth() > 0;
}