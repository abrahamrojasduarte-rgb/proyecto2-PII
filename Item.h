//
// Created by joaoa on 9/6/2026.
//

#ifndef PROYECTOII_ITEM_H
#define PROYECTOII_ITEM_H
#include <string>
using namespace std;

template <typename T>
class Item {
private:
    string name;
    T value;

public:
    Item(string name, T value) : name(name), value(value) {}

    string getName() { return name; }
    T getValue() { return value; }
};


#endif //PROYECTOII_ITEM_H