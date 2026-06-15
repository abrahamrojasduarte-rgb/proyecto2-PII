//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ITEMMANAGER_H
#define PROYECTOII_ITEMMANAGER_H
#include "Item.h"
#include "Utiles.h"
#include <vector>
#include <cstdlib>
#include <random>

class ItemManager {
private:
    vector<Item<int>> weapons;
    vector<Item<int>> potions;
    mt19937 rng;

public:
    ItemManager();
    void loadFromFile(const string& filename);
    Item<int> getRandomWeapon();
    Item<int> getRandomPotion();
    int getWeaponCount() const;
    int getPotionCount() const;
};


#endif //PROYECTOII_ITEMMANAGER_H