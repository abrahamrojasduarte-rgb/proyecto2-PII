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
    this->maxHealth = health;
    this->attack = attack;
}

string Entity::getName() const {
    return name;
}

int Entity::getHealth() const {
    return health;
}

int Entity::getMaxHealth() const {
    return maxHealth;
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

void Entity::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}

void Entity::setAttack(int attack) {
    this->attack = attack;
}

bool Entity::isAlive() const {
    return health > 0;
}

bool Entity::operator==(const Entity& other) const {
    return name == other.name && health == other.health && attack == other.attack;
}

bool Entity::operator<(const Entity& other) const {
    return health < other.health;
}

bool Entity::operator>(const Entity& other) const {
    return health > other.health;
}