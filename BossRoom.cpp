//
// Created by Abraham on 6/6/2026.
//

#include "BossRoom.h"
#include "EnemyManager.h"

BossRoom::BossRoom(string bossName)
    : bossName(bossName) {}

void BossRoom::generateRoom() {

    EnemyManager manager;
    cout<<"\n BOSS ROOM \n";
    enemies.clear();
    enemies.push_back(manager.getEnemyByName(bossName));
}