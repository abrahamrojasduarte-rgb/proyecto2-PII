//
// Created by Abraham on 6/4/2026.
//

#include "Characters.h"

Character::Character() :Entity(){
}

Character::Character(string name, int health, int attack) :Entity(name,health,attack){
}

string Character::toString() const {
    stringstream ss;
    ss << "Name: "<<this->name
    <<"\nHealth: "<<this->health
    <<"\nAttack: "<<this->getAttack()<<"\n";
    return ss.str();
}
