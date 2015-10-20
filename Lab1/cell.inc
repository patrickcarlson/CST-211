cell::cell()
{
	m_bomb = false;
	m_covered = true;
	bombCount = 0;
}

cell::cell(bool bomb)
	:m_bomb(bomb)
{
	m_covered = true;
	bombCount = 0;
}

void cell::setbombCount(int numBombs)
{
	bombCount = numBombs;
}

int cell::getbombCount()
{
	return bombCount;
}

bool cell::getbombStatus()
{
	return m_bomb;
}