board::board(int inRow, int inCol, char mode)
	:m_numRows(inRow), m_numCols(inCol), m_boardArray(inRow, inCol)
{
	if (mode = 'b')
		m_numBombs = 10;
	else if (mode = 'i')
		m_numBombs = 40;
	else if (mode = 'e')
		m_numBombs = 100;

	int bombCount = m_numBombs;

	int ranBomb;

	cell newCell(false);

	for (int row = 0; row < m_numRows; ++row)
	{
		for (int col = 0; col < m_numCols; ++col)
		{
			if (bombCount == 0)
				ranBomb = 0;
			else
			ranBomb = rand() % 1 + 0;

			if (ranBomb == 1)
			{
				bombCount--;
			}
			cell newCell(ranBomb == 1);

			m_boardArray[row][col] = newCell;
		}
	}

}

bool board::bombinfo(int row, int col)
{
	cell checkCell = m_boardArray.Select(row, col);

	return checkCell.getbombStatus;
}