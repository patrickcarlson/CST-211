

template <typename T>
class Array2D;

template <typename T>
class Row
{
public:
	Row(Array2D<T>& array, int row) :m_row(row), m_array2D(array) { }
	T& operator[](int column) { return m_array2D.Select(m_row, column); }

private:
	Array2D<T>& m_array2D;
	int m_row;

};

