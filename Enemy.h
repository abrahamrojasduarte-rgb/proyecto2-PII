//
// Created by Abraham on 6/5/2026.
//

#ifndef PROYECTOII_ENEMY_H
#define PROYECTOII_ENEMY_H
#include "Utiles.h"
#include "Entity.h"
class Enemy : public Entity {
private:
    bool boss;
    int expReward;

public:
    Enemy();
    Enemy(string name, int health, int attack, bool isBoss = false);

    bool isBoss() const;
    int getExpReward() const;
    void setBoss(bool isBoss);

    string toString() const override;
};
#endif //PROYECTOII_ENEMY_H