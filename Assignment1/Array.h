#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array& copy);
	~Array();
	Array<T>& operator=(const Array &rhs);
	T& operator[](int index);
	int getStartIndex();
	void setStartIndex(int start_index);
	int getLength();
	void setLength(int length);

private:
	T* m_array;
	int m_length;
	int m_start_index;
};

class Exception
{
public:
	Exception();
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();
	Exception& operator =(const Exception &rhs);
	const char* getMessage();
	void setMessage(char *msg);
	friend ostream& operator<<(ostream &stream, const Exception &except);

private:
	char* m_msg;
};
#include "Array.inc"

#endif