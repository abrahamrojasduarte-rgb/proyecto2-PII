//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ITEM_H
#define PROYECTOII_ITEM_H
#include "Utiles.h"
#include <string>
using namespace std;

template <typename T>
class Item {
private:
    string name;
    T value;
    string description;

public:
    Item() : name(""), value(T()), description("") {}
    Item(string name, T value) : name(name), value(value), description("") {}
    Item(string name, T value, string desc) : name(name), value(value), description(desc) {}

    string getName() const { return name; }
    T getValue() const { return value; }
    string getDescription() const { return description; }

    bool operator==(const Item<T>& other) const {
        return name == other.name && value == other.value;
    }

    bool operator>(const Item<T>& other) const {
        return value > other.value;
    }

    bool operator<(const Item<T>& other) const {
        return value < other.value;
    }

    friend ostream& operator<<(ostream& os, const Item<T>& item) {
        os << item.name << " (value: " << item.value << ")";
        if (!item.description.empty()) {
            os << " - " << item.description;
        }
        return os;
    }
};


#endif //PROYECTOII_ITEM_H