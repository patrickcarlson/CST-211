template <typename T>
Array2D<T>::Array2D()
{

}

template <typename T>
Array2D<T>::Array2D(int row, int col = 0)
{
	m_array = new Row*[row];
}

template <typename T>
Array2D<T>::Array2D(const Array2D &copy)
{

}

template <typename T>
Array2D<T>::~Array2D()
{

}

template <typename T>
Array2D& Array2D<T>::operator=(const Array2D &rhs)
{

}

template <typename T>
Row<T> Array2D<T>::operator[](int index)
{

}

template <typename T>
int Array2D<T>::getRow( ) //number of rows
{

}

template <typename T>
void Array2D<T>::setRow(int rows)
{

}

template <typename T>
int Array2D<T>::getColumn()
{

}

template <typename T>
void Array2D<T>::setColumn(int columns)
{

}

template <typename T>
T& Array2D<T>::Select(int row, int column)
{

}