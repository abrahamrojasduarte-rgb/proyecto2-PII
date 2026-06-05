//
// Created by Abraham on 6/5/2026.
//

#include "Enemy.h"
Enemy::Enemy() : Entity(), boss(false) {}

Enemy::Enemy(string name, int health, int attack, bool boss)
    : Entity(name, health, attack), boss(boss) {}

bool Enemy::isBoss() const {
    return boss;
}

string Enemy::toString() const {
    stringstream ss;
    ss << "\nEnemy\n"
     << "Name: " << name << endl
     << "Health: " << health << endl
     << "Attack: " << attack << endl
     << "Boss: " << (boss ? "Yes" : "No") << endl;
    return ss.str();
}