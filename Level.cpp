//
// Created by joaoa on 8/6/2026.
//

#include "Level.h"

Level::Level() {
}

Level::~Level() {
    for (Room* room : rooms) {
        delete room;
    }
}

void Level::setupLevel() {
    rooms.clear();

    for (int i = 0; i < 5; i++) {
        rooms.push_back(new SimpleRoom("Skeleton"));
    }
    rooms.push_back(new BossRoom("SkeletonKing"));
}

vector<Room *>& Level::getRooms() {
    return rooms;
}