#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "Player.h"

class Enemy : public Character {
protected:
    bool Dead = false;


public:

    // Constructor to initialize the character
    Enemy(std::string name,std::string weapon,std::string lvl, int health, int strength, int agility, int magic, int level)
        : Character(name, weapon, lvl, health, strength, agility, magic, level) { }  // Pass arguments to the base class constructor

    // Virtual Destructor (useful for inheritance)
    virtual ~Enemy() {}

    // Getters
    std::string getname() const { return name; }
    std::string getweapon() const { return weapon; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    int getAgility() const { return agility; }
    int getMagic() const { return magic; }
    int getLevel() const { return level; }

    // Setters
    void setHealth(int h) { health = h; }
    void setStrength(int s) { strength = s; }
    void setAgility(int a) { agility = a; }
    void setMagic(int m) { magic = m; }
    void setLevel(int l) { level = l; }

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
    virtual void Death(){
        if(health = 0)
        {
            Dead = true;
        }
    }

    std::vector<Enemy*> multiply(int count) {
        std::vector<Enemy*> enemies;
        for (int i = 0; i < count; ++i) {
            enemies.push_back(new Enemy(name + " " + std::to_string(i + 1), weapon,lvl, health, strength, agility, magic, level));
        }
        return enemies;  // Return the vector of enemies
    }

    // Pure virtual method for displaying character info
    virtual void displayInfo() const {
        std::cout << "Character: " << name << ", Weapon: " << weapon << ", Health: " << health << ", Strength: " << strength << ", Agility: " << agility << ", Magic: " << magic << std::endl;
    }
};