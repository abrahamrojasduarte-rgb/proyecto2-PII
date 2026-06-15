//
// Created by Abraham on 6/11/2026.
//

#include "Inventory.h"
#include <sstream>
Inventory::Iterator::Iterator(const Inventory* inv, int sec, int idx)
    : inventory(inv), section(sec), index(idx) {}

Inventory::Iterator& Inventory::Iterator::operator++() {
    index++;
    if (section == 0 && index >= (int)inventory->weapons.size()) {
        section = 1;
        index = 0;
    }
    return *this;
}

bool Inventory::Iterator::operator!=(const Iterator& other) const {
    return section != other.section || index != other.index;
}

string Inventory::Iterator::operator*() const {
    if (section == 0 && index < (int)inventory->weapons.size()) {
        return "[Weapon] " + inventory->weapons[index].getName()
               + " (+" + to_string(inventory->weapons[index].getValue()) + " ATK)";
    } else if (section == 1 && index < (int)inventory->potions.size()) {
        return "[Potion] " + inventory->potions[index].getName()
               + " (+" + to_string(inventory->potions[index].getValue()) + " HP)";
    }
    return "";
}


Inventory::Inventory() : maxCapacity(10) {}

Inventory::Inventory(int capacity) : maxCapacity(capacity) {}

bool Inventory::addWeapon(const Item<int>& weapon) {
    if (isFull()) return false;
    weapons.push_back(weapon);
    return true;
}

bool Inventory::addPotion(const Item<int>& potion) {
    if (isFull()) return false;
    potions.push_back(potion);
    return true;
}

Item<int> Inventory::getBestWeapon() const {
    if (weapons.empty()) {
        return Item<int>("Fists", 0);
    }
    auto best = max_element(weapons.begin(), weapons.end(),
        [](const Item<int>& a, const Item<int>& b) {
            return a.getValue() < b.getValue();
        });
    return *best;
}

Item<int> Inventory::usePotion() {
    if (potions.empty()) {
        throw runtime_error("No potions available");
    }
    Item<int> potion = potions.back();
    potions.pop_back();
    return potion;
}

bool Inventory::hasPotions() const {
    return !potions.empty();
}

int Inventory::getTotalItems() const {
    return (int)(weapons.size() + potions.size());
}

bool Inventory::isFull() const {
    return getTotalItems() >= maxCapacity;
}

Inventory::Iterator Inventory::begin() const {
    if (!weapons.empty()) {
        return Iterator(this, 0, 0);
    }
    if (!potions.empty()) {
        return Iterator(this, 1, 0);
    }
    return end();
}

Inventory::Iterator Inventory::end() const {
    return Iterator(this, 1, (int)potions.size());
}

string Inventory::toString() const {
    stringstream ss;
    ss << "=== Inventory (" << getTotalItems() << "/" << maxCapacity << ") ===" << endl;
    for (auto it = begin(); it != end(); ++it) {
        ss << "  " << *it << endl;
    }
    return ss.str();
}

ostream& operator<<(ostream& os, const Inventory& inv) {
    os << inv.toString();
    return os;
}