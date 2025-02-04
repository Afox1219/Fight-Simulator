#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<string>
#include <cmath>
#include "Flame.h"
#include "Jolt.h"
#include "Chlora.h"
#include "Divina.h"

using namespace std;

// Global variables for health, etc.
int P_health = 30;
int E_health = 30;
int Weapon = 5;
int Spell = 7;
bool stagger = false;
int choice, choice3;
string Enemy;
string enemy1 = "Flame";
string enemy2 = "Jolt";
string enemy3 = "Chlora";
string enemy4 = "Divina";

// Function Declarations  
int Player_Choice(Character* Player, Character* enemy);
int Enemy_Choice(Character* Player, Character* enemy);

int main() {
    Character* Player = nullptr;
    Character* enemy = nullptr;

    // Character selection for Player
    cout << "Choose your Character \n\n";
    cout << "1. Flame\n";
    cout << "2. Jolt\n";
    cout << "3. Chlora\n";
    cout << "4. Divina\n";
    cin >> choice;

    switch (choice) {
    case 1:
        Player = new Flame("Flame");
        break;
    case 2:
        Player = new Jolt("Jolt");
        break;
    case 3:
        Player = new Chlora("Chlora");
        break;
    case 4:
        Player = new Divina("Divina");
        break;
    default:
        cout << "Invalid choice!\n";
        return 1;
    }

    // Character selection for Enemy
    cout << "Choose your Enemy \n\n";
    cout << "1. Flame\n";
    cout << "2. Jolt\n";
    cout << "3. Chlora\n";
    cout << "4. Divina\n";
    cin >> choice3;

    switch (choice3) {
    case 1:
        enemy = new Flame("Flame");
        Enemy = enemy1;
        break;
    case 2:
        enemy = new Jolt("Jolt");
        Enemy = enemy2;
        break;
    case 3:
        enemy = new Chlora("Chlora");
        Enemy = enemy3;
        break;
    case 4:
        enemy = new Divina("Divina");
        Enemy = enemy4;
        break;
    default:
        cout << "Invalid choice!\n";
        return 1;
    }

    cout << "You chose " << Enemy << " as your enemy\n\n";

    // Game loop
    while (E_health > 0 && P_health > 0) {
        Player_Choice(Player, enemy); // Player's choice of action
        Enemy_Choice(Player, enemy);  // Enemy's random choice

        // Print the health of player and enemy
        cout << "\n\n";
        Player->displayInfo();
        enemy->displayInfo();
        cout << "\n\n";
    }

    if (enemy->getHealth() == 0) {
        cout << "YOU WON!!!\n";
    }
    else if (Player->getHealth() == 0) {
        cout << "YOU LOSE!!!\n";
    }

    return 0;
}

// Function Definitions
int Player_Choice(Character* Player, Character* enemy) {
    cout << "Choose your move \n\n";
    cout << "1. Sword\n";
    cout << "2. Power\n";
    cout << "3. Block\n";
    cin >> choice;

    switch (choice) {
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
            Weapon = 0;
            stagger = true;
            cout << "Your block was successful!\n";
        }
        break;
    default:
        cout << "Invalid move!\n";
        break;
    }

    return 0;
}

int Enemy_Choice(Character* Player, Character* enemy) {
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

    return 0;
}
