#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>
#include "Array2D.h"
#include "cell.h"

class board
{
public:
	board(int inRow, int inCol, char mode);
	bool bombinfo(int row, int col);
	void uncover(int row, int col);
	bool coverInfo(int row, int col);
	void clearEmpties(int row, int col);
	void print();

private:
	int m_numRows;
	int m_numCols;
	Array2D<cell>* m_boardArray;
	int m_numBombs;

};


#include "board.inc"

#endif