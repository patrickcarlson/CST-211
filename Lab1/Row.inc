/***********************************************************
* Author:					Patrick Carlson
* Date Created:				10/17/2015
* Last Modification Date:	10/17/2015
* Assignment Number:		CST 211 Assignment 3
* Filename:					Row.inc
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

/**************************************************************
*	  Purpose:  Two argument constructor for Row class.
*
*         Entry:  Creation of a new Row object with two arguments
*
*          Exit:	Assigns member variable m_row to row and
*					m_array2D to array.
****************************************************************/
template <typename T>
Row<T>::Row(Array2D<T>& array, int row)
	:m_row(row), m_array2D(array)
{

}

/**************************************************************
*	  Purpose:  Subscript operator overload.
*
*         Entry:  Indexing to 2d array via subscripts.
*
*          Exit:	Returns reference to data stored in array.
****************************************************************/
template <typename T>
T& Row<T>::operator[](int column)
{
	if (column < 0 || column >= m_array2D.getColumn())
		throw Exception("Column index is out of Range");

	return m_array2D.Select(m_row, column);
}