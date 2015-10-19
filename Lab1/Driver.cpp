#include <iostream>

#include "Driver.h"
#include "minesweeper.h"

using namespace std;
enum choice
{
	b, i, e, q
};

void main()
{
	menu();
	
	//minesweeper newGame(b);
}

void menu()
{
	char c = b;
	
	choice selection;

	cout << "Welcome to minesweeper!" << endl;

	
	while (c != 'q')
	{
		cout << "Please make a selection: " << endl;

		cout << "Enter b for beginner level game " << endl;
		cout << "Enter i for intermediate level game " << endl;
		cout << "Enter e for expert level game " << endl;
		cout << "Enter q to quit " << endl;

		cin >> c;

		if (c == 'b')
			selection = b;
		else if (c == 'i')
			selection = i;
		else if (c == 'e')
			selection = e;
		else if (c == 'q')
			selection = q;
		else
			throw("Selection incorrect, please choose b, i, e, or q");


		switch (selection)
		{
			case b :
			{
				cout << "Lets play beginner" << endl;
				easyGame();
				break;
			}
			case i:
			{
				cout << "Let's play intermediate" << endl;
				break;
			}
			case e:
			{
				cout << "Let's play expert" << endl;
				break;
			}
			case q:
			{
				cout << "Time to quit" << endl;
				break;
			}

		}

	}
}

void easyGame()
{
	int row, col;
	minesweeper easyGame(10, 10, b);
	while (!easyGame.lose() && !easyGame.win())
	{
		cout << "select your next location(row col)" << endl;
		//needs error checking
		//infinite loops are fun
		cin >> row >> col;

		easyGame.select(row, col);
	}
}