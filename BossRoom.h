//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_BOSSROOM_H
#define PROYECTOII_BOSSROOM_H

#include "Room.h"

class BossRoom : public Room {
private:
    string bossName;

public:
    BossRoom(string bossName);
    void generateRoom() override;
};

#endif //PROYECTOII_BOSSROOM_H