#ifndef BOARD_H
#define BOARD_H

#include "Array2D.h"
#include "cell.h"

class board
{
public:
	board(int inRow, int inCol, char mode);

private:
	int m_numRows;
	int m_numCols;
	Array2D<cell> boardArray;
	int m_numMines;

};


#include "board.inc"

#endif