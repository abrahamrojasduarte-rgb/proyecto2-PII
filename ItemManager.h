//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ITEMMANAGER_H
#define PROYECTOII_ITEMMANAGER_H
#include "Item.h"
#include <vector>
#include <cstdlib>

class ItemManager {
    public:
    Item<int> getRandomWeapon();
    Item<int> getRandomPotion();
};


#endif //PROYECTOII_ITEMMANAGER_H