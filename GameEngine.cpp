//
// Created by joaoa on 8/6/2026.
//

#include "GameEngine.h"
#include <ctime>

GameEngine::GameEngine(Character player) : player(player), logger("log.txt") {}

void GameEngine::setupLevels() {
    for (int i = 0; i < 3; i++) {
        Level* level = new Level();
        level->setupLevel();
        levels.push_back(level);
    }
}

void GameEngine::startGame() {
    srand(time(0));
    cout << "\n===== Starting Game ======\n";
    logger.log("Game started");
    logger.log("Player starts with health: " + to_string(player.getHealth()));

    int levelNumber = 1;

    for (Level* level : levels) {
        cout << "\n===== LEVEL " << levelNumber << " =====\n";
        logger.log("Starting level " + to_string(levelNumber));
        int roomNumber = 1;

        for (Room* room : level->getRooms()) {
            room->generateRoom();
            cout << "\n----- ROOM " << roomNumber << " -----\n";
            logger.log("Entered a room with " + to_string(room->getEnemies().size()) + " enemies");

            for (Enemy& enemy : room->getEnemies()) {
                logger.log("Encountered enemy: " + enemy.getName());
                cout<<"\nEnemy: "<<enemy.getName() <<endl;
                bool win = CombatSystem::fight(player, enemy);

                if (!win) {
                    cout << "----------------------------\n";
                    cout << "\nYou died, Game Over\n";
                    logger.log("Player died");
                    generateReport();
                    logger.close();
                    return;
                }

                cout << "Enemy defeated!\n";
                cout << "----------------------------\n";
                logger.log("Enemy defeated: " + enemy.getName());
                enemiesKilled++;

                if (enemy.getName() == "Skeleton") {
                    skeletonsKilled++;
                } else if (enemy.getName() == "SkeletonKing") {
                    bossesKilled++;
                    logger.log("Boss defeated!");
                }

                if (rand() % 3 == 0) {
                    logger.log("Player found a weapon!");
                }

                logger.log("Player health now: " + to_string(player.getHealth()));
            }

            roomNumber++;
            player.setHealth(player.getHealth() + 20);
            cout<<"You recover 20 HP\n";
            logger.log("Player healed +20 HP");
        }
        logger.log("Level " + to_string(levelNumber) + " completed");
        levelNumber++;
    }
    cout << "\nYou Win!\n";
    logger.log("Game completed successfully");
    generateReport();
    logger.close();

    for (Level* level : levels) {
        delete level;
    }
}

void GameEngine::generateReport() {
    ofstream report("report.txt");

    report<<"----- FINAL REPORT -----\n";
    report<<"Player: " << player.getName() << endl;
    report<<"Final health: " << player.getHealth() << endl;
    report<<"Enemies killed: "<<enemiesKilled << endl;
    report<<"Skeletons killed: "<<skeletonsKilled << endl;
    report<<"Bosses killed: "<<bossesKilled << endl;

    if (player.getHealth() > 0) {
        report << "Result: Victory\n";
    } else {
        report << "Result: Defeat\n";
    }

    report.close();
}