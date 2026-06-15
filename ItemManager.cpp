//
// Created by joaoa on 9/6/2026.
//

#include "ItemManager.h"
#include <fstream>
#include <sstream>


ItemManager::ItemManager() : rng(random_device{}()) {
    loadFromFile("items.txt");
}

void ItemManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        weapons.emplace_back("Iron Sword", 12, "A sturdy iron blade");
        weapons.emplace_back("Steel Axe", 15, "A heavy steel axe");
        weapons.emplace_back("Shadow Dagger", 10, "A swift dark dagger");
        weapons.emplace_back("War Hammer", 18, "A devastating war hammer");
        weapons.emplace_back("Enchanted Staff", 14, "A staff imbued with magic");

        potions.emplace_back("Small Potion", 20, "Restores a small amount of HP");
        potions.emplace_back("Medium Potion", 40, "Restores a moderate amount of HP");
        potions.emplace_back("Large Potion", 60, "Restores a large amount of HP");
        potions.emplace_back("Elixir", 80, "A powerful healing elixir");
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string type, name, valueStr, desc;

        if (getline(ss, type, '|') && getline(ss, name, '|') &&
            getline(ss, valueStr, '|') && getline(ss, desc, '|')) {
            try {
                int value = stoi(valueStr);
                if (type == "weapon") {
                    weapons.emplace_back(name, value, desc);
                } else if (type == "potion") {
                    potions.emplace_back(name, value, desc);
                }
            } catch (const exception&) {
            }
        }
    }
    file.close();
}

Item<int> ItemManager::getRandomWeapon() {
    if (weapons.empty()) {
        return Item<int>("Broken Stick", 5, "A pathetic weapon");
    }
    uniform_int_distribution<> dist(0, (int)weapons.size() - 1);
    return weapons[dist(rng)];
}

Item<int> ItemManager::getRandomPotion() {
    if (potions.empty()) {
        return Item<int>("Dirty Water", 10, "Better than nothing");
    }
    uniform_int_distribution<> dist(0, (int)potions.size() - 1);
    return potions[dist(rng)];
}

int ItemManager::getWeaponCount() const {
    return (int)weapons.size();
}

int ItemManager::getPotionCount() const {
    return (int)potions.size();
}