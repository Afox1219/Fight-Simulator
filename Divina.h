#pragma once
#include "Player.h"
#ifndef DIVINA_H
#define DIVINA_H

class Divina : public Character {
public:
    Divina(const std::string& name)
        : Character(name, "axe","5", 90, 40, 35, 30, 5) {}  // Custom health, strength, magic, and agility for Divina

    // Overridden methods
    void attack(Character& target) override {
        std::cout << name << " Slams an axe with" << strength << " power!" << std::endl;
        Character::attack(target); // Calls the base class attack
    }

    void Magic1(Character& target) override {
        std::cout << name << " casts a Healing Light spell with " << magic << " magic power!" << std::endl;
        Character::Magic1(target); // Calls the base class Magic method
    }

    void displayInfo() const override {
        std::cout << "Divina Archer: " << name << ", Health: " << health << ", Attack Power: " << strength << ", Weapon: " << weapon << std::endl;
    }
};

#endif // DIVINA_H 
