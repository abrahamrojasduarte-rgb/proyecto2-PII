//
// Created by joaoa on 9/6/2026.
//

#include "ItemManager.h"

Item<int> ItemManager::getRandomWeapon() {
    vector<Item<int>> weapons = {
        Item<int>("Sword", 15),
        Item<int>("Axe", 10),
        Item<int>("Dagger", 8),
    };

    return weapons[rand() % weapons.size()];
}

Item<int> ItemManager::getRandomPotion() {
    vector<Item<int>> potions = {
        Item<int>("Small Potion", 20),
        Item<int>("Medium Potion", 40),
        Item<int>("Big Potion", 60)
    };

    return potions[rand() % potions.size()];
}
