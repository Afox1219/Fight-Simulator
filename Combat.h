#pragma once
#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"

class Combat {
public:
    Combat();
    void startBattle(Character* Player, Character* enemy);
    void Player_Choice(Character* Player, Character* enemy);
    void Enemy_Choice(Character* Player, Character* enemy);
    void endBattle();
private:
    int enemyHealth;
};

#endif // COMBAT_H