#pragma 
#include "Combat.h"
#include <iostream>
using namespace std;

bool stagger = false;
int choice2;

Combat::Combat() {}

void Combat::startBattle(Character* Player, Character* enemy) {
    while (enemy->getHealth() > 0 && Player->getHealth() > 0) {
        Player_Choice(Player, enemy); // Player's choice of action
        Enemy_Choice(Player, enemy);  // Enemy's random choice

        // Print the health of player and enemy
        cout << "\n\n";
        Player->displayInfo();
        enemy->displayInfo();
        cout << "\n\n";
    }

    if (enemy->getHealth() > 0) {
        cout << "YOU WON!!!\n";
    }
    else if (Player->getHealth() > 0) {
        cout << "YOU LOSE!!!\n";
    }

    endBattle();
    }

void Combat::Player_Choice(Character* Player, Character* enemy) {
        cout << "Choose your move \n\n";
        cout << "1. Sword\n";
        cout << "2. Power\n";
        cout << "3. Block\n";
        cin >> choice2;

        switch (choice2) {
        case 1:


            Player->attack(*enemy);
            stagger = false;
            break;
        case 2:
            cout << "You hit enemy with Power\n";

            Player->Magic1(*enemy);
            stagger = false;
            break;
        case 3:
            cout << "You try to block the attack.\n\n";
            if (stagger) {
                cout << "Your block was broken; you can't block right now!\n\n";
            }
            else {
                stagger = true;
                cout << "Your block was successful!\n";
            }
            break;
        default:
            cout << "Invalid move!\n";
            break;
        }

    }

void Combat::Enemy_Choice(Character* Player, Character* enemy) {
    int E_Choice = (1 + rand() % 3); // Random enemy move

    switch (E_Choice) {
    case 1:
        enemy->attack(*Player);

        break;
    case 2:
        enemy->Magic1(*Player);
        break;
    case 3:
        cout << enemy << " tries to block\n";
        break;
    default:
        break;
    }

}

void Combat::endBattle() {

 
}