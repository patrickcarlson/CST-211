/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
* Last Modification Date:	10/20/2015
* Assignment Number:    CST 211 Lab 1
* Filename:				minesweeper.inc
*
* Overview:
*	This file is the .inc file for minesweeper class. A
*	minesweeper object contains various game status checks.
*
* Input:
*	Row and Col sizes to build the board. Mode is passed in
*	to lay down mines.
*
* Output:
*	Member functions can output bool values corresponding
*	to win loss states
************************************************************/
minesweeper::minesweeper(int inRow, int inCol, char mode)
	:m_row(inRow), m_col(inCol), m_mode(mode)
{
	winGame = false;
	loseGame = false;
	gameBoard = new board(m_row, m_col, m_mode);
}

void minesweeper::select(int row, int col, bool mark)
{
	if (mark)
	{
		gameBoard->mark(row, col);

		gameBoard->print();

		return;
	}
	
	if (gameBoard->bombinfo(row, col))
	{
		loseGame = true;

		std::cout << "That was a bomb!" << std::endl;

		return;
	}

	gameBoard->clearEmpties(row, col);

	gameBoard->print();


}

bool minesweeper::win()
{
	return winGame;
}

bool minesweeper::lose()
{
	return loseGame;
}