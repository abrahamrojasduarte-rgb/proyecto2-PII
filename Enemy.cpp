//
// Created by Abraham on 6/5/2026.
//

#include "Enemy.h"
Enemy::Enemy() : Entity(), boss(false), expReward(10) {}

Enemy::Enemy(string name, int health, int attack, bool isBoss)
    : Entity(name, health, attack), boss(isBoss) {
    expReward = isBoss ? 50 : (10 + attack);
}

bool Enemy::isBoss() const {
    return boss;
}

int Enemy::getExpReward() const {
    return expReward;
}

void Enemy::setBoss(bool isBoss) {
    this->boss = isBoss;
    if (isBoss) {
        expReward = 50;
    }
}

string Enemy::toString() const {
    stringstream ss;
    ss << "[Enemy] " << name;
    if (boss) ss << " (BOSS)";
    ss << " | HP: " << health << " | ATK: " << attack;
    return ss.str();
}