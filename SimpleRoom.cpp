//
// Created by Abraham on 6/6/2026.
//

#include "SimpleRoom.h"
#include "EnemyManager.h"

#include <random>
SimpleRoom::SimpleRoom(vector<string> types) {
    this->enemyTypes = types;
}
void SimpleRoom::generateRoom() {
    enemies.clear();

    EnemyManager manager;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> amountDist(1, 4);
    int amount = amountDist(gen);

    uniform_int_distribution<> typeDist(0, enemyTypes.size() - 1);

    for(int i = 0; i < amount; i++) {
        string randomEnemy = enemyTypes[typeDist(gen)];

        enemies.push_back(manager.getEnemyByName(randomEnemy));
    }
}