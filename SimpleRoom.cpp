//
// Created by Abraham on 6/6/2026.
//

#include "SimpleRoom.h"
#include "EnemyManager.h"

#include <random>
SimpleRoom::SimpleRoom(vector<string> types) : enemyTypes(types) {
    roomName = "Dungeon Chamber";
}

void SimpleRoom::generateRoom() {
    enemies.clear();

    EnemyManager manager;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> amountDist(1, 4);
    int amount = amountDist(gen);

    uniform_int_distribution<> typeDist(0, (int)enemyTypes.size() - 1);

    for (int i = 0; i < amount; i++) {
        string randomEnemy = enemyTypes[typeDist(gen)];
        try {
            enemies.push_back(manager.getEnemyByName(randomEnemy));
        } catch (const runtime_error& e) {
            cerr << "Warning: " << e.what() << endl;
        }
    }
}

string SimpleRoom::getRoomType() const {
    return "Simple Room";
}