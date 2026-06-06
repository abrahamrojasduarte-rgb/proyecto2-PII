//
// Created by Abraham on 6/6/2026.
//

#include "EnemyManager.h"
vector<Enemy> EnemyManager::loadEnemies() {

    ifstream file("enemies.txt");

    vector<Enemy> enemies;

    string name;
    int health;
    int attack;

    while(file >> name >> health >> attack) {
        enemies.push_back(Enemy(name, health, attack));
    }

    return enemies;
}

Enemy EnemyManager::getEnemyByName(string targetName) {

    vector<Enemy> enemies = loadEnemies();

    for(const Enemy& enemy : enemies) {

        if(enemy.getName() == targetName) {
            return enemy;
        }
    }

    return Enemy();
}