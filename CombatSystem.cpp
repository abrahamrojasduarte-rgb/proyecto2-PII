//
// Created by joaoa on 8/6/2026.
//

#include "CombatSystem.h"
#include "Ability.h"

CombatSystem::CombatResult CombatSystem::fight(Characters& player, Enemy& enemy, Logger& logger) {
    CombatResult result = {false, 0, 0, 0};

    logger.log("Combat started: " + player.getName() + " vs " + enemy.getName());

    while (player.isAlive() && enemy.isAlive()) {
        result.turnsElapsed++;

        player.getAbility()->onAttack(player, enemy);
        int playerDamage = player.getAttack();
        enemy.setHealth(enemy.getHealth() - playerDamage);
        result.damageDealt += playerDamage;

        cout << "  " << player.getName() << " attacks " << enemy.getName()
             << " (-" << playerDamage << " HP)" << endl;

        if (!enemy.isAlive()) break;

        int enemyDamage = enemy.getAttack();
        player.getAbility()->onDefense(player, enemy, enemyDamage);
        player.setHealth(player.getHealth() - enemyDamage);
        result.damageTaken += enemyDamage;

        cout << "  " << enemy.getName() << " attacks " << player.getName()
             << " (-" << enemyDamage << " HP)" << endl;
        cout << "  [HP: " << player.getHealth() << "/" << player.getMaxHealth() << "]" << endl;

        player.getAbility()->onTurn(player);
    }

    result.playerWon = player.isAlive();

    if (result.playerWon) {
        logger.log("Victory! " + enemy.getName() + " defeated in " + to_string(result.turnsElapsed) + " turns");
    } else {
        logger.log("Defeat! " + player.getName() + " fell to " + enemy.getName());
    }

    return result;
}