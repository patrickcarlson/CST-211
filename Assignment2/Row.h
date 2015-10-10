#include "Exception.h"

template <typename T>
class Array2D;

template <typename T>
class Row
{
public:
	Row(Array2D& array, int row);
	T& operator[](int column);

private:
	Array2D& m_array2D;
	int m_row;

};

#include "Row.inc";