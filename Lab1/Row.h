/***********************************************************
* Author:					Patrick Carlson
* Date Created:				10/8/2015
* Last Modification Date:	10/17/2015
* Assignment Number:		CST 211 Assignment 3
* Filename:					Row.h
*
* Overview:
*	Row class is utilized as a proxy class for overloading
*	the subscript operator in the Array2D class.
*
* Input:
*	The constructor takes in an Array2D object, and the row
*	of the 2d array that is being indexed.
*
* Output:
*	The overloaded subscript operator outputs a reference to
*	the indexed cell of the array.
************************************************************/
#ifndef ROW_H
#define ROW_H

// forward declaration of Array2D class
template <typename T>
class Array2D;

/************************************************************************
* Class: Row
*
* Constructors:
*		Row(Array2D<T>& array, int row)
*				m_row set to row data, and m_array2D set to array
*
* Methods:
*		T& operator [](int column)
*				Subscript operator overload.
*************************************************************************/
template <typename T>
class Row
{
public:

	// Row class single argument constructor
	Row(Array2D<T>& array, int row);
	
	// Subscript operator overload
	T& operator[](int column);
	


private:
	Array2D<T>& m_array2D;  // Array2D object member variable
	int m_row;				// index to row being accessed

};

#include "Row.inc"
m
#endif