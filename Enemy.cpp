//
// Created by Abraham on 6/5/2026.
//

#include "Enemy.h"
Enemy::Enemy() : Entity(){}

Enemy::Enemy(string name, int health, int attack)
    : Entity(name, health, attack){}


string Enemy::toString() const {
    stringstream ss;
    ss << "\nEnemy\n"
     << "Name: " << name << endl
     << "Health: " << health << endl
     << "Attack: " << attack << endl;
    return ss.str();
}