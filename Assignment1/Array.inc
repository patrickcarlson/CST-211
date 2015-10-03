#include <string.h>

template <typename T>
Array<T>::Array()
{

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