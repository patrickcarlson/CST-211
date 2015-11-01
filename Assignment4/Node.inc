/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/24/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Node.inc
*
* Overview:
*	This is the .inc file for the Node class. The node
*	class is utilized to store position and data information
*	for a doubley linked list. This file holds the 
*	member function definitions.
*
* Input:
*	On construction a Node takes data to store.
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the Node.
************************************************************/

/**************************************************************
*	  Purpose:  Single argument constructor of Node class
*
*         Entry:  Creation of a new Node object with 1 argument
*
*          Exit:	Assign m_data member variable to argument 
*					of data. Assign m_next and m_prev to nullptr
****************************************************************/
template <typename T>
Node<T>::Node(T& data)
	:m_data(data)
{
	m_next = nullptr;
	m_prev = nullptr;
}

/**************************************************************
*	  Purpose:  Member variable inspector for m_data
*
*         Entry:  
*
*          Exit:	Returns reference to data stored in member
*					variable m_data.
****************************************************************/
template <typename T>
T& Node<T>::getData()
{
	return m_data;
}

/**************************************************************
*	  Purpose:  Member variable mutator for m_data
*
*         Entry:	Single argument of templated data.
*
*          Exit:	Set m_data to data in argument
*
****************************************************************/
template <typename T>
void Node<T>::setData(T newData)
{
	m_data = newData;
}

/**************************************************************
*	  Purpose:  Member variable inspector for m_next
*
*         Entry:
*
*          Exit:	Returns data stored in member variable 
*					m_next.
****************************************************************/
template <typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

/**************************************************************
*	  Purpose:  Member variable inspector for m_prev
*
*         Entry:
*
*          Exit:	Returns  data stored in member variable
*					m_next.
****************************************************************/
template <typename T>
Node<T>* Node<T>::getPrev()
{
	return m_prev;
}

/**************************************************************
*	  Purpose:  Member variable mutator for m_next
*
*         Entry:	Single argument of pointer to Node of
*					templated data.
*
*          Exit:	Set m_next to input argument.
*
****************************************************************/
template <typename T>
void Node<T>::setNext(Node<T>* input)
{
	m_next = input;
}

/**************************************************************
*	  Purpose:  Member variable mutator for m_prev
*
*         Entry:	Single argument of pointer to Node of
*					templated data.
*
*          Exit:	Set m_prev to input argument.
*
****************************************************************/
template <typename T>
void Node<T>::setPrev(Node<T>* input)
{
	m_prev = input;
}