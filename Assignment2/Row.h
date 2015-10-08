#include "Array2D.h"
#include "Exception.h"

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