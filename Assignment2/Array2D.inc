/***********************************************************
* Author:					Patrick Carlson
* Date Created:				10/8/2015
* Last Modification Date:	10/11/2015
* Assignment Number:		CST 211 Assignment 2
* Filename:					Array2D.inc
*
* Overview:
*	Array2D.inc contains the definitions for the Template class
*	Array2D. Declarations are in the Array2D.h file.
*
* Input:
*	Receives input from calls to declarations in the Array2D.h
*
* Output:
*	These Functions do not provide output implicitly. Member
*	variables and data stored in the array can be accessed 
*	utilizing these member functions.
************************************************************/

template <typename T>
Array2D<T>::Array2D()
	:m_row(0), m_col(0)
{
	m_array = new T *[1];
	
	m_array[m_row] = new T[1];
}

template <typename T>
Array2D<T>::Array2D(int row, int col = 0)
	:m_row(row), m_col(col)
{
	m_array = new T *[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}

}

template <typename T>
Array2D<T>::Array2D(const Array2D &copy)
{
	m_row = copy.m_row;
	m_col = copy.m_col;
	
	m_array = new T *[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = copy.m_array[i][j];
		}
	}

}

template <typename T>
Array2D<T>::~Array2D()
{
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;
}

template <typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D &rhs)
{
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	m_row = rhs.m_row;
	m_col = rhs.m_col;

	m_array = new T *[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = rhs.m_array[i][j];
		}
	}

	return *this;

}


template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	if (index < 0 || index >= m_row)
		throw Exception("Row index is out of Range.");

	Row<T> rowObj(*this, index);
	return rowObj;
}


template <typename T>
int Array2D<T>::getRow() //number of rows
{
	return m_row;
}

template <typename T>
void Array2D<T>::setRow(int rows)
{

	if (rows < 1)
		throw Exception("Array must contain at least 1 Row");

	T** tempArray = new T*[rows];
	for (int i = 0; i <  rows; i++)
	{
		tempArray[i] = new T[m_col];

	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			tempArray[i][j] = m_array[i][j];
		}
	}

	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	m_row = rows;

	m_array = new T*[m_row];
	for (int i = 0; i < m_row; i++ )
	{
		m_array[i] = new T[m_col];
	}

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = tempArray[i][j];
		}
	}

	for (int i = 0; i < m_row; i++)
	{
		delete[] tempArray[i];
	}

	delete[] tempArray;

}

template <typename T>
int Array2D<T>::getColumn()
{
	return m_col;
}

template <typename T>
void Array2D<T>::setColumn(int columns)
{
	if (columns < 1)
		throw Exception("Array must contain at least 1 Column");

	//TempArray to store copied data from m_array
	T** tempArray = new T*[m_row];
	
	for (int i = 0; i < m_row; i++)
	{
		tempArray[i] = new T[columns];
	}

	//copy data from m_array
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			tempArray[i][j] = m_array[i][j];
		}
	}

	//delete m_array
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	m_col = columns;

	//Rebuild m_array in the prescribed likeness
	m_array = new T*[m_row];
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new T[m_col];
	}

	//copy from tempArray to m_array
	//also deletes tempArray row arrays as it goes.
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = tempArray[i][j];
		}

		delete[] tempArray[i];
	}

	//delete last of tempArray
	delete[] tempArray;
	
}

template <typename T>
T& Array2D<T>::Select(int row, int column)
{
	if (row < 0 || row >= m_row)
		throw Exception("Row index out of range");

	if (column < 0 || column >= m_col)
		throw Exception("Column index out of range");

	T* something = m_array[row];
	return something[column];
}