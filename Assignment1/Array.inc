#include <iostream>
#include <string.h>

template <typename T>
Array<T>::Array()
{
	m_length = 10;
	m_start_index = 0;
}

template <typename T>
Array<T>::Array(int length, int start_index = 0)
	:m_length(length), m_start_index(start_index)
{
	m_array = new T[length];
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;
	m_array = new T[m_length];
	memcpy(m_array, copy.m_array, m_length);
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
}

template <typename T>
Array<T>& Array<T>::operator= (const Array &rhs)
{
	delete[] m_array;
	m_length = rhs.m_length;
	m_start_index = rhs.m_start_index;
	m_array = new T[m_length];
	memcpy(m_array, rhs.m_array, m_length);

	return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	try{
		if (index < m_start_index || index >= m_start_index + m_length)
		{
			throw index;
		}

		
	}
	catch (int e)
	{
		Exception except("Index out of Range");

		cout << e << " " << except << endl;
	}
	
	
	int trueindex = index - m_start_index;
	return m_array[trueindex];
}

template <typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
int Array<T>::getLength()
{
	return m_length;
}

template <typename T>
void Array<T>::setLength(int length)
{
	m_length = length;
}

/*
Exception::Exception()
{
	m_msg = "Standard Error";
}

Exception::Exception(char *msg)
	:m_msg(msg)
{

}

Exception::Exception(const Exception &copy)
{
	m_msg = copy.m_msg;
}

Exception::~Exception()
{

}

Exception& Exception::operator=(const Exception &rhs)
{
	m_msg = rhs.m_msg;

	return *this;
}

const char* Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(char *msg)
{
	m_msg = msg;
}

std::ostream& operator<<(std::ostream &stream, const Exception &except)
{
	stream << except.m_msg;

	return stream;
}

*/