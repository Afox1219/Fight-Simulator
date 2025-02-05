#pragma once
#include "Player.h"
#ifndef CHLORA_H
#define CHLORA_H

class Chlora : public Character {
public:
    Chlora(const std::string& name)
        : Character(name, "whip","5", 80, 30, 40, 25, 5) {}  // Custom health, strength, magic, and agility for Chlora

    // Overridden methods
    void attack(Character& target) override {
        std::cout << name << " attacks with vines, dealing " << strength << " damage!" << std::endl;
        Character::attack(target); // Calls the base class attack
    }

    void Magic1(Character& target) override {
        std::cout << name << " casts a Nature's Fury spell with " << magic << " magic power!" << std::endl;
        Character::Magic1(target); // Calls the base class Magic method
    }

    void displayInfo() const override {
        std::cout << "Chlora Nature Mage: " << name << ", Health: " << health << ", Attack Power: " << strength << ", Weapon: " << weapon << std::endl;
    }
};

#endif // CHLORA_H 
