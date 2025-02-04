#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Character {
protected:
    std::string name;
    std::string weapon;
    int health;
    int strength;
    int agility;
    int magic;

public:
    // Constructor to initialize the character
    Character(std::string name, std::string weapon, int health, int strength, int agility, int magic)
        : name(name), weapon(weapon), health(health), strength(strength), agility(agility), magic(magic) {}

    // Virtual Destructor (useful for inheritance)
    virtual ~Character() {}

    // Getters
    std::string getname() const { return name; }
    std::string getweapon() const { return weapon; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    int getAgility() const { return agility; }
    int getMagic() const { return magic; }

    // Setters
    void setHealth(int h) { health = h; }
    void setStrength(int s) { strength = s; }
    void setAgility(int a) { agility = a; }
    void setMagic(int m) { magic = m; }

    // A virtual method for attack, to be overridden by derived classes
    virtual void attack(Character& target) {
        std::cout << name << " attacks " << target.getname() << " for " << strength << " damage!" << std::endl;
        target.takeDamage(strength);
    }

    virtual void Magic1(Character& target) {
        // Base attack logic (could be generic or you can override in derived classes)
        std::cout << name << " attacks with " << magic << " magic power!" << std::endl;
        target.takeDamage(magic);
    }

    // Method to take damage (reusable for all derived classes)
    virtual void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0; // Prevent negative health
    }

    // Pure virtual method for displaying character info
    virtual void displayInfo() const {
        std::cout << "Character: " << name << ", Weapon: " << weapon << ", Health: " << health << ", Strength: " << strength << ", Agility: " << agility << ", Magic: " << magic << std::endl;
    }
};
