#include "Array.h"

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
	
}

template <typename T>
Array<T>::~Array()
{

}

template <typename T>
Array& Array<T>::operator =(const Array& rhs)
{

}

template <typename T>
T& Array<T>::operator[](int index)
{

}

template <typename T>
int Array<T>::getStartIndex()
{

}

template <typename T>
void Array<T>::setStartIndex(int start_index)
{

}

template <typename T>
int Array<T>::getLength()
{

}

void Array<T>::setLength(int length)
{

}