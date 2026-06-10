//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_GAMEENGINE_H
#define PROYECTOII_GAMEENGINE_H
#include "Characters.h"
#include "Level.h"
#include "Logger.h"
#include "CombatSystem.h"
#include "ItemManager.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class GameEngine {
private:
    Characters player;
    vector<Level*> levels;
    Logger logger;

    int enemiesKilled = 0;
    int skeletonsKilled = 0;
    int bossesKilled = 0;

public:
    GameEngine(Characters player);
    void setupLevels();
    void startGame();
    void generateReport();
};

#endif //PROYECTOII_GAMEENGINE_H