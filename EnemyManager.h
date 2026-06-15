//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_ENEMYMANAGER_H
#define PROYECTOII_ENEMYMANAGER_H
#include "Utiles.h"
#include "Enemy.h"
class EnemyManager {
private:
    vector<Enemy> enemies;
    bool loaded;

public:
    EnemyManager();
    void loadFromFile(const string& filename);
    vector<Enemy> getEnemies() const;
    Enemy getEnemyByName(const string& targetName);
    int getEnemyCount() const;
};


#endif //PROYECTOII_ENEMYMANAGER_H