template <typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col = 0);
	Array2D(const Array2D &copy);
	~Array2D();
	Array2D& operator=(const Array2D &rhs);
	Row<T> operator[](int index);
	int getRow();
	void setRow(int rows);
	int getColumn();
	void setColumn(int columns);
	T& Select(int row, int column);

private:
	T** m_array;
	int m_row;
	int m_col;
};

#include "Array2D.inc"