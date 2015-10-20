cell::cell()
{
	m_marked = false;
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

void cell::setbombStatus()
{
	m_bomb = true;
}

void cell::uncover()
{
	m_covered = false;
}

bool cell::getCoverStatus()
{
	return m_covered;
}

void cell::setmarked()
{
	m_marked = true;
}

bool cell::getMarked()
{
	return m_marked;
}