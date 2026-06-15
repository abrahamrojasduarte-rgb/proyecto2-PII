//
// Created by Abraham on 6/11/2026.
//

#ifndef PROYECTOII_INVENTORY_H
#define PROYECTOII_INVENTORY_H
#include "Item.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Inventory {
private:
    vector<Item<int>> weapons;
    vector<Item<int>> potions;
    int maxCapacity;

public:
    class Iterator {
    private:
        const Inventory* inventory;
        int section;
        int index;

    public:
        Iterator(const Inventory* inv, int sec, int idx);
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
        string operator*() const;
    };

    Inventory();
    explicit Inventory(int capacity);

    bool addWeapon(const Item<int>& weapon);
    bool addPotion(const Item<int>& potion);
    Item<int> getBestWeapon() const;
    Item<int> usePotion();
    bool hasPotions() const;
    int getTotalItems() const;
    bool isFull() const;

    Iterator begin() const;
    Iterator end() const;

    string toString() const;
    friend ostream& operator<<(ostream& os, const Inventory& inv);
};
#endif //PROYECTOII_INVENTORY_H