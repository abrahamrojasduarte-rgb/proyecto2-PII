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
    string roomName;

public:
    Room();
    virtual ~Room() = default;
    virtual void generateRoom() = 0;
    virtual string getRoomType() const = 0;

    vector<Enemy>& getEnemies();
    string getRoomName() const;
    void setRoomName(const string& name);
};


#endif //PROYECTOII_ROOM_H