//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_ENEMYMANAGER_H
#define PROYECTOII_ENEMYMANAGER_H
#include "Utiles.h"
#include "Enemy.h"
class EnemyManager {
public:
    vector<Enemy> loadEnemies();
    Enemy getEnemyByName(string n);
};


#endif //PROYECTOII_ENEMYMANAGER_H