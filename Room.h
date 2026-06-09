//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_ROOM_H
#define PROYECTOII_ROOM_H
#include "Utiles.h"
#include "Enemy.h"
using namespace std;

class Room {
protected:
    vector<Enemy> enemies;
public:
    virtual ~Room()=default;
    virtual void generateRoom()=0;
    vector<Enemy>& getEnemies();
};


#endif //PROYECTOII_ROOM_H