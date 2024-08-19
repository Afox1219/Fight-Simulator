#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define punch 1
#define feint 2
#define defend 3



int main()
{
	int Player1 = 10;
	int Player_Choice{};
	int Player2;
	int Computer = 10;
	int Computer_Choice;
	int Game_Select;
	int Choice;
	int punching = 3;
	int feinting = 0;
	int defending = 0;
	bool Alive = true;

	do {
	cout << "How many players today" << endl;
	cout << "1.) Ai" << endl;
	cout << "2.) player" << endl;
	cin >> Game_Select;


	
		if (Game_Select == 1)
		{
			while (Alive){
				if(Player1 <= 0|| Computer <= 0) 
				{
					Alive = false;
				}
				cout << "Player 1: " << Player1 << endl;
				cout << "Computer: " << Computer << endl;
				cout << "Choose your attack" << endl;
				cin >> Choice;

				srand((unsigned int)time(NULL));
				Computer_Choice = (rand() % 3) + 1;
				
				if (Player_Choice == 1)
				{
					Computer = Computer - punching;
				}
				if (Player_Choice == 2)
				{
					if (Computer_Choice == 3)
					{
						feinting = 3;
					}
					Computer = Computer - feinting;
				}
				if (Player_Choice == 3)
				{
					Computer = Computer - defending;
				}


				if (Computer_Choice == 1)
				{
					Player1 = Player1 - punching;
				}
				if (Computer_Choice == 2)
				{
					if (Player_Choice == 3)
					{
						feinting = 3;
					}
					Player1 = Player1 - feinting;
				}
				if (Computer_Choice == 3)
				{
					Player1 = Player1 - defending;
				}
			}
		}
		else
		{
			cout << "Option not available" << endl;
		}
	} while (Game_Select != 1);

	if(Player1 <= 0)
	{
		cout << "YOU LOSE!" << endl;
	}
	if (Computer <= 0)
	{
		cout << "YOU WIN!" << endl;
	}


		return 0;
}