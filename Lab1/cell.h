/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
* Last Modification Date:	10/20/2015
* Assignment Number:    CST 211 Lab 1
* Filename:				cell.h
*
* Overview:
*	This file is the header for cell class, each cell
*	is a cell in the 2d array and stores information
*	for the corresponding game cell.
*
* Input:
*	
*
* Output:
*	Member functions can output bool values corresponding
*	to various states within the cell.
************************************************************/
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
	bool getCoverStatus();
	void setmarked();
	bool getMarked();

private:
	bool m_covered;
	bool m_bomb;
	bool m_marked;
	int bombCount;


};


#include "cell.inc"

#endif