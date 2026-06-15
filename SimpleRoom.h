//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_SIMPLEROOM_H
#define PROYECTOII_SIMPLEROOM_H
#include "Room.h"
#include "Utiles.h"

class SimpleRoom : public Room {
private:
    vector<string> enemyTypes;

public:
    SimpleRoom(vector<string> types);
    void generateRoom() override;
    string getRoomType() const override;
};


#endif //PROYECTOII_SIMPLEROOM_H