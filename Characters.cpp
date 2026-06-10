//
// Created by Abraham on 6/4/2026.
//

#include "Characters.h"

Characters::Characters() :Entity(){
}

Characters::Characters(string name, int health, int attack) :Entity(name,health,attack){
}

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

string Characters::toString() const {
    stringstream ss;
    ss << "Name: "<< name
    <<"\nHealth: "<< health
    <<"\nAttack: "<< attack<<"\n";
    return ss.str();
}

int Characters::getWeaponBonus() const {
    return weaponBonus;
}

void Characters::setAbility(Ability* ability) {
    this->ability = ability;
}

Ability* Characters::getAbility() const{
    return ability;
}