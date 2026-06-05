//
// Created by Abraham on 6/5/2026.
//

#include "Entity.h"
Entity::Entity() {
    name = "";
    health = 0;
    attack = 0;
}

Entity::Entity(string name, int health, int attack) {
    this->name = name;
    this->health = health;
    this->attack = attack;
}

string Entity::getName() const {
    return name;
}

int Entity::getHealth() const {
    return health;
}

int Entity::getAttack() const {
    return attack;
}

void Entity::setName(string name) {
    this->name = name;
}

void Entity::setHealth(int health) {
    this->health = health;
}

void Entity::setAttack(int attack) {
    this->attack = attack;
}