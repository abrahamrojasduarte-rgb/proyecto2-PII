//
// Created by Abraham on 6/4/2026.
//

#ifndef PROYECTOII_CHARACTERS_H
#define PROYECTOII_CHARACTERS_H
#include "Utiles.h"
#include "Entity.h"
#include "Inventory.h"
class Ability;
using namespace std;

class Characters : public Entity {
private:
    int weaponBonus = 0;
    Ability* ability;
    Inventory inventory;
    int experience = 0;
    int level = 1;
    string characterClass;

public:
    Characters();
    Characters(string name, int health, int attack, string charClass = "Adventurer");

    void equipWeapon(int bonus);
    void heal(int amount);
    void gainExperience(int amount);

    int getWeaponBonus() const;
    Ability* getAbility() const;
    Inventory& getInventory();
    int getExperience() const;
    int getLevel() const;
    string getCharacterClass() const;

    void setAbility(Ability* ability);

    Characters& operator+=(int healAmount);
    Characters& operator-=(int damage);

    string toString() const override;

    ~Characters() override;
};

#endif //PROYECTOII_CHARACTERS_H