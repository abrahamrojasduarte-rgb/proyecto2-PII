//
// Created by Abraham on 6/6/2026.
//

#include "EnemyManager.h"
EnemyManager::EnemyManager() : loaded(false) {
    loadFromFile("enemies.txt");
}

void EnemyManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file '" + filename + "'. Make sure it exists in the working directory.");
    }

    string name;
    int health;
    int attack;

    while (file >> name >> health >> attack) {
        if (health <= 0 || attack <= 0) {
            throw invalid_argument("Error: Invalid stats for enemy '" + name + "'. Health and attack must be positive.");
        }
        bool isBoss = (health >= 80);
        enemies.emplace_back(name, health, attack, isBoss);
    }

    if (enemies.empty()) {
        throw runtime_error("Error: No enemies found in '" + filename + "'.");
    }

    loaded = true;
    file.close();
}

vector<Enemy> EnemyManager::getEnemies() const {
    return enemies;
}

Enemy EnemyManager::getEnemyByName(const string& targetName) {
    for (const Enemy& enemy : enemies) {
        if (enemy.getName() == targetName) {
            return enemy;
        }
    }
    throw runtime_error("Error: Enemy '" + targetName + "' not found in enemy database.");
}

int EnemyManager::getEnemyCount() const {
    return (int)enemies.size();
}