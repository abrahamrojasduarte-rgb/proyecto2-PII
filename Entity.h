//
// Created by Abraham on 6/5/2026.
//

#ifndef PROYECTOII_ENTITY_H
#define PROYECTOII_ENTITY_H
#include <iostream>

using namespace std;
class Entity {
protected:
    string name;
    int health;
    int attack;
    int maxHealth;
public:
    Entity();
    Entity(string name, int health, int attack);

    string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;

    void setName(string name);
    void setHealth(int health);
    void setMaxHealth(int maxHealth);
    void setAttack(int attack);

    virtual ~Entity()=default;
    virtual string toString() const =0;
};


#endif //PROYECTOII_ENTITY_H