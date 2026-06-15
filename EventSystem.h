//
// Created by Abraham on 6/11/2026.
//

#ifndef PROYECTOII_EVENTSYSTEM_H
#define PROYECTOII_EVENTSYSTEM_H
#include <string>
#include <vector>
#include <functional>
#include <random>
#include <iostream>

using namespace std;

class Characters;

struct GameEvent {
    string name;
    string description;
    enum Type { TRAP, TREASURE, REST, MYSTERY };
    Type type;
    int effectValue;

    GameEvent();
    GameEvent(string name, string desc, Type type, int value);
    string getTypeName() const;
};


class EventSystem {
private:
    vector<GameEvent> events;
    mt19937 rng;
    int eventChancePercent;
public:
    EventSystem();
    void loadEvents(const string& filename);
    bool shouldTriggerEvent();
    GameEvent getRandomEvent();
    void applyEvent(const GameEvent& event, Characters& player);
    int getEventCount() const;
};
#endif //PROYECTOII_EVENTSYSTEM_H