//
// Created by Abraham on 6/6/2026.
//

#include "BossRoom.h"
#include "EnemyManager.h"

BossRoom::BossRoom(string bossName) : bossName(bossName) {
    roomName = "Boss Arena";
}

void BossRoom::generateRoom() {
    enemies.clear();

    EnemyManager manager;
    cout << "\n  ========================================" << endl;
    cout << "  |     BOSS ENCOUNTER: " << bossName << "     |" << endl;
    cout << "  ========================================" << endl;

    try {
        Enemy boss = manager.getEnemyByName(bossName);
        boss.setBoss(true);
        enemies.push_back(boss);
    } catch (const runtime_error& e) {
        throw runtime_error("Critical error: Boss '" + bossName + "' not found in enemy database.");
    }
}

string BossRoom::getRoomType() const {
    return "Boss Room";
}