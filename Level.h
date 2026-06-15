//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_LEVEL_H
#define PROYECTOII_LEVEL_H
#include "Room.h"
#include "SimpleRoom.h"
#include "BossRoom.h"
#include <vector>
#include <memory>

using namespace std;

class Level {
private:
    vector<Room*> rooms;
    string levelName;
    int levelNumber;

public:
    Level(int number = 1);
    ~Level();

    void setupLevel(const vector<string>& enemyTypes, const string& bossName, int roomCount = 5);
    vector<Room*>& getRooms();
    string getLevelName() const;
    int getLevelNumber() const;
    int getRoomCount() const;
};


#endif //PROYECTOII_LEVEL_H