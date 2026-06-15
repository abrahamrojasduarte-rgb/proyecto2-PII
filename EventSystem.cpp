//
// Created by Abraham on 6/11/2026.
//

#include "EventSystem.h"
#include "EventSystem.h"
#include "Characters.h"
#include <fstream>
#include <sstream>


GameEvent::GameEvent() : name(""), description(""), type(MYSTERY), effectValue(0) {}

GameEvent::GameEvent(string name, string desc, Type type, int value)
    : name(name), description(desc), type(type), effectValue(value) {}

string GameEvent::getTypeName() const {
    switch (type) {
        case TRAP: return "Trap";
        case TREASURE: return "Treasure";
        case REST: return "Rest";
        case MYSTERY: return "Mystery";
        default: return "Unknown";
    }
}


EventSystem::EventSystem() : rng(random_device{}()), eventChancePercent(30) {}

void EventSystem::loadEvents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open events file: " + filename);
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string name, description;
        int typeInt, value;

        if (getline(ss, name, '|') && getline(ss, description, '|')) {
            string typeStr, valueStr;
            if (getline(ss, typeStr, '|') && getline(ss, valueStr, '|')) {
                try {
                    typeInt = stoi(typeStr);
                    value = stoi(valueStr);
                    GameEvent::Type eventType = static_cast<GameEvent::Type>(typeInt);
                    events.emplace_back(name, description, eventType, value);
                } catch (const exception&) {
                    continue;
                }
            }
        }
    }
    file.close();
}

bool EventSystem::shouldTriggerEvent() {
    uniform_int_distribution<> dist(1, 100);
    return dist(rng) <= eventChancePercent;
}

GameEvent EventSystem::getRandomEvent() {
    if (events.empty()) {
        return GameEvent("Nothing", "Nothing happens.", GameEvent::MYSTERY, 0);
    }
    uniform_int_distribution<> dist(0, (int)events.size() - 1);
    return events[dist(rng)];
}

void EventSystem::applyEvent(const GameEvent& event, Characters& player) {
    switch (event.type) {
        case GameEvent::TRAP:
            player.setHealth(player.getHealth() - event.effectValue);
            cout << "  [TRAP] " << event.description << " (-" << event.effectValue << " HP)" << endl;
            break;
        case GameEvent::TREASURE:
            player.setAttack(player.getAttack() + event.effectValue);
            cout << "  [TREASURE] " << event.description << " (+" << event.effectValue << " ATK)" << endl;
            break;
        case GameEvent::REST:
            player.heal(event.effectValue);
            cout << "  [REST] " << event.description << " (+" << event.effectValue << " HP)" << endl;
            break;
        case GameEvent::MYSTERY:
            if (event.effectValue > 0) {
                player.heal(event.effectValue);
                cout << "  [MYSTERY] " << event.description << " (+" << event.effectValue << " HP)" << endl;
            } else {
                player.setHealth(player.getHealth() + event.effectValue);
                cout << "  [MYSTERY] " << event.description << " (" << event.effectValue << " HP)" << endl;
            }
            break;
    }
}

int EventSystem::getEventCount() const {
    return (int)events.size();
}