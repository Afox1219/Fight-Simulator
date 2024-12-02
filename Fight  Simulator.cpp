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
int choice2;
int click = 0;
int Player_Choice();
int Enemy_Choice();

char Weapon_choice;
char Element;
char Name;

string Enemy;
string enemy1 = "Flame";
string enemy2 = "Jolt";
string enemy3 = "Chlora";
string enemy4 = "Divina";

int main()
{
   
    string Name;
    string name1 = "Flame";
    string name2 = "Jolt";
    string name3 = "Chlora";
    string name4 = "Divina";

    cout << "Choose your Character \n\n";
    cout << "1. Flame\n";
    cout << "2. Jolt\n";
    cout << "3. Chlora\n";
    cout << "4. Divina\n";
    cin >> choice;


    switch (choice)
    {
        case 1: 
            cout << "you chose flame \n\n";
            Name = name1;
            cout << "Choose your Enemy \n\n";
            cout << "2. Jolt\n";
            cout << "3. Chlora\n";
            cout << "4. Divina\n";
            cin >> choice2;
            
            break;
        case 2:
            cout << "you chose Jolt \n\n";
            Name = name2;
            cout << "Choose your Enemy \n\n";
            cout << "1. Flame\n";
            cout << "3. Chlora\n";
            cout << "4. Divina\n";
            cin >> choice2;

            break;
        case 3:
            cout << "you chose Chlora \n\n";
            Name = name3;
            cout << "Choose your Enemy \n\n";
            cout << "1. Flame\n";
            cout << "2. Jolt\n";
            cout << "4. Divina\n";
            cin >> choice2;

            break;
        case 4:
            cout << "you chose Divina \n\n";
            Name = name4;
            cout << "Choose your Enemy \n\n";
            cout << "1. Flame\n";
            cout << "2. Jolt\n";
            cout << "3. Chlora\n";
            cin >> choice2;

            break;
        default:
            cout << "Invalid choice!\n";
            return 1; // Exit if invalid choice
    }
    

    switch (choice2)
    {
    case 1:
        Enemy = enemy1;
        break;
    case 2:
        Enemy = enemy2;
        break;
    case 3:
        Enemy = enemy3;
        break;
    case 4:
        Enemy = enemy4;
        break;
    default:
        cout << "Invalid choice!\n";
        return 1; // Exit if invalid choice
    }
 
    cout << "You Chose " << Enemy << " As Your Enemy\n\n";


    while(E_health >= 0 && P_health >= 0)
    {
        Weapon = 5;
        Player_Choice();
        Enemy_Choice();

        cout << Enemy <<": " << E_health << "\n";;
        cout << Name <<": " << P_health << "\n\n\n\n";
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
 
    
    //Chooses Weapon//
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
    case 3:  //Checks if you are able to block//
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
    int E_Choice = (1 + rand() % 3); //Allows the enemy to decide what move they want to use//

    switch (E_Choice)
    {
    case 1:
        cout << Enemy << " hit you with Sword\n\n";
        P_health -= Weapon;
        break;
    case 2:
        cout << Enemy << " hit you with Spell\n\n";
        P_health -= Spell;
        break;
    case 3:
        cout << Enemy << " tries to block\n\n";
        Weapon = 0;
        break;
    
    default:
        break;
    }


    return 0;
}