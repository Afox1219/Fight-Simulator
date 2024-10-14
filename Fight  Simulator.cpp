#include<string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<SFML/Graphics.hpp>
using namespace std;

int P_health = 30;
int E_health = 30;
int Weapon = 5;
int Spell = 7;
int Block = 0;
bool stagger = false;
int Mana = 10;
int Special = 20;
int choice;
int click = 0;
int Player_Choice();
int Enemy_Choice();


int main()
{
   
    

    

    cout << "Choose your Character \n\n";
    cout << "1. Flame\n";
    cout << "2. Jolt\n";
    cout << "3. Chlora\n";
    cout << "4. Divina\n";
    cin >> choice;


    switch (choice)
    {
        case 1: 
            cout << "you chose flame \n";
            break;
        case 2:
            cout << "you chose Jolt \n";
            break;
        case 3:
            cout << "you chose Chlora \n";
            break;
        case 4:
            cout << "you chose Divina \n";
            break;
        default:
            cout << "Invalid choice!\n";
            return 1; // Exit if invalid choice
    }
    


    while(E_health >= 0 && P_health >= 0)
    {
        Weapon = 5;
        Player_Choice();
        Enemy_Choice();

        cout << "Enemy Health" << E_health << "\n";;
        cout << "Player health" << P_health << "\n\n\n\n";
    }
    if (E_health <= 1)
    {
        cout << "YOU WON!!!";
    }
    else if (P_health <= 1)
    {
        cout << "YOU LOSE!!!";
    }


    return 0;
}

int Player_Choice()
{
    
    
    cout << "Choose your move \n\n";
    cout << "1. Sword\n";
    cout << "2. Power\n";
    cout << "3. block\n";
    
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "You hit enemy with your\n\n";
        cout << Weapon;
        E_health = E_health - Weapon;

        stagger = false;
        break;
    case 2:
        cout << "You hit enemy with Sword\n\n";
        E_health = E_health - Spell;

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

    }

    if (stagger)
    {
        cout << "Your block needs time to recover\n\n";
        
    }
    else
    {
        cout << "You can block again \n\n";
    }

    return 0;
}

int Enemy_Choice()
{
    int E_Choice = (1 + rand() % 3);

    cout << E_Choice;
    switch (E_Choice)
    {
    case 1:
        cout << "The enemy hit you with Sword\n\n";
        P_health -= Weapon;
        break;
    case 2:
        cout << "The enemy hit you with Spell\n\n";
        P_health -= Spell;
        break;
    case 3:
        cout << "The enemy tries to block\n\n";
        Weapon = 0;
        break;
    
    default:
        break;
    }


    return 0;
}