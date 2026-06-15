//
// Created by Abraham on 6/6/2026.
//

#include "Room.h"
Room::Room() : roomName("Unknown Room") {}

vector<Enemy>& Room::getEnemies() {
    return enemies;
}

string Room::getRoomName() const {
    return roomName;
}

void Room::setRoomName(const string& name) {
    roomName = name;
}