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

template <typename T>
class Array2D;

template <typename T>
class Row
{
public:
	Row(Array2D<T>& array, int row) :m_row(row), m_array2D(array) { }
	T& operator[](int column) 
	{ 
		if (column < 0 || column >= m_array2D.getColumn())
			throw Exception("Column index is out of Range");

		return m_array2D.Select(m_row, column); 		
	}

private:
	Array2D<T>& m_array2D;
	int m_row;

};

