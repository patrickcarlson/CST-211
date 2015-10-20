/***********************************************************
* Author:					Patrick Carlson
* Date Created:				10/8/2015
* Last Modification Date:	10/19/2015
* Assignment Number:		CST 211 Assignment 2
* Filename:					Array2D.h
*
* Overview:
*	Array2D class is a Multidimensional array. The size of the
*	array can be shortened or lengthened.
*
* Input:
*	Input for the class created is applied in Tester.cpp to
*	test the uses of the class. Outside input includes row length
*	and column length.
*
* Output:
*	This class does not provide output implicitly, but their
*	stored values can be reached through member functions.
************************************************************/

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Row.h"
#include "Exception.h"

/************************************************************************
* Class: Array2D
*
* Constructors:
*		Array2D()
*				m_row and m_col are set to 0, a 1 x 1 array is created.
*		Array2D(int row, int col = 0)
*				m_row set to row value and m_col set to col value, otherwise
*				m_col set to 0(default). Creates multidimensional array using
*				T** m_array member variable.
*		Array(const Array& copy)
*				New Array2D object member variables are set to same values
*				as copied Array2D object.
*
* Mutators:
*		void setRow(int rows)
*				This mutator allows resizing of the 2d array's rows. Must be 
*				set greater than 0.
*		void setColumn(int columns)
*				This mutator allows resizing of the 2d array's columns. Must 
*				be set greater than 0.
*
* Methods:
*		Array2D& operator=(const Array2D &rhs);
*				Assignment operator overload
*		Row<T> operator[](int index);
*				Subscript operator overload.
*		int getRow();
*				Accessor for m_row member variable. Returns number of rows.
*		int getColumn();
*				Accessor for m_col member variable. Returns number of columns
*		T& Select(int row, int column);
*				Return reference to item in prescribed row and column.
*************************************************************************/

template <typename T>
class Array2D
{
public:
	// Default Constructor
	Array2D();
	
	// Two argument constructor
	Array2D(int row, int col = 0);
	
	// Copy constructor
	Array2D(const Array2D &copy);
	
	// Descructor
	~Array2D();

	// Assignment operator overload
	Array2D& operator=(const Array2D &rhs);
	
	// Subscript operator overload
	Row<T> operator[](int index);

	// m_row member variable accessor.
	int getRow();

	// m_row mutator and array resize
	void setRow(int rows);

	// m_col member variable accessor
	int getColumn();

	// m_col mutator and array resize
	void setColumn(int columns);

	// Cell mutator
	T& Select(int row, int column);

private:
	T** m_array;		// Pointer to start of array of pointers.
	int m_row;			// Number of rows in array
	int m_col;			// Number of columns in array
};

#include "Array2D.inc"

#endif