#pragma 
#include "Combat.h"
#include <iostream>
using namespace std;

bool stagger = false;
int choice2;
int choice4;

Combat::Combat() {}

void Combat::startBattle(Character* Player, std::vector<Enemy*> enemies,int numEnemies) {
    this->enemies = enemies;

    // Create `numEnemies` of a certain type
    for (const auto& enemy : enemies) {
        enemies.push_back(enemy);  // Add to the vector
    }



    while (!enemies.empty() && Player->getHealth() >= 0) {
        Player_Choice(Player);
        Enemy_Choice(Player);

        
        cout << "\n\n";
        Player->displayInfo();
        
        
    }
    if (enemies.empty()) {
        cout << "YOU WON!!!\n";
    }
    else if (Player->getHealth() < 0) {
        cout << "YOU LOSE!!!\n";
    }

    endBattle();
    }

void Combat::Player_Choice(Character* Player) {
    cout << "Choose your move \n\n";
    cout << "1. Sword\n";
    cout << "2. Power\n";
    cout << "3. Block\n";
    cin >> choice2;
    cout << "Which Enemy? (Enter number 1 - " << enemies.size() << ")\n\n";
    cin >> choice4;  // Get enemy selection from the user

    if (choice4 < 1 || choice4 > enemies.size()) {
        cout << "Invalid choice!\n";
        return;
    }

    Enemy* chosenEnemy = enemies[choice4 - 1]; // Pick the chosen enemy

    switch (choice2) {
    case 1:
        Player->attack(*chosenEnemy);
        stagger = false;
        break;
    case 2:
        cout << "You hit enemy with Power\n";
        Player->Magic1(*chosenEnemy);
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

void Combat::Enemy_Choice(Character* Player) {
    for (auto it = enemies.begin(); it != enemies.end();) {
        Enemy* enemy = *it;  // Get the actual enemy object
        enemy->displayInfo();

        if (enemy->getHealth() <= 0) {
            it = enemies.erase(it); // Remove dead enemies from vector
            continue; // Move to the next enemy
        }

        int E_Choice = (1 + rand() % 3);

        switch (E_Choice) {
        case 1:
            enemy->attack(*Player);
            break;
        case 2:
            enemy->Magic1(*Player);
            break;
        case 3:
            cout << enemy->getname() << " tries to block\n";
            break;
        default:
            break;
        }

        ++it; // Move to next enemy
    }
}


void Combat::endBattle() {

 
}