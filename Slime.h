#include "Enemy.h"
#include <ctime>
#include <vector>
#include <cstdlib>
#ifndef SLIME_H
#define SLIME_H

class Slime : public Enemy {
public:    
    Slime(const std::string& name)
        : Enemy(name, "Body","level", 50, 10, 30, 15, 1) {}

    void attack(Character& target) override {
        std::cout << name << " Launches Themselves At You With " << strength << " power!" << std::endl;
        Enemy::attack(target); // Calls the base class attack
    }

        void displayInfo() const override{
        std::cout << " Enemy: " << name << ", Health: " << health << ", Attack Power: " << strength << ", Weapon: " << weapon << std::endl;
    }


};



#endif