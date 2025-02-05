#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include "Flame.h"
#include "Jolt.h"
#include "Chlora.h"
#include "Divina.h"
#include "Combat.h"

using namespace std;

// Global variables for health, etc.
string Enemy;
string enemy1 = "Flame";
string enemy2 = "Jolt";
string enemy3 = "Chlora";
string enemy4 = "Divina";
int choice;
int choice3;

int main() {
    Character* Player = nullptr;
    Character* enemy = nullptr;

    // Character selection for Player
    cout << "Who Would You Like To Play As? \n\n";
    cout << "1. The Immortal Pyromaniac: Flame\n";
    cout << "2. The Envious Raijun: Jolt\n";
    cout << "3. Nature's child: Chlora\n";
    cout << "4. The Egotistical Angel: Divina\n";
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

    Combat combat;
    combat.startBattle(Player, enemy);

    delete Player;
    return 0;
}
