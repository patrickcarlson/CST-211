/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/1/2015
* Last Modification Date:	10/3/2015
* Assignment Number:    CST 211 Assignment 1
* Filename:				Array.inc
*
* Overview:
*	Array.inc contains the definitions for the Template class
*	Array.
*
* Input:
*	Receives input from calls to declarations in the Array.h
* 
*
* Output:
*	These functions do not provide output implicitly, but their
*	stored values can be reached through member functions.
************************************************************/
#include <iostream>
#include <string.h>

/**************************************************************
*	  Purpose:  Default constructor for Array class
*
*         Entry:  Creation of a new Array object with no arguments
*
*          Exit:	Assigns member variable m_length to 10 and
*					member variable m_start_index to 0. Creates
*					array on the heap.
****************************************************************/

template <typename T>
Array<T>::Array()
{
	
	m_length = 10;
	m_start_index = 0;
	m_array = new T[m_length];
}

/**************************************************************
*	  Purpose:  Two argument constructor for Array class.
*
*         Entry:	Creation of a new Array object with arguments 
*					of length and start_index. 
*
*          Exit:	Assigns member variable m_length to value of
*					length and member variable m_start_index to
*					value of start_index. Creates array on heap.
****************************************************************/
template <typename T>
Array<T>::Array(int length, int start_index = 0)
	:m_length(length), m_start_index(start_index)
{
	if (length <= 0)
		throw Exception("Array length must be greater than 0");

	m_array = new T[length];
}

/**************************************************************
*	  Purpose:  Copy Constructor for Array class
*
*         Entry:	Array object to be copied.
*
*          Exit:	Assigns member variable m_length and member
*					variable start_index to values of corresponding
*					member variables in object to be copied. Creates
*					array on the heap.
****************************************************************/
template <typename T>
Array<T>::Array(const Array& copy)
{
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;
	m_array = new T[m_length];
	memcpy(m_array, copy.m_array, m_length);
}

/**************************************************************
*	  Purpose:  Destructor
*
*         Entry:	End of life for Array object.
*
*          Exit:	Deletes m_array member variable, the entire
*					array, from the heap.
****************************************************************/
template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
}

/**************************************************************
*	  Purpose:  Assignment operator overload
*
*         Entry:	When one Array object is assigned to another
*
*          Exit:	Array object to receive assignment has 
*					member varialbe m_array deleted from memory.
*					member variables from assigning object are copied.
****************************************************************/
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

/**************************************************************
*	  Purpose:  Subscript operator overload
*
*         Entry:	When element of the array is indexed using
*					the subscript operator.
*
*          Exit:	Assigns member variable m_length to 10 and
*					member variable m_start_index to 0. Creates
*					array on the heap.
*
*		Exception:	Checks that index is within range of the 
*					array. 
****************************************************************/
template <typename T>
T& Array<T>::operator[](int index)
{

	if (index < m_start_index || index >= m_start_index + m_length)
		throw Exception("Index out of bounds");
	
	int trueindex = index - m_start_index;
	return m_array[trueindex];
}

/**************************************************************
*	  Purpose:		Member variable, m_start_index, inspector
*
*         Entry:	None
*
*          Exit:	Returns data stored in member variable 
*					m_start_index.
****************************************************************/
template <typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

/**************************************************************
*	  Purpose:		Member variable, m_start_index, mutator
*
*         Entry:	Argument contains variable start_index which
*					will replace data currently stored in 
*					m_start_index.
*
*          Exit:	Returns no value.
****************************************************************/
template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**************************************************************
*	  Purpose:		Member variable, m_length, inspector
*
*         Entry:	None
*
*          Exit:	Returns data stored in member variable
*					m_length.
****************************************************************/
template <typename T>
int Array<T>::getLength()
{
	return m_length;
}

/**************************************************************
*	  Purpose:		Member variable, m_length, mutator
*
*         Entry:	Argument contains variable length which
*					will replace data currently stored in
*					m_length.
*
*          Exit:	Returns no value.
****************************************************************/
template <typename T>
void Array<T>::setLength(int length)
{
	m_length = length;
}

