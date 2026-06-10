//
// Created by Abraham on 6/6/2026.
//

#include "BossRoom.h"
#include "EnemyManager.h"

BossRoom::BossRoom(string bossName)
    : bossName(bossName) {}

void BossRoom::generateRoom() {
    enemies.clear();

    EnemyManager manager;
    cout<<"\n BOSS: "<<bossName<<"\n";
    enemies.push_back(manager.getEnemyByName(bossName));
}