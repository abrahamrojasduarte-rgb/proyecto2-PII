//
// Created by Abraham on 6/4/2026.
//

#ifndef PROYECTOII_CHARACTERS_H
#define PROYECTOII_CHARACTERS_H
#include "Utiles.h"
#include "Entity.h"
class Ability;
using namespace std;

class Characters : public Entity {
private:
    int weaponBonus = 0;
    Ability* ability;
public:
    Characters();
    Characters(string name, int health, int attack);

    void equipWeapon(int bonus);
    void heal(int amount);
    string toString()const override;
    int getWeaponBonus() const;
    void setAbility(Ability* ability);
    Ability* getAbility() const;
};

#endif //PROYECTOII_CHARACTERS_H