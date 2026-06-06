//
// Created by Abraham on 6/5/2026.
//

#ifndef PROYECTOII_ENEMY_H
#define PROYECTOII_ENEMY_H
#include "Utiles.h"
class Enemy : public Entity {
private:
    bool boss;

public:
    Enemy();
    Enemy(string name, int health, int attack);
    string toString() const override;
};
#endif //PROYECTOII_ENEMY_H