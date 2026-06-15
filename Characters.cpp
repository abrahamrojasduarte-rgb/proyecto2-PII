//
// Created by Abraham on 6/4/2026.
//

#include "Characters.h"

#include <iomanip>

Characters::Characters() : Entity(), ability(nullptr), characterClass("Adventurer") {}

Characters::Characters(string name, int health, int attack, string charClass)
    : Entity(name, health, attack), ability(nullptr), characterClass(charClass) {}

void Characters::equipWeapon(int bonus) {
    if (bonus <= weaponBonus) {
        return;
    }
    attack -= weaponBonus;
    weaponBonus = bonus;
    attack += weaponBonus;
}

void Characters::heal(int amount) {
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

void Characters::gainExperience(int amount) {
    experience += amount;
    while (experience >= level * 50) {
        experience -= level * 50;
        level++;
        maxHealth += 10;
        health += 10;
        attack += 2;
        cout << "  *** LEVEL UP! Now level " << level << " ***" << endl;
        cout << "  +10 Max HP, +2 ATK" << endl;
    }
}

int Characters::getWeaponBonus() const {
    return weaponBonus;
}

Ability* Characters::getAbility() const {
    return ability;
}

Inventory& Characters::getInventory() {
    return inventory;
}

int Characters::getExperience() const {
    return experience;
}

int Characters::getLevel() const {
    return level;
}

string Characters::getCharacterClass() const {
    return characterClass;
}

void Characters::setAbility(Ability* ability) {
    this->ability = ability;
}

Characters& Characters::operator+=(int healAmount) {
    heal(healAmount);
    return *this;
}

Characters& Characters::operator-=(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    return *this;
}

string Characters::toString() const {
    stringstream ss;
    ss << "" << left << setw(24) << name << " |" << endl;
    ss << "Class:  " << left << setw(16) << characterClass << " |" << endl;
    ss << "Level:  " << left << setw(16) << level << " |" << endl;
    ss << "Health: " << left << setw(7) << health << "/ " << setw(6) << maxHealth << "  |" << endl;
    ss << "Attack: " << left << setw(16) << attack << " |" << endl;
    ss << "Weapon: +" << left << setw(15) << weaponBonus << " |" << endl;
    ss << "XP:     " << left << setw(16) << experience << " |" << endl;
    return ss.str();
}

Characters::~Characters() {}