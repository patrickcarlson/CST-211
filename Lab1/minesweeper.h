#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "board.h"

class minesweeper
{
public:
	minesweeper(int inRow, int inCol, char mode);
	void select(int row, int col);
	bool win();
	bool lose();

private:
	board* gameBoard;
	char m_mode;
	int m_row;
	int m_col;
	bool winGame;
	bool loseGame;

};


#include "minesweeper.inc"

#endif