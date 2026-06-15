//
// Created by joaoa on 8/6/2026.
//

#include "GameEngine.h"
#include <ctime>

#include "Ability.h"

GameEngine::GameEngine(Characters player) : player(player), logger("log.txt") {
    try {
        eventSystem.loadEvents("events.txt");
    } catch (const exception& e) {
        cerr << "Note: " << e.what() << " (events disabled)" << endl;
    }
}

GameEngine::~GameEngine() {
    for (Level* level : levels) {
        delete level;
    }
    levels.clear();
}

void GameEngine::setupLevels() {
    Level* level1 = new Level(1);
    level1->setupLevel({"Skeleton", "Goblin", "Zombie"}, "SkeletonKing", 4);
    levels.push_back(level1);

    Level* level2 = new Level(2);
    level2->setupLevel({"Goblin", "Skeleton", "Zombie"}, "GoblinChief", 5);
    levels.push_back(level2);

    Level* level3 = new Level(3);
    level3->setupLevel({"Zombie", "Skeleton", "Goblin"}, "ZombieTyrant", 5);
    levels.push_back(level3);
}

void GameEngine::startGame() {
    srand(time(0));

    cout << "\n";
    cout << "         SOUL KNIGHT - ADVENTURE        " << endl;
    cout << "    Explore dungeons, defeat enemies,   " << endl;
    cout << "    collect loot, and slay the bosses!  " << endl;

    logger.logSection("GAME START");
    logger.log("Player: " + player.getName() + " (" + player.getCharacterClass() + ")");
    logger.log("Starting HP: " + to_string(player.getHealth()));
    logger.log("Starting ATK: " + to_string(player.getAttack()));
    logger.log("Ability: " + string(player.getAbility()->getName()));

    for (Level* level : levels) {
        cout << "\n";
        cout << "  " << left << setw(28) << level->getLevelName() << " " << endl;
        cout << "   Rooms: " << left << setw(21) << level->getRoomCount() << " " << endl;

        logger.logSection(level->getLevelName());
        int levelKills = 0;
        int roomNumber = 1;

        for (Room* room : level->getRooms()) {
            room->generateRoom();

            cout << "\n  --- " << room->getRoomType() << " " << roomNumber << " ---" << endl;
            cout << "  Enemies: " << room->getEnemies().size() << endl;

            logger.log("Entered " + room->getRoomType() + " " + to_string(roomNumber)
                       + " (" + to_string(room->getEnemies().size()) + " enemies)");

            processRoomEvent();

            if (!player.isAlive()) {
                cout << "           GAME OVER                  " << endl;
                cout << "    You succumbed to a trap...         " << endl;
                killsPerLevel.push_back(levelKills);
                logger.log("Player died from event");
                generateReport();
                logger.close();
                return;
            }

            for (Enemy& enemy : room->getEnemies()) {
                cout << "\n  " << enemy.toString() << endl;

                CombatSystem::CombatResult result = CombatSystem::fight(player, enemy, logger);
                totalDamageDealt += result.damageDealt;
                totalDamageTaken += result.damageTaken;
                totalTurns += result.turnsElapsed;

                if (!result.playerWon) {
                    cout << "             GAME OVER                   " << endl;
                    cout << "      " << left << setw(34) << (player.getName() + " has fallen...") << " ║" << endl;

                    killsPerLevel.push_back(levelKills);
                    generateReport();
                    logger.close();
                    return;
                }

                cout << "  >> " << enemy.getName() << " defeated!" << endl;
                enemiesKilled++;
                levelKills++;

                player.gainExperience(enemy.getExpReward());
                logger.log("Gained " + to_string(enemy.getExpReward()) + " XP");

                if (enemy.isBoss()) {
                    bossesKilled++;
                    bossesDefeated.push_back(enemy.getName());
                    logger.log("BOSS DEFEATED: " + enemy.getName());
                }

                processItemDrop(enemy);
                logger.log("Player HP: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()));
            }

            roomNumber++;

            player.heal(15);
            cout << "  >> Room cleared! +15 HP recovered" << endl;
            logger.log("Room cleared, healed +15 HP");
        }

        killsPerLevel.push_back(levelKills);
        cout << "\n  ========================================" << endl;
        cout << "  " << level->getLevelName() << " COMPLETED!" << endl;
        cout << "  Enemies defeated: " << levelKills << endl;
        cout << "  ========================================" << endl;

        logger.log(level->getLevelName() + " completed - " + to_string(levelKills) + " enemies killed");
    }

    cout << "\n";
    cout << "           VICTORY!                      " << endl;
    cout << "      All dungeons have been cleared!    " << endl;

    logger.logSection("GAME COMPLETE");
    logger.log("All levels completed successfully!");
    generateReport();
    logger.close();
}

void GameEngine::processItemDrop(const Enemy& enemy) {
    int dropChance = rand() % 100;

    if (dropChance < 40) {
        Item<int> weapon = itemManager.getRandomWeapon();
        if (weapon.getValue() > player.getWeaponBonus()) {
            player.equipWeapon(weapon.getValue());
            cout << "  >> Equipped: " << weapon.getName() << " (+" << weapon.getValue() << " ATK)" << endl;
            logger.log("Equipped weapon: " + weapon.getName() + " (+" + to_string(weapon.getValue()) + ")");
            itemsCollected++;
        } else {
            cout << "  >> Found: " << weapon.getName() << " (too weak, ignored)" << endl;
            logger.log("Ignored weaker weapon: " + weapon.getName());
        }
    } else if (dropChance < 75) {
        Item<int> potion = itemManager.getRandomPotion();
        player.heal(potion.getValue());
        cout << "  >> Used: " << potion.getName() << " (+" << potion.getValue() << " HP)" << endl;
        logger.log("Used potion: " + potion.getName() + " (+" + to_string(potion.getValue()) + " HP)");
        itemsCollected++;
    }
}

void GameEngine::processRoomEvent() {
    if (eventSystem.getEventCount() > 0 && eventSystem.shouldTriggerEvent()) {
        GameEvent event = eventSystem.getRandomEvent();
        cout << "\n  [EVENT] " << event.name << endl;
        eventSystem.applyEvent(event, player);
        logger.log("Event triggered: " + event.name + " (" + event.getTypeName() + ")");
        eventsTriggered++;
    }
}

void GameEngine::generateReport() {
    ofstream report("report.txt");
    if (!report.is_open()) {
        cerr << "Error: Could not create report file." << endl;
        return;
    }

    report << "         SOUL KNIGHT - FINAL REPORT          " << endl;
    report << endl;

    report << "--- Player Summary ---" << endl;
    report << "Name:           " << player.getName() << endl;
    report << "Class:          " << player.getCharacterClass() << endl;
    report << "Final Level:    " << player.getLevel() << endl;
    report << "Final Health:   " << player.getHealth() << "/" << player.getMaxHealth() << endl;
    report << "Final Attack:   " << player.getAttack() << endl;
    report << "Weapon Bonus:   +" << player.getWeaponBonus() << endl;
    report << endl;

    report << "--- Combat Statistics ---" << endl;
    report << "Total enemies killed:   " << enemiesKilled << endl;
    report << "Bosses defeated:        " << bossesKilled << endl;
    report << "Total damage dealt:     " << totalDamageDealt << endl;
    report << "Total damage taken:     " << totalDamageTaken << endl;
    report << "Total combat turns:     " << totalTurns << endl;
    report << "Items collected:        " << itemsCollected << endl;
    report << "Events triggered:       " << eventsTriggered << endl;
    report << endl;

    report << "--- Kills Per Level ---" << endl;
    for (int i = 0; i < (int)killsPerLevel.size(); i++) {
        report << "Level " << (i + 1) << ": " << killsPerLevel[i] << " enemies killed" << endl;
    }
    report << endl;

    if (!bossesDefeated.empty()) {
        report << "--- Bosses Defeated ---" << endl;
        for (const string& boss : bossesDefeated) {
            report << "  * " << boss << endl;
        }
        report << endl;
    }

    report << "--- Result ---" << endl;
    if (player.isAlive() && bossesKilled == 3) {
        report << "VICTORY - All dungeons cleared!" << endl;
    } else if (player.isAlive()) {
        report << "PARTIAL VICTORY - Adventure incomplete" << endl;
    } else {
        report << "DEFEAT - The hero has fallen" << endl;
    }

    report << endl;
    report << "══════════════════════════════════════════════" << endl;
    report.close();

    cout << "\n  [Report saved to report.txt]" << endl;
}