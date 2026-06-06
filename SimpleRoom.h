//
// Created by Abraham on 6/6/2026.
//

#ifndef PROYECTOII_SIMPLEROOM_H
#define PROYECTOII_SIMPLEROOM_H
#include "Room.h"
#include "Utiles.h"

class SimpleRoom :public Room{
private:
    string enemyName;
public:
    SimpleRoom(string m);
    void generateRoom() override;
};


#endif //PROYECTOII_SIMPLEROOM_H