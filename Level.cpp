//
// Created by joaoa on 8/6/2026.
//

#include "Level.h"

Level::Level(int number) : levelNumber(number) {
    levelName = "Level " + to_string(number);
}

Level::~Level() {
    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();
}

void Level::setupLevel(const vector<string>& enemyTypes, const string& bossName, int roomCount) {
    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();

    for (int i = 0; i < roomCount; i++) {
        rooms.push_back(new SimpleRoom(enemyTypes));
    }

    rooms.push_back(new BossRoom(bossName));
}

vector<Room*>& Level::getRooms() {
    return rooms;
}

string Level::getLevelName() const {
    return levelName;
}

int Level::getLevelNumber() const {
    return levelNumber;
}

int Level::getRoomCount() const {
    return (int)rooms.size();
}