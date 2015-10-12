/***********************************************************
* Author:					Patrick Carlson
* Date Created:				10/8/2015
* Last Modification Date:	10/11/2015
* Assignment Number:		CST 211 Assignment 2
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
	/**************************************************************
	*	  Purpose:  Two argument constructor for Row class.
	*
	*         Entry:  Creation of a new Row object with two arguments
	*
	*          Exit:	Assigns member variable m_row to row and
	*					m_array2D to array.
	****************************************************************/
	Row(Array2D<T>& array, int row) :m_row(row), m_array2D(array) { }
	
	/**************************************************************
	*	  Purpose:  Subscript operator overload.
	*
	*         Entry:  Indexing to 2d array via subscripts.
	*
	*          Exit:	Returns reference to data stored in array.
	****************************************************************/
	T& operator[](int column) 
	{ 
		if (column < 0 || column >= m_array2D.getColumn())
			throw Exception("Column index is out of Range");

		return m_array2D.Select(m_row, column); 		
	}


private:
	Array2D<T>& m_array2D;  // Array2D object member variable
	int m_row;				// index to row being accessed

};


#endif