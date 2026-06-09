//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_LEVEL_H
#define PROYECTOII_LEVEL_H
#include "Room.h"
#include "SimpleRoom.h"
#include "BossRoom.h"
#include <vector>
using namespace std;

class Level {
private:
    vector<Room *> rooms;

public:
    Level();
    ~Level();
    void setupLevel();
    vector<Room *>& getRooms();
};


#endif //PROYECTOII_LEVEL_H