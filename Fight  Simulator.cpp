#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include "Flame.h"
#include "Jolt.h"
#include "Chlora.h"
#include "Divina.h"
#include "player.h"
#include "Combat.h"
#include "Slime.h"
#include "Exploration.h"

using namespace std;

// Choosing Character, etc.
string Creature;
string Creature2;
string Creature3;
string enemy1 = "Flame";
string enemy2 = "Jolt";
string enemy3 = "Chlora";
string enemy4 = "Divina";
int choice;
int choice3;
int numEnemies;


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Fiery Flame");


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        Exploration exploration;
        Character character;

        window.clear();
        exploration.draw(window);
        character.draw(window);
        window.display();


    Character* Player = nullptr;
    Enemy* bad = nullptr;
   
    std::vector<Enemy*> enemies;


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
    cout << "1. Slime\n";
    cout << "2. Spider\n";
    cout << "3. Skeleton\n";
    cout << "4. Ghoul\n";
    cin >> choice3;

    switch (choice3) {
    case 1:
        bad = new Slime("Bad Slime");
        std::cout << "You chose ";
        bad->displayInfo();

        
        std::cout << "How many slimes do you want to create? ";
        std::cin >> numEnemies;

        // Now multiply slimes
        enemies = bad->multiply(numEnemies);

        // Display the multiplied slimes
        for (const auto& enemy : enemies) {
            enemy->displayInfo();  // Display each slime's info
        }
        break;
    default:
        cout << "Invalid choice!\n";
        return 1;
    }

    

    Combat combat;
    combat.startBattle(Player, enemies, numEnemies);
    delete Player;
    for (auto enemy : enemies) {
        delete enemy;
    }

    
    }


    return 0;
}
