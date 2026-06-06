//
// Created by Abraham on 6/6/2026.
//

#include "SimpleRoom.h"
#include "EnemyManager.h"

#include <random>
SimpleRoom::SimpleRoom(string m) {
    this->enemyName = m;
}
void SimpleRoom::generateRoom() {

    EnemyManager manager;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(1, 6);

    int amount = dist(gen);

    for(int i = 0; i < amount; i++) {

        enemies.push_back(
            manager.getEnemyByName(enemyName)
        );
    }
}