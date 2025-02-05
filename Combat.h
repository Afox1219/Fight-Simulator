#pragma once
#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Enemy.h"
#include <vector>

class Combat {
public:
    Combat();
    void startBattle(Character* Player, std::vector<Enemy*> enemies, int numEnemies);
    void Player_Choice(Character* Player);
    void Enemy_Choice(Character* Player);
    void endBattle();
private:
    int enemyHealth;
    int numEnemies;
    std::vector<Enemy*> enemies;
};

#endif // COMBAT_H