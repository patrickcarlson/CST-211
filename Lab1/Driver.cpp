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
				intermediateGame();
				break;
			}
			case e:
			{
				cout << "Let's play expert" << endl;
				expertGame();
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
	int lrow;
	int lcol;
	minesweeper easygame(10, 10, 'b');
	char yesorno;
	bool mark;

	while (!easygame.lose() && !easygame.win())
	{
		cout << "Would you like to mark a potential bomb?(y or n)" << endl;

		cin >> yesorno;

		if (yesorno == 'y')
			mark = true;
		else
			mark = false;
		cout << "select your next location" << endl;
		//needs error checking
		//infinite loops are fun
		cin >> lrow >> lcol;

		easygame.select(lrow, lcol, mark);

		
	}
}

void intermediateGame()
{
	int lrow;
	int lcol;
	minesweeper intermediategame(16, 16, 'i');
	char yesorno;
	bool mark;

	while (!intermediategame.lose() && !intermediategame.win())
	{
		cout << "Would you like to mark a potential bomb?(y or n)" << endl;

		cin >> yesorno;

		if (yesorno == 'y')
			mark = true;
		else
			mark = false;
		cout << "select your next location" << endl;
		//needs error checking
		//infinite loops are fun
		cin >> lrow >> lcol;

		intermediategame.select(lrow, lcol, mark);


	}
}

void expertGame()
{
	int lrow;
	int lcol;
	minesweeper expertGame(16, 30, 'e');
	char yesorno;
	bool mark;

	while (!expertGame.lose() && !expertGame.win())
	{
		cout << "Would you like to mark a potential bomb?(y or n)" << endl;

		cin >> yesorno;

		if (yesorno == 'y')
			mark = true;
		else
			mark = false;
		cout << "select your next location" << endl;
		//needs error checking
		//infinite loops are fun
		cin >> lrow >> lcol;

		expertGame.select(lrow, lcol, mark);


	}
}