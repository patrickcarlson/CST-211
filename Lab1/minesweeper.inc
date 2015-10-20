minesweeper::minesweeper(int inRow, int inCol, char mode)
	:m_row(inRow), m_col(inCol), m_mode(mode)
{
	winGame = false;
	loseGame = false;
	board gameBoard(inRow, inCol, mode);
}

void minesweeper::select(int row, int col)
{
	if (gameBoard->bombinfo)
		loseGame = true;

	else
}

bool minesweeper::win()
{
	return winGame;
}

bool minesweeper::lose()
{
	return loseGame;
}