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

/************************************************************************
* Class: cell
*
* Constructors:
*		cell()
*				Default constructor.
*		cell(bool bomb)
*				Single argument constructor, sets bomb state to bool passed in.
*
* Mutators:
*		void setbombCount(int numBombs)
*				Set member variable bombcount.
*		void uncover()
*				Sets member variable m_covered to false.
*		void setmarked()
*				Set m_marked bool to true.
*
* Methods:
*		int getbombCount();
*				returns int value corresponding to number of bombs in
*				cells immediate area.
*		bool getCoverStatus()
*				Returns bool of m_covered
*		bool getMarked()
*				Returns bool of m_marked.
*************************************************************************/
class cell
{
public:
	// No argument constructor
	cell();

	// Single argument constructor
	cell(bool bomb);

	// bombCount mutator
	void setbombCount(int numBombs);

	// bombCount inspector
	int getbombCount();

	// m_bomb inspector
	bool getbombStatus();

	// m_bomb mutator
	void setbombStatus();

	// m_covered mutator
	void uncover();

	// m_covered inspector
	bool getCoverStatus();

	// m_marked mutator
	void setmarked();

	// m_marked inspector
	bool getMarked();

private:
	bool m_covered;	//cover status bool
	bool m_bomb;	//bomb presence bool
	bool m_marked;	//marked cell bool
	int bombCount;	//number of bombs in region around cell


};


#include "cell.inc"

#endif