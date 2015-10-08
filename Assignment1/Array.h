/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/1/2015
* Last Modification Date:	10/3/2015
* Assignment Number:    CST 211 Assignment 1
* Filename:				Array.h
*
* Overview:
*	These classes allow the creation of a dynamic array, titled
*	Array, which can have its index values, and lengths, adjusted
*	by users of this class. The Array class is a template class.
*
* Input:
*	Input for the classes created is applied in Tester.cpp to
*	test the uses of the class. Outside input includes length
*	and starting index for the Array class, and a message in the
*	exception class.
*
* Output:
*	These classes do not provide output implicitly, but their
*	stored values can be reached through member functions.
************************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

/************************************************************************
* Class: Array
*
* Constructors:
*		Array()	
*				Length is set to 10 and start index is set to 0. 
*		Array(int length, int start_index = 0)		
*				m_length set to argument value length, m_start_index set to
*				argument value start_index, or defaults to 0.
*		Array(const Array& copy)
*				New array object member variables are set to same values
*				as copied Array object.
*
* Mutators:
*		void setStartIndex( int start_index)
*				This mutator allows adjusting of the start index of the
*				Array
*		void setLength(int length)
*				This mutator allows initialization of the length member
*				variable.
*
* Methods:
*		int getStartIndex()
*				Returns current start index member data.	
*		int getLength()
*				Returns current length member data.
*		Array<T>& operator=(const Array &rhs)
*				Overloads the assignment operator for the Array class
*		T& operator[](int index)
*				Overloads the subscript operator.
*************************************************************************/

template <typename T>
class Array
{
public:
	// Default Constructor
	Array();

	// Two Argument constructor
	Array(int length, int start_index = 0);
	
	// Copy Constructor
	Array(const Array& copy);
	
	// Descructor
	~Array();

	// Assignment operator overload
	Array<T>& operator=(const Array &rhs);
	
	// Subscript operator overload
	T& operator[](int index);
	
	// Start Index member data inspector
	int getStartIndex();

	// Start Index member data mutator
	void setStartIndex(int start_index);
	
	// Length member data inspector
	int getLength();

	// Length member data mutator
	void setLength(int length);

private:
	T* m_array;				// Pointer to start of the Array.
	int m_length;			// Length of the array.
	int m_start_index;		// Start index of the array.
};

#include "Array.inc"

#endif