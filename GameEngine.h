//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_GAMEENGINE_H
#define PROYECTOII_GAMEENGINE_H
#include "Utiles.h"
#include "Characters.h"
#include "Level.h"
#include "Logger.h"
#include "CombatSystem.h"
#include "ItemManager.h"
#include "EventSystem.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class GameEngine {
private:
    Characters player;
    vector<Level*> levels;
    Logger logger;
    ItemManager itemManager;
    EventSystem eventSystem;

    int enemiesKilled = 0;
    int bossesKilled = 0;
    int totalDamageDealt = 0;
    int totalDamageTaken = 0;
    int totalTurns = 0;
    int itemsCollected = 0;
    int eventsTriggered = 0;
    vector<int> killsPerLevel;
    vector<string> bossesDefeated;

    void processItemDrop(const Enemy& enemy);
    void processRoomEvent();

public:
    GameEngine(Characters player);
    ~GameEngine();

    void setupLevels();
    void startGame();
    void generateReport();
};

#endif //PROYECTOII_GAMEENGINE_H