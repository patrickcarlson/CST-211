/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/18/2015
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

template <typename T>
Iterator<T>::Iterator(Node<T> *P)
{
	m_node = P;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
		m_node = m_node->getNext();

		return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++(int input)
{
	Iterator<T> temp(m_node);

	temp = *this;

	m_node = m_node->getNext();

	return temp;


}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	m_node = m_node->getPrev();
}

template <typename T>
Iterator<T>& Iterator<T>::operator--(int input)
{
	Iterator<T> tempIt;

	tempIt = *this;

	m_node = m_node->getPrev();

	return tempIt;
}

template <typename T>
T& Iterator<T>::operator*()
{
	T something = m_node->getData();
	
	return something;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& other)
{
	return m_node == other.m_node;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other)
{
	return m_node != other.m_node;
}

template <typename T>
Node<T>& Iterator<T>::getItNode()
{
	return *m_node;
}