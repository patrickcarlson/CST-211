

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
	T* something = m_array[row];
	return something[column];
}