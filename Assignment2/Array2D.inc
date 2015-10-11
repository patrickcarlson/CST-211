#include <string.h>

template <typename T>
Array2D<T>::Array2D()
{

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
		delete[] m_array[i]
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
			m_array[i][j] = copy.m_array[i][j];
		}
	}

}


template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	Row<T> rowObj(m_array, index);
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
	rows;
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

	m_array = tempArray;
}

template <typename T>
int Array2D<T>::getColumn()
{
	return m_col;
}

template <typename T>
void Array2D<T>::setColumn(int columns)
{
	return 0;
}

template <typename T>
T Array2D<T>::Select(int row, int column)
{
	return m_array[row][column];
}