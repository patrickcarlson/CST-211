/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
* Last Modification Date:	10/20/2015
* Assignment Number:    CST 211 Lab 1
* Filename:				board.h
*
* Overview:
*	This file is the .inc file for the board class, which 
*	contains the array for stored minesweeper information.
*
* Input:
*	Row and Col sizes to build the array. Mode is passed in
*	to lay down mines.
*
* Output:
*	Member functions can output bool values corresponding
*	to various states within the cell.
************************************************************/

board::board(int inRow, int inCol, char mode)
	:m_numRows(inRow), m_numCols(inCol)
{
	Array2D<cell>* newBoardArray = new Array2D<cell>(m_numRows, m_numCols);
	m_boardArray = newBoardArray;

	if (mode == 'b')
	{
		m_numBombs = 10;
	}
	else if (mode == 'i')
	{
		m_numBombs = 40;
	}
	else if (mode == 'e')
	{
		m_numBombs = 100;
	}

	int bombCount = m_numBombs;

	int randCol = rand() % m_numCols;

	cell newCell(false);
	while (bombCount > 0)
	{
		for (int row = 0; row < m_numRows; ++row)
		{
			randCol = rand() % m_numCols;

			cell* newCell = &m_boardArray->Select(row, randCol);
			if (!newCell->getbombStatus())
			{
				newCell->setbombStatus();

				bombCount--;
			}


		}
	}

	for (int row = 0; row < m_numRows; ++row)
	{
		for (int col = 0; col < m_numCols; ++col)
		{
			int cellBombs = 0;
			if (row != m_numRows - 1 && bombinfo(row + 1, col))
				cellBombs++;
			if (row != m_numRows - 1 && col != m_numCols - 1 && bombinfo(row + 1, col + 1))
				cellBombs++;
			if (col != m_numCols - 1 && bombinfo(row, col + 1))
				cellBombs++;
			if (row != 0 && col != m_numCols - 1 && bombinfo(row - 1, col + 1))
				cellBombs++;
			if (row != 0 && bombinfo(row - 1, col))
				cellBombs++;
			if (row != 0 && col != 0 && bombinfo(row - 1, col - 1))
				cellBombs++;
			if (col != 0 && bombinfo(row, col - 1))
				cellBombs++;
			if (row != m_numRows - 1 && col != 0 && bombinfo(row + 1, col - 1))
				cellBombs++;

			cell* curCell = &m_boardArray->Select(row, col);

			curCell->setbombCount(cellBombs);
		}
	}

}

bool board::bombinfo(int row, int col)
{
	cell* checkCell = &m_boardArray->Select(row, col);

	return checkCell->getbombStatus();
}

void board::uncover(int row, int col)
{
	cell* uncoverCell = &m_boardArray->Select(row, col);

	uncoverCell->uncover();
}

bool board::coverInfo(int row, int col)
{
	cell* checkCell = &m_boardArray->Select(row, col);

	return checkCell->getCoverStatus();
}

void board::clearEmpties(int row, int col)
{
	this->uncover(row, col);

	if (row + 1 < m_numRows && !bombinfo(row + 1, col) && coverInfo(row + 1, col))
	{
		clearEmpties(row + 1, col);
	}

	if (col + 1 < m_numCols && !bombinfo(row, col + 1) && coverInfo(row, col + 1))
	{
		clearEmpties(row, col + 1);
	}

	if (row - 1 >= 0 && !bombinfo(row - 1, col) && coverInfo(row - 1, col))
	{
		clearEmpties(row - 1, col);
	}

	if (col - 1 >= 0 && !bombinfo(row, col - 1) && coverInfo(row, col - 1))
	{
		clearEmpties(row, col - 1);
	}
}

void board::mark(int row, int col)
{
	cell* markCell = &m_boardArray->Select(row, col);

	markCell->setmarked();
}

void board::print()
{
	for (int row = 0; row < m_numRows; ++row)
	{
		for (int col = 0; col < m_numCols; ++col)
		{
			cell* curCell = &m_boardArray->Select(row, col);

			if (curCell->getMarked())
				std::cout << 'M' << " ";
			else if (curCell->getCoverStatus())
				std::cout << 'E' << " ";
			else
				std::cout << curCell->getbombCount() << " ";

		}
		std::cout << std::endl;
	}
}