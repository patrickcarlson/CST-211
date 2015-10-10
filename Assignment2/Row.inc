template <typename T>
Row<T>::Row(Array2D& array, int row)
	:m_row(row), m_array2D(array)
{


}

template <template T>
T& Row<T>::operator[](int column)
{

}