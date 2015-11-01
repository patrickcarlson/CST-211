/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/20/2015
* Last Modification Date:	10/24/2015
* Assignment Number:    CST 211 Assignment 4
* Filename:				Stack.h
*
* Overview:
*	This is the header file for the Stack class which will 
*	implement a stack object based on the LinkList class.
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the stack.
************************************************************/
#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
#include "Exception.h"


/************************************************************************
* Class: Stack
*
* Constructors:
*		Stack(int capacity)
*				Single argument constructor, assigns member
*				variable m_capacity to int parameter.
*		
* Mutators:
*		void Push(T data);
*				Pushes data value to top of the Stack
*		T Pop()
*				Removes and returns top element of stack

*		
* Methods:
*		const T Peek()
*				Returns top element of stack
*		int Size()
*				Returns current number of elements in stack
*		bool isEmpty()
*				Returns bool value, true, if stack is empty
*		bool isFull()
*				Returns bool value, true, if stack is full
*	
*************************************************************************/
template <typename T>
class Stack    // Needs exceptions
{
public:

	// Single argument constructor
	Stack(int capacity, int size = 0);

	// Copy Constructor
	Stack(const Stack& copy);

	// Assignment operator overload
	Stack<T>& operator = (const Stack& rhs);

	// Pushes data element to top of stack
	void Push(T data);

	// Removes and returns top element of stack
	T Pop();

	// Returns top element of stack
	const T Peek();

	// Returns the number of items currently on stack
	int Size();

	// Returns true if stack is empty
	bool isEmpty();

	// Returns true if stack is full
	bool isFull();

private:
	LinkedList<T> m_list;	// List member variable
	int m_capacity;			// Stack capacity member variable
	int m_size;				// Stack size(how many currently holding) member variable.
};

#include "Stack.inc"

#endif