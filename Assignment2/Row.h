

template <typename T>
class Array2D;

template <typename T>
class Row
{
public:
	Row(Array2D& array, int row) :m_row(row), m_array2D(array) { }
	T& operator[](int column) { return array.Select(row, column) }

private:
	Array2D& m_array2D;
	int m_row;

};

