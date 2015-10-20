/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/17/2015
* Last Modification Date:	10/20/2015
* Assignment Number:    CST 211 Lab 1
* Filename:				cell.inc
*
* Overview:
*	This file is the .inc file for cell class, each cell
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

/**************************************************************
*	  Purpose:  Default constructor for cell class
*
*         Entry:  Creation of a new cell object
*
*          Exit:	Assigns member variables m_marked and m_bomb
*					to true, and m_covered to true. bombCount
*					is set to 0.
****************************************************************/
cell::cell()
{
	m_marked = false;
	m_bomb = false;
	m_covered = true;
	bombCount = 0;
}

/**************************************************************
*	  Purpose:  Single argument constructor for cell class
*
*         Entry:  Creation of a new cell object
*
*          Exit:	Assigns member variables m_marked to false
*					passes in bool value to set m_bomb to. 
*					bombCount is set to 0.
****************************************************************/
cell::cell(bool bomb)
	:m_bomb(bomb)
{
	m_marked = false;
	m_covered = true;
	bombCount = 0;
}

/**************************************************************
*	  Purpose:  bombCount mutator
*
*         Entry:  Pass in int value of number of bombs.
*
*          Exit:	
****************************************************************/
void cell::setbombCount(int numBombs)
{
	bombCount = numBombs;
}

/**************************************************************
*	  Purpose:  bombCount inspector
*
*         Entry:
*
*          Exit: Return value of bombCount
****************************************************************/
int cell::getbombCount()
{
	return bombCount;
}

/**************************************************************
*	  Purpose:  m_bomb inspector
*
*         Entry:
*
*          Exit: Return value of m_bomb
****************************************************************/
bool cell::getbombStatus()
{
	return m_bomb;
}

/**************************************************************
*	  Purpose:  m_bomb inspector
*
*         Entry:
*
*          Exit: Return value of m_bomb
****************************************************************/
void cell::setbombStatus()
{
	m_bomb = true;
}

/**************************************************************
*	  Purpose:  m_covered mutator
*
*         Entry:
*
*          Exit: Set m_covered to false
****************************************************************/
void cell::uncover()
{
	m_covered = false;
}

/**************************************************************
*	  Purpose:  m_covered inspector
*
*         Entry:
*
*          Exit: Return value of m_covered
****************************************************************/
bool cell::getCoverStatus()
{
	return m_covered;
}

/**************************************************************
*	  Purpose:  m_marked mutator
*
*         Entry:
*
*          Exit: set value of m_marked to true
****************************************************************/
void cell::setmarked()
{
	m_marked = true;
}

/**************************************************************
*	  Purpose:  m_marked inspector
*
*         Entry:
*
*          Exit: return m_marked value
****************************************************************/
bool cell::getMarked()
{
	return m_marked;
}