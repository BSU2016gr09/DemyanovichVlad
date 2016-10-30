//игра в кости
#include <iostream>
#include <ctime>
#include <clocale>
void playerThrow(int & playerpoints);
void enemyThrow(int & enemypoints);
void graphics(int value);
using namespace std;
int main() 
{    
	int playerpoints=0, enemypoints=0;
	srand(time(NULL));
	setlocale(LC_ALL,"Russian");
	while (playerpoints <= 50 && enemypoints <= 50)
	{
		cout << "ваши кости:\n";
		playerThrow(playerpoints);
		cout << "кости соперника:\n";
		enemyThrow(enemypoints);
		cout << "ваше число очков: " << playerpoints << "  число очков вашего соперника: " << enemypoints << '\n';
		if (playerpoints >= 50 || enemypoints >= 50) 
		{
			if (playerpoints > enemypoints) cout << "вы победили"; 
				else if (enemypoints > playerpoints) cout << "вы проиграли"; 
					else cout << "ничья";
					cout << '\n';
		}
		system("PAUSE");
	}
}
void playerThrow(int & value)
{
	int i = 0, playerpoints;
	while (i < 2)
	{
		playerpoints = rand() % 6 + 1;
		value += playerpoints;
		graphics(playerpoints);
		i++;
	}
}
void enemyThrow(int & value)
{
	int i = 0, enemypoints;
	while (i < 2)
	{
		enemypoints = rand() % 6 + 1;
		value += enemypoints;
		graphics(enemypoints);
		i++;
	}
}
void graphics(int value)
{
	switch(value)
	{
	case 1: cout << "+---+\n" << "|   |\n" << "| 0 |\n" << "|   |\n" << "+---+\n"; break;
	case 2: cout << "+---+\n" << "|0  |\n" << "|   |\n" << "|  0|\n" << "+---+\n"; break;
	case 3: cout << "+---+\n" << "|0  |\n" << "| 0 |\n" << "|  0|\n" << "+---+\n"; break;
	case 4: cout << "+---+\n" << "|0 0|\n" << "|   |\n" << "|0 0|\n" << "+---+\n"; break;
	case 5: cout << "+---+\n" << "|0 0|\n" << "| 0 |\n" << "|0 0|\n" << "+---+\n"; break;
	case 6: cout << "+---+\n" << "|0 0|\n" << "|0 0|\n" << "|0 0|\n" << "+---+\n"; break;
	}

}

