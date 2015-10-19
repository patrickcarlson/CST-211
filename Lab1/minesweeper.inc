minesweeper::minesweeper(int inRow, int inCol, char mode)
	:m_row(inRow), m_col(inCol), m_mode(mode)
{
	winGame = false;
	loseGame = false;
	board(inRow, inCol, mode);
}

void minesweeper::select(int row, int col)
{

}

bool minesweeper::win()
{
	return winGame;
}

bool minesweeper::lose()
{
	return loseGame;
}