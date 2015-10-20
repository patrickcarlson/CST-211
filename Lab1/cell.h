#ifndef CELL_H
#define CELL_H

class cell
{
public:
	cell();
	cell(bool bomb);
	void setbombCount(int numBombs);
	int getbombCount();
	bool getbombStatus();
	void setbombStatus();
	void uncover();

private:
	bool m_covered;
	bool m_bomb;
	int bombCount;


};


#include "cell.inc"

#endif