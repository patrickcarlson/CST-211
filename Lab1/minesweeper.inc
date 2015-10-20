minesweeper::minesweeper(int inRow, int inCol, char mode)
	:m_row(inRow), m_col(inCol), m_mode(mode)
{
	winGame = false;
	loseGame = false;
	gameBoard = new board(m_row, m_col, m_mode);
}

void minesweeper::select(int row, int col)
{
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