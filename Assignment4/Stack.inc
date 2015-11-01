/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/20/2015
* Last Modification Date:	10/25/2015
* Assignment Number:    CST 211 Assignment 4
* Filename:				Stack.inc
*
* Overview:
*	This is the .inc file for the Stack class which will
*	implement a stack object based on the LinkList class.
*	this file contains the definitions for Stack.h
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the stack.
************************************************************/


/**************************************************************
*	  Purpose:  Single argument constructor of Stack
*
*         Entry:  Creation of a new Stack with one argument
*
*          Exit:	Assign m_capacity to supplied argument. Assign
*					m_size to current size of 0.
****************************************************************/
template <typename T>
Stack<T>::Stack(int capacity, int size = 0)
	:m_capacity(capacity), m_size(size)
{
	
}

/**************************************************************
*	  Purpose:  Copy constructor of Stack
*
*         Entry:  Stack to be copied
*
*          Exit:	New stack with same values of that which it
*					copied.
****************************************************************/
template <typename T>
Stack<T>::Stack(const Stack& copy)
	:m_size(copy.m_size), m_capacity(copy.m_capacity)
{
	m_list = copy.m_list;
}

/**************************************************************
*	  Purpose:  Assignment operator overload.
*
*         Entry:  Stack who's values will be assigned to this
*					Stack.
*
*          Exit:	Copy values from rhs Stack to this Stack, 
*					return reference to this stack.
****************************************************************/
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack& rhs)
{
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;

	m_list = rhs.m_list;

	return *this;
}

/**************************************************************
*	  Purpose:  Push argument data to top of stack, if room
*
*         Entry:  Data to be placed at top of stack.
*
*          Exit:	Assign m_capacity to supplied argument. Assign
*					m_size to current size of 0.
****************************************************************/
template <typename T>
void Stack<T>::Push(T data)
{
	if (m_size == m_capacity)
		throw Exception("Overflow: Stack is at capacity.");

	m_list.Append(&data);
	m_size++;
}

/**************************************************************
*	  Purpose:  Remove top element of stack, return element.
*
*         Entry:  
*
*          Exit:	Assign m_capacity to supplied argument. Assign
*					m_size to current size of 0.
****************************************************************/
template <typename T>
T Stack<T>::Pop()
{
	if (m_size == 0)
		throw Exception("Underflow: There is no data in Stack to remove.");
	
	T outEl = m_list.popBack();

	m_size--;

	return outEl;

}


/**************************************************************
*	  Purpose:  Returns top element of stack
*
*         Entry:  
*
*          Exit:	Return the value in the top point of stack.
****************************************************************/
template <typename T>
const T Stack<T>::Peek()
{
	if (m_size == 0)
		throw Exception("Stack is empty, no values to evaluate");

	Node<T> lastNode = m_list.Last();

	T outEl = lastNode.getData();

	//T outEl = m_list.Last().getData();
	return outEl;
}


/**************************************************************
*	  Purpose:  Returns the number of items currently on stack
*
*         Entry:
*
*          Exit:	Return the value stored in m_size.
****************************************************************/
template <typename T>
int Stack<T>::Size()
{
	return m_size;
}


/**************************************************************
*	  Purpose:  Bool to return true if stack is empty.
*
*         Entry:
*
*          Exit:	Return true if stack is empty, false elsewise.
****************************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
	if (m_size == 0)
		return true;
	else
		return false;
}

/**************************************************************
*	  Purpose:  Returns true if stack is full
*
*         Entry:
*
*          Exit:	Return true if stack is full, false elsewise.
****************************************************************/
template <typename T>
bool Stack<T>::isFull()
{
	if (m_size == m_capacity)
		return true;
	else
		return false;
}