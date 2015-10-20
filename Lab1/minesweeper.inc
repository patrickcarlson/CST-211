minesweeper::minesweeper(int inRow, int inCol, char mode)
	:m_row(inRow), m_col(inCol), m_mode(mode)
{
	winGame = false;
	loseGame = false;
	board newBoard(m_row, m_col, m_mode);
	gameBoard = &newBoard;
}

void minesweeper::select(int row, int col)
{
	if (gameBoard->bombinfo(row, col))
	{
		loseGame = true;

		return;
	}

	else

		gameBoard->clearEmpties(row, col);

		//gameBoard->uncover(row, col);


}

bool minesweeper::win()
{
	return winGame;
}

bool minesweeper::lose()
{
	return loseGame;
}