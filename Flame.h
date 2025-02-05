#pragma once
#include "Player.h"
#ifndef FLAME_H
#define FLAME_H

class Flame : public Character {
public:
    Flame(const std::string& name)
        : Character(name, "5" , "sword", 100, 30, 30, 15, 5) {}  // Custom health, strength, magic, and agility for Flame

    // Overridden methods
    void attack(Character& target) override {
        std::cout << name << " swings their sword with " << strength << " power!" << std::endl;
        Character::attack(target); // Calls the base class attack
    }

    void Magic1(Character& target) override {
        std::cout << name << " Fire Blasts with " << magic << " power!" << std::endl;
        Character::Magic1(target); // Calls the base class Magic method
    }

    void displayInfo() const override {
        std::cout << "Flame Fighter: " << name << ", Health: " << health << ", Attack Power: " << strength << ", Weapon: " << weapon << std::endl;
    }
};

#endif // FLAME_H 
