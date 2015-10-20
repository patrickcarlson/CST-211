/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
* Last Modification Date:	10/20/2015
* Assignment Number:    CST 211 Lab 1
* Filename:				board.h
*
* Overview:
*	This file is the header for minesweeper class. A 
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
#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include "board.h"

class minesweeper
{
public:
	minesweeper(int inRow, int inCol, char mode);
	void select(int row, int col, bool mark);
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