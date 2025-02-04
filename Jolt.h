#pragma once
#include "Player.h"
#ifndef JOLT_H
#define JOLT_H

class Jolt : public Character {
public:
    Jolt(const std::string& name)
        : Character(name, "Kanabo", 150, 30, 35, 20) {}  // Custom health, strength, magic, and agility for Jolt

    // Overridden methods
    void attack(Character& target) override {
        std::cout << name << " strikes with "<< weapon <<" using " << strength << " power!" << std::endl;
        Character::attack(target); // Calls the base class attack
    }

    void Magic1(Character& target) override {
        std::cout << name << " casts a Thunderbolt with " << magic << " magic power!" << std::endl;
        Character::Magic1(target); // Calls the base class Magic method
    }

    void displayInfo() const override {
        std::cout << "Jolt (Tank): " << name << ", Health: " << health << ", Attack Power: " << strength << ", Weapon: " << weapon << std::endl;
    }
};

#endif // JOLT_H 
