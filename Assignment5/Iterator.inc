/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/24/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Iterator.inc
*
* Overview:
*	This is the .inc file for the Iterator class, which
*	is utilized to iterate through a doubly linked list.
*
* Input:
*	On construction it takes in a pointer to a Node.
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/

/**************************************************************
*	  Purpose:  Single argument constructor of Iterator class
*
*         Entry:  Creation of a new Iterator object with 1 argument
*
*          Exit:	Assign m_node member variable to argument
*					of P.
****************************************************************/
template <typename T>
Iterator<T>::Iterator(Node<T> *P)
{
	m_node = P;
}

/****************************************************************
*		Purpose: Post increment operator overload.
*
*			Entry:
*
*			 Exit: Moves iterators node value to next node
*****************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
		m_node = m_node->getNext();

		return *this;
}

/****************************************************************
*		Purpose: Pre increment operator overload.
*
*			Entry:
*
*			 Exit: Moves iterators node value to next node
*****************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator++(int input)
{
	Iterator<T> temp(m_node);

	temp = *this;

	m_node = m_node->getNext();

	return temp;


}

/****************************************************************
*		Purpose: Post decrement operator overload.
*
*			Entry:
*
*			 Exit: Moves iterators node value to previous node
*****************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	m_node = m_node->getPrev();
}

/****************************************************************
*		Purpose: pre decrement operator overload.
*
*			Entry: Dummy variable
*
*			 Exit: Moves iterators node value to previous node
*****************************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator--(int input)
{
	Iterator<T> tempIt;

	tempIt = *this;

	m_node = m_node->getPrev();

	return tempIt;
}

/****************************************************************
*		Purpose: Dereference operator overload
*
*			Entry:
*
*			 Exit: Returns values stored in currently iterated 
*					node.
*****************************************************************/
template <typename T>
T& Iterator<T>::operator*()
{
	T* something = &m_node->getData();
	
	return *something;
}

/****************************************************************
*		Purpose: Equality operator overload
*
*			Entry: Iterator object to be compared to
*
*			 Exit: returns true if iterators have same node
*****************************************************************/
template <typename T>
bool Iterator<T>::operator==(const Iterator& other)
{
	return m_node == other.m_node;
}

/****************************************************************
*		Purpose: Equality operator overload
*
*			Entry: Iterator object to be compared to
*
*			 Exit: returns true if iterators do not have same node
*****************************************************************/
template <typename T>
bool Iterator<T>::operator!=(const Iterator& other)
{
	return m_node != other.m_node;
}

/****************************************************************
*		Purpose: Inspector for member variable m_node
*
*			Entry: 
*
*			 Exit: Returns reference to node in iterator.
*****************************************************************/
template <typename T>
Node<T>& Iterator<T>::getItNode()
{
	return *m_node;
}