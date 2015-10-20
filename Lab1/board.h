/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
* Last Modification Date:	10/20/2015
* Assignment Number:    CST 211 Lab 1
* Filename:				board.h
*
* Overview:
*	This file is the header for board class, which contains
*	the array for stored minesweeper information.
*
* Input:
*	Row and Col sizes to build the array. Mode is passed in 
*	to lay down mines.
*
* Output:
*	Member functions can output bool values corresponding 
*	to various states within the cell.
************************************************************/
#ifndef BOARD_H
#define BOARD_H

#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "Array2D.h"
#include "cell.h"

/************************************************************************
* Class: board
*
* Constructors:
*		board(int inRow, int inCol, char mode)
*				3 argument instructor, takes in arrays dimensions as well
*				as char coresponding with difficulty level.
*
* Mutators:
*		void uncover(int row, int col)
*				Used to access cell m_covered member data and adjust.
*		void clearEmpties(int row, int col)
*				Recursive function used to clear empty cells adjacent, but
*				not diagnol to each other. ATM, clears too many, and solves
*				the game.
*		void mark(int row, int col)
*				Allos to set m_mark member variable of corresponding cell
*		void print()
*				Prints out user seeable array of game board.
*
* Methods:
*		bool bombinfo(int row, int col)
*				Returns bool value of bomb status of cell.
*		bool coverInfo(int row, int col)
*				Returns bool value of cover status of cell.
*************************************************************************/
class board
{
public:
	board(int inRow, int inCol, char mode);
	bool bombinfo(int row, int col);
	void uncover(int row, int col);
	bool coverInfo(int row, int col);
	void clearEmpties(int row, int col);
	void mark(int row, int col);
	void print();

private:
	int m_numRows;
	int m_numCols;
	Array2D<cell>* m_boardArray;
	int m_numBombs;

};


#include "board.inc"

#endif